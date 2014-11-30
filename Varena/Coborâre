#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000;
const int Mmax = 300000;
const int MOD = 100003;

typedef struct
{
    int nod;
    int urm;

} lista;

lista G[Mmax + 1];
int head[Nmax + 1];

bool vis[Nmax + 1];
int postordine[Nmax + 1];
int sol[Nmax + 1];

int N, M, V, C;
int P;

void addEdge( int x, int y, int i )
{
    G[i].nod = y;
    G[i].urm = head[x];
    head[x] = i;
}

void DFS( int nod )
{
    vis[nod] = 1;

    int p = head[nod];

    while ( p )
    {
        int v = G[p].nod;

        if ( !vis[v] )
            DFS( v );

        p = G[p].urm;
    }

    postordine[ ++P ] = nod;
}

int main()
{
    FILE *f = fopen("coborare.in", "r");
    FILE *g = fopen("coborare.out", "w");

    fscanf(f, "%d%d%d%d", &N, &M, &V, &C);

    for ( int i = 1, a, b; i <= M; ++i )
    {
        fscanf(f, "%d%d", &a, &b);

        addEdge( a, b, i );
    }

    DFS( V );

    sol[C] = 1;

    for ( int i = 1; i <= N; ++i )
    {
        int nod = postordine[i];

        int p = head[nod];

        while ( p )
        {
            int v = G[p].nod;

            sol[nod] = ( sol[nod] + sol[v] ) % MOD;

            p = G[p].urm;
        }
    }

    fprintf(g, "%d\n", sol[V]);

    return 0;
}
