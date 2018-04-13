#include <bits/stdc++.h>

using namespace std;

const int Nmax = 9 + 1;
const int Mmax = 50000 + 1;
const int NIL = -1;

struct Edge
{
    int nod;
    int urm;
    int indice;
    int rev;
};

struct Node
{
    int nod;
    int indice;
    int rev;
};

struct Pair
{
    int a, b;
};

Edge G[2 * Mmax];
int head[Nmax];

int degree[Nmax];
int vis[Nmax];

Node stiva[Mmax + 1];
int top;

int sizeCycle;
Pair eulerPath[Mmax + 1];

int N, contor;

void addEdge(int x, int y, int ind, int rev)
{
    G[contor].nod = y;
    G[contor].urm = head[x];
    G[contor].indice = ind;
    G[contor].rev = rev;
    head[x] = contor;

    degree[x]++;

    contor++;
}

void dfs(int nod)
{
    vis[nod] = 1;

    for (int p = head[nod]; p != NIL; p = G[p].urm)
    {
        int son = G[p].nod;

        if ( !vis[son] )
            dfs(son);
    }
}

bool isEulerian()
{
    int nrComp = 0;

    for ( int i = 0; i <= 9; ++i )
        if ( degree[i] != 0 && !vis[i] )
        {
            nrComp++;
            dfs(i);
        }

    if ( nrComp > 1 )
        return false;

    int nr = 0;

    for ( int i = 0; i <= 9; ++i )
        if ( degree[i] % 2 )
            nr++;

    if ( nr > 2 )
        return false;

    return true;
}

int findRoot()
{
    for ( int i = 0; i <= 9; ++i )
        if ( degree[i] % 2 )
            return i;

    for ( int i = 0; i <= 9; ++i )
        if ( degree[i] )
            return i;

    return -1;
}

void euler(int nod)
{
    top = 1;
    stiva[1] = {nod, 0, 0};

    while (top)
    {
        nod = stiva[top].nod;

        while ( head[nod] != NIL && G[ head[nod] ].nod == NIL )
            head[nod] = G[ head[nod] ].urm;

        if ( head[nod] == NIL )
        {
            sizeCycle++;
            eulerPath[sizeCycle] = { stiva[top].indice, stiva[top].rev };
            top--;
        }
        else
        {
            stiva[ ++top ] = { G[ head[nod] ].nod, G[ head[nod] ].indice, G[ head[nod] ].rev };

            G[ head[nod] ^ 1 ].nod = NIL;
            head[nod] = G[ head[nod] ].urm;
        }
    }
}

int main()
{
    ifstream in("domino.in");
    ofstream out("domino.out");

    ios_base::sync_with_stdio(false);

    in >> N;

    for ( int i = 0; i <= 9; ++i )
        head[i] = NIL;

    for ( int i = 1; i <= N; ++i )
    {
        int a, b;
        in >> a >> b;

        addEdge(a, b, i, 0);
        addEdge(b, a, i, 1);
    }

    if ( isEulerian() == false )
        out << "0\n";
    else
    {
        out << "1\n";

        euler(findRoot());

        for ( int i = sizeCycle - 1; i >= 1; i-- )
            out << eulerPath[i].a << " " << eulerPath[i].b << "\n";
    }

    return 0;
}
