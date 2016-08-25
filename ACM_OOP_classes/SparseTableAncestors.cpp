#include <bits/stdc++.h>

using namespace std;

class SparseTableAncestors
{
private:

    vector< vector<int> > ancestor;
    vector< vector<int> > costMin;
    vector< vector<int> > costMax;
    vector<int> depth;
    int N;
    int MAX_LG;

public:

    SparseTableAncestors(int _N) : N(_N) {

        int LG2 = 2 + log2(_N);

        ancestor.resize(LG2);
        costMin.resize(LG2);
        costMax.resize(LG2);
        depth.resize(N + 1, 0);

        MAX_LG = LG2 - 1;

        for (int i = 0; i <= MAX_LG; ++i)
        {
            ancestor[i].resize(N + 1, -1);
            costMin[i].resize(N + 1, numeric_limits<int>::max());
            costMax[i].resize(N + 1, numeric_limits<int>::min());
        }
    }

    void setIndex(int node, int _ancestor, int _cost, int _depth)
    {
        ancestor[0][node] = _ancestor;
        costMin[0][node] = costMax[0][node] = _cost;
        depth[node] = _depth;
    }

    void build()
    {
        for (int i = 1; i <= MAX_LG; ++i)
            for (int j = 1; j <= N; ++j)
            {
                if (ancestor[i - 1][j] != -1)
                    ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];

                costMin[i][j] = costMin[i - 1][j];
                costMax[i][j] = costMax[i - 1][j];

                if (ancestor[i - 1][j] != -1)
                {
                    costMin[i][j] = min(costMin[i][j], costMin[i - 1][ancestor[i - 1][j]]);
                    costMax[i][j] = max(costMax[i][j], costMax[i - 1][ancestor[i - 1][j]]);
                }
            }
    }

    pair<int,int> query(int x, int y)
    {
        if (x == y)
            return {numeric_limits<int>::min(), numeric_limits<int>::max()};

        if (depth[x] < depth[y])
            swap(x, y);

        int keyMin = numeric_limits<int>::max();
        int keyMax = numeric_limits<int>::min();

        for (int k = MAX_LG; k >= 0; k--)
            if (ancestor[k][x] != -1 && depth[ ancestor[k][x] ] >= depth[y])
            {
                keyMin = min(keyMin, costMin[k][x]);
                keyMax = max(keyMax, costMax[k][x]);
                x = ancestor[k][x];
            }

        assert(depth[x] == depth[y]);

        if (x == y)
            return {keyMin, keyMax};

        for (int k = MAX_LG; k >= 0; k--)
            if (ancestor[k][x] != -1 && ancestor[k][y] != -1 && ancestor[k][x] != ancestor[k][y])
            {
                keyMin = min(keyMin, costMin[k][x]);
                keyMax = max(keyMax, costMax[k][x]);

                keyMin = min(keyMin, costMin[k][y]);
                keyMax = max(keyMax, costMax[k][y]);

                x = ancestor[k][x];
                y = ancestor[k][y];
            }

        assert(x != y);

        keyMin = min(keyMin, costMin[0][x]);
        keyMax = max(keyMax, costMax[0][x]);
        keyMin = min(keyMin, costMin[0][y]);
        keyMax = max(keyMax, costMax[0][y]);
        x = ancestor[0][x];
        y = ancestor[0][y];

        assert(x == y);

        return {keyMin, keyMax};
    }
};

int main()
{
    return 0;
}
