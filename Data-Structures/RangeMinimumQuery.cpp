#include <bits/stdc++.h>

using namespace std;

class RangeMinimumQuery
{
private:

    vector< vector<int> > rmq;
    vector<int> _log2;
    int N;

public:

    RangeMinimumQuery(int N)
    {
        this->N = N;
        rmq.resize(1 + ceil(log2(N)));

        for (size_t i = 0; i < rmq.size(); ++i)
            rmq[i].resize(N + 1);

        _log2.resize(N + 1);
    }

    void setIndex(int index, int key)
    {
        assert(1 <= index && index <= N);
        rmq[0][index] = key;
    }

    void build()
    {
        for (int i = 1; (1 << i) <= N; ++i)
            for (int j = 1; j + (1 << i) - 1 <= N; ++j)
            {
                int p = 1 << (i - 1);
                rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + p]);
            }

        _log2[1] = 0;

        for (int i = 2; i <= N; ++i)
            _log2[i] = _log2[i >> 1] + 1;
    }

    int query(int x, int y)
    {
        assert(1 <= x && x <= y && y <= N);

        int dif = y - x + 1;
        int k = _log2[dif];

        return min(rmq[k][x] , rmq[k][y - (1 << k) + 1]);
    }
};

int main()
{
}
