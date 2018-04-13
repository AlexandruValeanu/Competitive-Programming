#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000 + 1;
const int Mmax = 5000 + 1;
const int NIL = -1;
const int INF = numeric_limits<int>::max();

struct Edge
{
    int nod;
    int flow;
    int capacity;

    int urm;
};

Edge G[2 * Mmax];
int head[Nmax];

int coada[Nmax];
int tata[Nmax];
int pointer[Nmax];

int visited[Nmax];

int N, M, contor;

void addEdge(int x, int y, int c)
{
    G[contor].nod = y;
    G[contor].flow = 0;
    G[contor].capacity = c;
    G[contor].urm = head[x];

    head[x] = contor;
    contor++;
}

bool BFS(int S, int T)
{
    for ( int i = 1; i <= N; ++i )
        tata[i] = 0;

    tata[S] = S;

    int st = 1, dr = 1;
    coada[1] = S;

    while (st <= dr)
    {
        int nod = coada[st++];

        for ( int p = head[nod]; p != NIL; p = G[p].urm )
        {
            int son = G[p].nod;

            if (tata[son] == 0 && G[p].flow < G[p].capacity)
            {
                tata[son] = nod;
                pointer[son] = p;
                coada[++dr] = son;

                if ( son == T )
                    return true;
            }
        }
    }

    return false;
}

int Edmonds_Karp(int S, int T)
{
    int flow = 0, fmin, nod;

    while ( BFS(S, T) )
    {
        fmin = INF;
        nod = T;

        while (nod != S)
        {
            fmin = min(fmin, G[ pointer[nod] ].capacity - G[ pointer[nod] ].flow);
            nod = tata[nod];
        }

        nod = T;

        while (nod != S)
        {
            G[ pointer[nod] ].flow += fmin;
            G[ pointer[nod] ^ 1 ].flow -= fmin;
            nod = tata[nod];
        }

        flow += fmin;
    }

    return flow;
}

int main()
{
    scanf("%d %d", &N, &M);

    for ( int i = 1; i <= N; ++i )
        head[i] = NIL;

    for ( int i = 1; i <= M; ++i )
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        addEdge(a, b, c);
        addEdge(b, a, 0);
    }

    printf("%d\n", Edmonds_Karp(1, N));

    return 0;
}
