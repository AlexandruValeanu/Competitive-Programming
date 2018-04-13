#include <bits/stdc++.h>

using namespace std;

const int Nmax = 200000 + 1;
const int Mmax = 400000 + 1;
const int INF = numeric_limits<int>::max();

struct Edge
{
    int x;
    int y;
    int cost;

    bool operator < (const Edge& A) const
    {
        return cost < A.cost;
    }
};

Edge E[Mmax];
bool usedEdge[Mmax];

int Father[Nmax];
int Rank[Nmax];

int N, M;

void initDSU()
{
    for (int i = 1; i <= N; ++i)
    {
        Father[i] = i;
        Rank[i] = 1;
    }
}

int Find(int x)
{
    int R = x;

    while (R != Father[R])
        R = Father[R];

    while (x != Father[x])
    {
        int aux = Father[x];
        Father[x] = R;
        x = aux;
    }

    return R;
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y)
        return false;

    if (Rank[y] > Rank[x])
        swap(x, y);

    Father[y] = x;

    if (Rank[x] == Rank[y])
        Rank[x]++;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for ( int i = 1; i <= M; ++i )
    {
        int a, b, c;
        cin >> a >> b >> c;

        E[i] = {a, b, c};
    }

    sort(E + 1, E + M + 1);

    initDSU();

    int costAPM = 0;

    for (int i = 1; i <= M; ++i)
    {
        if (Union(E[i].x, E[i].y))
        {
            costAPM += E[i].cost;
            usedEdge[i] = true;
        }
    }

    cout << costAPM << "\n";
    cout << N - 1 << "\n";

    for (int i = 1; i <= M; ++i)
        if ( usedEdge[i] )
            cout << E[i].x << " " << E[i].y << "\n";

    return 0;
}
