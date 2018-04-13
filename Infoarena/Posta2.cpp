#include <iostream>
#include <fstream>

using namespace std;

const int Nmax = 100000 + 1;

struct Edge
{
    int nod;
    int cost;
    int urm;
};

Edge G[2 * Nmax];
int head[Nmax];
int contor;

int size[Nmax];
bool deleted[Nmax];
bool special[Nmax];
int costNode[Nmax];
int nrPassed[Nmax];

long long costPath;
long long sumEdges;

int N, M;

void addEdge(int x, int y, int c)
{
    contor++;
    G[contor].nod = y;
    G[contor].cost = c;
    G[contor].urm = head[x];
    head[x] = contor;
}

void dfs(int nod, int tata)
{
    if ( special[nod] )
        size[nod] = 1;

    for ( int p = head[nod]; p != 0; p = G[p].urm )
    {
        int fiu = G[p].nod;

        if ( fiu != tata )
        {
            dfs(fiu, nod);
            size[nod] += size[fiu];
        }
    }

    if ( size[nod] == 0 )
        deleted[nod] = true;
}

void DFS(int nod, int tata)
{
    for ( int p = head[nod]; p != 0; p = G[p].urm )
    {
        int fiu = G[p].nod;

        if ( fiu != tata && deleted[fiu] == false )
        {
            costPath += 2LL * G[p].cost;
            DFS(fiu, nod);
        }
    }
}

int main()
{
    ifstream in("posta2.in");
    ofstream out("posta2.out");

    ios_base::sync_with_stdio(false);

    in >> N >> M;

    for ( int i = 1; i < N; ++i )
    {
        int a, b, c;
        in >> a >> b >> c;

        addEdge(a, b, c);
        addEdge(b, a, c);
    }

    for ( int i = 1; i <= N; ++i )
        in >> costNode[i];

    for ( int i = 1; i <= M; ++i )
    {
        int a;
        in >> a;
        special[a] = true;
    }

    int root = 0;

    ///reduce graf
    for ( int i = 1; i <= N; ++i )
        if ( special[i] == true )
        {
            root = i;
            i = N + 1;
        }

    ///assert(root != 0);
    dfs(root, 0);
    DFS(root, 0);

    long long best = -(1LL << 60);

    for ( int i = 1; i <= N; ++i )
        if ( deleted[i] == false )
        {
            int nrNeigh = 0;

            for ( int p = head[i]; p != 0; p = G[p].urm )
            {
                int fiu = G[p].nod;

                if ( deleted[fiu] == false )
                    nrNeigh++;
            }

            costPath += 1LL * (nrNeigh - 1) * costNode[i];

            if ( best < 1LL * (nrNeigh - 1) * costNode[i] )
                best = 1LL * (nrNeigh - 1) * costNode[i];
        }

    out << costPath - best << "\n";

    return 0;
}
