#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int Nmax = 1e5 + 2;

vector <int> G[Nmax];
int path[Nmax], father[Nmax];
int depth[Nmax];
int N, Q, sqrtN;

void DFS( int node, int P )
{
    path[node] = P;

    if ( depth[node] % sqrtN == 0 )
        P = node;

    for ( auto x: G[node] )
    {
        depth[x] = depth[node] + 1;
        DFS( x, P );
    }
}

int lca( int x, int y )
{
    while ( path[x] != path[y] )
    {
        if ( depth[x] < depth[y] )
            y = path[y];
        else
            x = path[x];
    }

    while ( x != y )
    {
        if ( depth[x] < depth[y] )
            y = father[y];
        else
            x = father[x];
    }

    return x;
}

int main()
{
    cin.sync_with_stdio( false );

    cin >> N >> Q;

    for ( sqrtN = 1; sqrtN * sqrtN <= N; sqrtN++ );

    for ( int i = 2, a; i <= N; ++i )
    {
        cin >> a;

        G[a].push_back( i );
        father[i] = a;
    }

    DFS( 1, 1 );

    while ( Q-- )
    {
        int a, b;

        cin >> a >> b;
        cout << lca( a, b ) << "\n";
    }

    return 0;
}
