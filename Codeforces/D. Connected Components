#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
public:

    explicit UnionFind(){
    }

    UnionFind(const int n) : Parent(vector<int>(n + 1)), Rank(vector<int>(n + 1)), Size(vector<int>(n + 1)) {

        nrComp = n;

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
            }

            if (Rank[x] == Rank[y])
                Rank[y]++;

            nrComp--;
        }
    }

    bool connected(int x, int y)
    {
        return Find(x) == Find(y);
    }

    int nrComp;

private:

    vector<int> Parent;
    vector<int> Rank;
    vector<int> Size;
};

const int Nmax = 500 + 2;
const int Mmax = 10000 + 2;

int L[Mmax], R[Mmax];
UnionFind Prefix[Mmax], Suffix[Mmax];

int N, M, K;

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    Prefix[0] = UnionFind(N);

    for (int i = 1; i <= M; ++i)
        cin >> L[i] >> R[i];

    for (int i = 1; i <= M; ++i)
    {
        Prefix[i] = Prefix[i - 1];
        Prefix[i].Union(L[i], R[i]);
    }

    Suffix[M + 1] = UnionFind(N);

    for (int i = M; i >= 1; --i)
    {
        Suffix[i] = Suffix[i + 1];
        Suffix[i].Union(L[i], R[i]);
    }

    cin >> K;

    while (K--)
    {
        int x, y;
        cin >> x >> y;

        UnionFind tmp = Prefix[x - 1];

        for (int i = 1; i <= N; ++i)
            tmp.Union(i, Suffix[y + 1].Find(i));

        cout << tmp.nrComp << "\n";
    }

    return 0;
}
