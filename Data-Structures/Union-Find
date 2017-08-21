#include <bits/stdc++.h>

using namespace std;

class UnionFind{
public:
    UnionFind(const int n) : Parent(vector<int>(n + 1)), Rank(vector<int>(n + 1)), Size(vector<int>(n + 1)) {
        for (int i = 1; i <= n; ++i)
            MakeSet(i);
    }

    void MakeSet(int x)
    {
        Parent[x] = x;
        Rank[x] = 0;
        Size[x] = 1;
    }

    int Find(int x)
    {
        if (Parent[x] != x)
            Parent[x] = Find(Parent[x]);

        return Parent[x];
    }

    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);

        if (x != y)
        {
            /// append y to x
            if (Rank[x] > Rank[y])
            {
                Parent[y] = x;
                Size[x] += Size[y];
            }
            else /// append x to y
            {
                Parent[x] = y;
                Size[y] += Size[x];

                if (Rank[x] == Rank[y])
                  Rank[y]++;
            }
        }
    }

    bool connected(int x, int y)
    {
        return Find(x) == Find(y);
    }

    int getSize(int x){
      return Size[Find(x)];
    }

private:

    vector<int> Parent;
    vector<int> Rank;
    vector<int> Size;
};

int main()
{
    return 0;
}
