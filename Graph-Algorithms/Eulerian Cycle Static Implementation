#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;
const int Mmax = 500000 + 1;
const int NIL = -1;

struct Edge
{
    int nod;
    int urm;
};

Edge G[2 * Mmax];
int head[Nmax];

bool vis[Nmax];
int degree[Nmax];
int stiva[Mmax + 1], top;

int eulerPath[Mmax + 1];
int sizeCycle;

int N, M, contor;

void addEdge(int x, int y)
{
    G[contor].nod = y;
    G[contor].urm = head[x];
    head[x] = contor;
    degree[x]++;
    contor++;
}

void dfs(int nod)
{
    vis[nod] = 1;

    for ( int p = head[nod]; p != NIL; p = G[p].urm)
    {
        int son = G[p].nod;

        if ( !vis[son] )
            dfs(son);
    }
}

void euler(int nod)
{
    stiva[ top = 1 ] = nod;

    while (top)
    {
        nod = stiva[top];

        while ( head[nod] != NIL && G[ head[nod] ].nod == NIL )
            head[nod] = G[ head[nod] ].urm;

        if ( head[nod] == NIL )
        {
            eulerPath[ sizeCycle++ ] = nod;
            top--;
        }
        else
        {
            stiva[ ++top ] = G[ head[nod] ].nod;
            G[ head[nod] ^ 1 ].nod = NIL;
            head[nod] = G[ head[nod] ].urm;
        }
    }
}

bool checkIfEuler()
{
    int nrComp = 0;

    for ( int i = 1; i <= N; ++i )
        if ( !vis[i] )
        {
            nrComp++;
            dfs(i);
        }

    int nrOdd = 0;

    for ( int i = 1; i <= N; ++i )
        if ( degree[i] % 2 == 1 )
            nrOdd++;

    if ( nrComp > 1 || nrOdd > 0 )
        return false;
    else
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for ( int i = 1; i <= N; ++i )
        head[i] = NIL;

    for ( int i = 1; i <= M; ++i )
    {
        int a, b;
        cin >> a >> b;

        addEdge(a, b);
        addEdge(b, a);
    }

    if ( checkIfEuler() == false )
        cout << "-1\n";
    else
    {
        euler(1);

        for ( int i = 0; i < sizeCycle - 1; ++i )
            cout << eulerPath[i] << " ";

        cout << "\n";
    }

    return 0;
}
