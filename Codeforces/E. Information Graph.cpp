#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
public:

    explicit UnionFind(){
    }

    UnionFind(const int n) : Parent(vector<int>(n + 1)), Rank(vector<int>(n + 1)), Size(vector<int>(n + 1)) {

        nrComponents = n;

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

            nrComponents--;
        }
    }

    bool connected(int x, int y)
    {
        return Find(x) == Find(y);
    }

    int sizeComponent(int x)
    {
        return Size[Find(x)];
    }

    int nrComponents;

private:

    vector<int> Parent;
    vector<int> Rank;
    vector<int> Size;
};

const int Nmax = 1e5 + 1;

struct Query
{
    int tip;
    int x, y;

} Q[Nmax];

vector<int> G[Nmax];
vector<int> documents[Nmax];
int tata[Nmax];
int solution[Nmax];
int in[Nmax], out[Nmax];

int N, M;
int timer;

void dfs(int nod)
{
    in[nod] = ++timer;

    for (auto x: G[nod])
        dfs(x);

    out[nod] = ++timer;
}

int ancestor(int u, int v)
{
    return (in[v] <= in[u] && out[u] <= out[v]);
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= M; ++i)
    {
        cin >> Q[i].tip;

        if (Q[i].tip == 1)
        {
            cin >> Q[i].x >> Q[i].y;
            tata[ Q[i].x ] = Q[i].y;
            G[ Q[i].y ].push_back(Q[i].x);
        }

        if (Q[i].tip == 2)
        {
            cin >> Q[i].x;
        }

        if (Q[i].tip == 3)
        {
            cin >> Q[i].x >> Q[i].y;
            documents[ Q[i].y ].push_back(i);
        }
    }

    for (int i = 1; i <= N; ++i)
        if (!tata[i])
            dfs(i);

    UnionFind UF(N);

    int nrQ = 0;

    for (int i = 1; i <= M; ++i)
    {
        if (Q[i].tip == 1)
        {
            UF.Union(Q[i].x, Q[i].y);
            continue;
        }

        if (Q[i].tip == 3)
        {
            if (solution[i])
                cout << "YES\n";
            else
                cout << "NO\n";

            continue;
        }

        nrQ++;

        for (int id: documents[nrQ])
        {
            int x = Q[i].x;
            int y = Q[id].x;

            if (UF.connected(x, y) && ancestor(x, y))
                solution[id] = 1;
        }
    }

    return 0;
}
