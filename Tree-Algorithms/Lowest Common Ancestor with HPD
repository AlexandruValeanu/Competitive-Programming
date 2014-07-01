#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int Nmax = 1e5 + 2;

vector <int> G[Nmax];
int father[Nmax], depth[Nmax];
int size[Nmax], path[Nmax], lengthPath[Nmax], pos_in_path[Nmax], start_node[Nmax];

int N, Q, nrPaths;

void DFS( int node )
{
    int heavySon = 0;
    size[node] = 1;

    for ( auto x: G[node] )
    {
        father[x] = node;
        depth[x] = depth[node] + 1;
        DFS( x );

        size[node] += size[x];

        if ( size[heavySon] < size[x] )
            heavySon = x;
    }

    if ( heavySon == 0 )
        path[node] = nrPaths++;
    else
        path[node] = path[heavySon];

    pos_in_path[node] = lengthPath[ path[node] ]++;
}

void build_heavy_path()
{
    father[1] = 1;
    depth[1] = 0;

    DFS( 1 );

    for ( int i = 1; i <= N; ++i )
    {
        pos_in_path[i] = lengthPath[ path[i] ] - pos_in_path[i] - 1;

        if ( pos_in_path[i] == 0 )
            start_node[ path[i] ] = i;
    }
}

int lca( int x, int y )
{
    while ( path[x] != path[y] )
    {
        if ( depth[ start_node[ path[x] ] ] < depth[ start_node[ path[y] ] ] )
            y = father[ start_node[ path[y] ] ];
        else
            x = father[ start_node[ path[x] ] ];
    }

    return pos_in_path[x] < pos_in_path[y] ? x : y;
}

int main()
{
    cin >> N >> Q;

    for ( int i = 2, a; i <= N; ++i )
    {
        cin >> a;

        G[a].push_back( i );
    }

    build_heavy_path();

    while ( Q-- )
    {
        int a, b;

        cin >> a >> b;
        cout << lca( a, b ) << "\n";
    }

    return 0;
}
