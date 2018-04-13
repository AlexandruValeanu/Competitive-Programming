#include <bits/stdc++.h>

using namespace std;

const int Vmax = 100000 + 1;
const int Emax = 200000 + 1;

struct Graph
{
    struct Node
    {
        int nod;
        int next;
    };

    Node listEdges[Emax];
    int head[Vmax];
    int contor;

    Graph()
    {
        contor = 0;

        for ( int i = 0; i < Vmax; ++i )
            head[i] = 0;
    }

    void addEdge( int a, int b )
    {
        contor++;
        listEdges[contor].nod = b;
        listEdges[contor].next = head[a];
        head[a] = contor;
    }
};

Graph G, GT;
bool visited[Vmax];
int postOrder[Vmax];
int nrSCC[Vmax];

int N, M, P;

Graph SCC;
int numberOfSCC;

void DFS(int nod)
{
    visited[nod] = true;

    for ( int p = G.head[nod]; p != 0; p = G.listEdges[p].next )
    {
        int v = G.listEdges[p].nod;

        if ( visited[v] == false )
            DFS(v);
    }

    postOrder[ ++P ] = nod;
}

void DFST(int nod)
{
    visited[nod] = false;

    for ( int p = GT.head[nod]; p != 0; p = GT.listEdges[p].next )
    {
        int v = GT.listEdges[p].nod;

        if ( visited[v] == true )
            DFST(v);
    }

    nrSCC[nod] = numberOfSCC;
    SCC.addEdge(numberOfSCC, nod);
}

void Kosaraju()
{
    for ( int i = 1; i <= N; ++i )
        if ( visited[i] == false )
            DFS(i);

    for ( int i = N; i >= 1; --i )
    {
        int nod = postOrder[i];

        if ( visited[nod] == true )
        {
            numberOfSCC++;
            DFST(nod);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio( false );

    cin >> N >> M;

    for ( int i = 1; i <= M; ++i )
    {
        int a, b;
        cin >> a >> b;

        G.addEdge(a, b);
        GT.addEdge(b, a);
    }

    Kosaraju();

    cout << numberOfSCC << "\n";

    for ( int i = 1; i <= numberOfSCC; ++i )
    {
        for ( int p = SCC.head[i]; p != 0; p = SCC.listEdges[p].next )
            cout << SCC.listEdges[p].nod << " ";

        cout << "\n";
    }

    return 0;
}
