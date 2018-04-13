#include <bits/stdc++.h>

using namespace std;

const int Nmax = 150 + 1;
const int Mmax = 5000 + 1;
const int INF = 1e9;

struct Edge
{
    int nod;
    int urm;
};

struct Muchie
{
    int x;
    int y;
};

Muchie E[Mmax];
Edge G[2 * Mmax];
int contor;
int head[Nmax];

int coada[Nmax];
int D[Nmax][Nmax];

int N, M;

void addEdge(int x, int y)
{
    contor++;
    G[contor].nod = y;
    G[contor].urm = head[x];
    head[x] = contor;
}

void BFS(int nod, int dist[])
{
    for ( int i = 1; i <= N; ++i )
        dist[i] = INF;

    dist[nod] = 0;

    int st, dr;
    coada[ st = dr = 1 ] = nod;

    while (st <= dr)
    {
        nod = coada[st++];

        for ( int p = head[nod]; p != 0; p = G[p].urm )
        {
            int fiu = G[p].nod;

            if ( dist[fiu] > dist[nod] + 1 )
            {
                dist[fiu] = dist[nod] + 1;
                coada[++dr] = fiu;
            }
        }
    }
}

int main()
{
    ifstream in("apdm.in");
    ofstream out("apdm.out");

    ios_base::sync_with_stdio(false);

    in >> N >> M;

    for ( int i = 1; i <= M; ++i )
    {
        int a, b;
        in >> a >> b;

        addEdge(a, b);
        addEdge(b, a);

        E[i].x = a;
        E[i].y = b;
    }

    for ( int i = 1; i <= N; ++i )
        BFS(i, D[i]);

    int best = INF;

    for ( int i = 1; i <= N; ++i )
    {
        int x1 = 0, d = 0, diameter = 0;

        for ( int j = 1; j <= N; ++j )
        {
            if ( d < D[i][j] )
            {
                d = D[i][j];
                x1 = j;
            }
        }

        diameter += d;
        d = 0;

        for ( int j = 1; j <= N; ++j )
        {
            if ( j != x1 && d < D[i][j] )
            {
                d = D[i][j];
            }
        }

        diameter += d;

        best = min(best, diameter);
    }

    for ( int i = 1; i <= M; ++i )
    {
        int a = E[i].x;
        int b = E[i].y;

        if ( D[a][b] == 1 )
        {
            int sol = 0;

            for ( int j = 1; j <= N; ++j )
                sol = max(sol, min(D[a][j], D[b][j]));

            best = min(best, 2 * sol + 1);
        }
    }

    out << best << "\n";

    return 0;
}
