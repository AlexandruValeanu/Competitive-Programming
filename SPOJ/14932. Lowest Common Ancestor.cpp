#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int Nmax = 1e3 + 2;

vector <int> G[Nmax];
int father[Nmax], depth[Nmax];
int size[Nmax], path[Nmax], lengthPath[Nmax], pos_in_path[Nmax], start_node[Nmax];
int vis[Nmax];

int N, Q, nrPaths;

void DFS( int node )
{
    int heavySon = 0;
    size[node] = 1;

    for ( int i = 0; i < G[node].size(); ++i )
    {
        int x = G[node][i];

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
    int root = -1;

    for ( int i = 1; i <= N; ++i )
    {
        if ( vis[i] == 0 )
            root = i;
    }

    father[root] = root;
    depth[root] = 0;

    DFS( root );

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

void reset()
{
    for ( int i = 1; i <= N; ++i )
        G[i].clear();

    fill( path + 1, path + N + 1, 0 );
    fill( pos_in_path + 1, pos_in_path + N + 1, 0 );
    fill( father + 1, father + N + 1, 0 );
    fill( size + 1, size + N + 1, 0 );
    fill( vis + 1, vis + N + 1, 0 );
    fill( lengthPath, lengthPath + N + 1, 0 );
}

int main()
{
    ///ifstream cin("data.in");

    int t;

    cin.sync_with_stdio( false );

    cin >> t;

    for ( int k = 1; k <= t; ++k )
    {
        cin >> N;

        for ( int i = 1, nr, a; i <= N; ++i )
        {
            cin >> nr;

            while ( nr-- )
            {
                cin >> a;
                G[i].push_back( a );
                vis[a] = 1;
            }
        }

        build_heavy_path();

        cin >> Q;

        cout << "Case " << k << ":\n";

        while ( Q-- )
        {
            int a, b;

            cin >> a >> b;
            cout << lca( a, b ) << "\n";
        }

        reset();
    }

    return 0;
}
