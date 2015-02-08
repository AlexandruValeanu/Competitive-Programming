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

    Node listEdges[2 * Emax];
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

struct Edge
{
    int x, y;
};

struct Node
{
    int nod;
    Node* next;
};

int numberOfSCC;
Node *graphSCC[Vmax];

void add(int nod, int neigh)
{
    Node *aux = new Node;
    aux->nod = neigh;
    aux->next = graphSCC[nod];
    graphSCC[nod] = aux;
}

Graph G;
bool visited[Vmax];
Edge StackEdges[Emax];

int lowLink[Vmax];
int Index[Vmax];
int cut_point[Vmax];

int N, M, top, I;

int arr[Vmax], n;

void create_component(int nod, int son)
{
    numberOfSCC++;
    Edge E;

    do
    {
        E = StackEdges[ top-- ];
        add(numberOfSCC, E.x);
        add(numberOfSCC, E.y);

    } while ( nod != E.x || son != E.y );
}

void DFS(int nod, int father)
{
    visited[nod] = true;
    Index[nod] = lowLink[nod] = ++I;

    int nrSons = 0;
    bool cutPoint = false;

    for ( int p = G.head[nod]; p != 0; p = G.listEdges[p].next )
    {
        int son = G.listEdges[p].nod;

        if ( visited[son] == false )
        {
            nrSons++;
            StackEdges[ ++top ] = {nod, son};
            DFS(son, nod);
            lowLink[nod] = min(lowLink[nod], lowLink[son]);

            if ( lowLink[son] >= Index[nod] ) /// is cutPoint + new component
            {
                cutPoint = true;
                create_component(nod, son);
            }

            if ( lowLink[son] > Index[nod] ) /// is bridge (nod, son)
            {
                ///...///
            }
        }
        else
            lowLink[nod] = min(lowLink[nod], Index[son]);
    }

    if ( father == 0 ) /// is root
        if ( nrSons >= 2 )
            cutPoint = true;

    cut_point[nod] = cutPoint;
}

void Tarjan()
{
    for ( int i = 1; i <= N; ++i )
        if ( visited[i] == false )
            DFS(i, 0);
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
        G.addEdge(b, a);
    }

    Tarjan();

    cout << numberOfSCC << "\n";

    for ( int i = 1; i <= numberOfSCC; ++i )
    {
        int n = 0;

        for ( Node* p = graphSCC[i]; p != NULL; p = p->next )
            arr[ ++n ] = p->nod;

        sort(arr + 1, arr + n + 1);

        int last = 0;

        for ( int j = 1; j <= n; ++j )
        {
            if ( last != arr[j] )
                cout << arr[j] << " ";

            last = arr[j];
        }

        cout << "\n";
    }

    return 0;
}
