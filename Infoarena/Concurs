#include <bits/stdc++.h>

using namespace std;

const int Nmax = 32e3 + 1;
const int Mmax = 5e5 + 1;

vector <int> G[Nmax];
int father[Nmax], size[Nmax], depth[Nmax], vis[Nmax], value[Nmax];
int start_node[Nmax], pos_in_path[Nmax], length_path[Nmax], path[Nmax];

int N, M, NumberPaths;

void DFS( int node )
{
    int hson = 0;
    size[node] = 1;

    for ( auto x: G[node] )
    {
        if ( father[x] == 0 )
        {
            father[x] = node;
            depth[x] = depth[node] + 1;

            DFS( x );

            size[node] += size[x];

            if ( size[x] > size[hson] )
                hson = x;
        }
    }

    if ( hson == 0 )
        path[node] = NumberPaths++;
    else
        path[node] = path[hson];

    pos_in_path[node] = length_path[ path[node] ]++;
}

void build_hpd()
{
    int root = 0;

    for ( int i = 1; i <= N; ++i )
        if ( !vis[i] )
            root = i;

    father[root] = root;
    depth[root] = 0;
    DFS( root );

    for ( int i = 1; i <= N; ++i )
    {
        pos_in_path[i] = length_path[ path[i] ] - pos_in_path[i] - 1;

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
    ifstream in("concurs.in");
    ofstream out("concurs.out");

    in.sync_with_stdio( false );

    in >> N >> M;

    for ( int i = 1; i <= N; ++i )
        in >> value[i];

    for ( int i = 1, a, b; i < N; ++i )
    {
        in >> a >> b;

        G[a].push_back( b );
        vis[b] = 1;
    }

    build_hpd();

    int minx = 1e9, miny = 1e9, ans = -1e9;

    for ( int i = 1, x, y; i <= M; ++i )
    {
        in >> x >> y;

        int L = lca( x, y );

        if ( value[L] > ans )
        {
            ans = value[L];
            minx = x;
            miny = y;
        }
        else
        {
            if ( value[L] == ans )
            {
                if ( x < minx )
                {
                    minx = x;
                    miny = y;
                }
                else
                {
                    if ( x == minx )
                    {
                        if ( y < miny )
                            miny = y;
                    }
                }
            }
        }
    }

    out << ans << " " << minx << " " << miny << "\n";

    return 0;
}
