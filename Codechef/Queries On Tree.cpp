#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class SegmentTree
{
public:

    SegmentTree( const int n, const vector<int> &values )
    {
        N = n;
        T = vector<int>( 4 * N );
        build( 1, 0, N - 1, values );
    }

    void update( int pos, int value )
    {
        update( 1, 0, N - 1, pos, value );
    }

    int query( int st, int dr )
    {
        return query( 1, 0, N - 1, st, dr );
    }

private:

    vector <int> T;
    int N;

    void build( int node, int st, int dr, const vector<int> &values )
    {
        if ( st == dr )
        {
            T[node] = values[st];
        }
        else
        {
            int m = ( st + dr ) / 2;

            build( 2 * node, st, m, values );
            build( 2 * node + 1, m + 1, dr, values );

            T[node] = ( T[2 * node] + T[2 * node + 1] );
        }
    }

    void update( int node, int st, int dr, int pos, int val )
    {
        if ( st == dr )
        {
            T[node] = val;
        }
        else
        {
            int m = ( st + dr ) / 2;

            if ( pos <= m ) update( 2 * node, st, m, pos, val );
            else            update( 2 * node + 1, m + 1, dr, pos, val );

            T[node] = ( T[2 * node] + T[2 * node + 1] );
        }
    }

    int query( int node, int st, int dr, int st_q, int dr_q )
    {
        if ( st_q <= st && dr <= dr_q )
        {
            return T[node];
        }
        else
        {
            int m = ( st + dr ) / 2;
            int val = 0;

            if ( st_q <= m )
                val += query( 2 * node, st, m, st_q, dr_q );

            if ( m  < dr_q )
                val += query( 2 * node + 1, m + 1, dr, st_q, dr_q );

            return val;
        }
    }
};

const int Nmax = 1e5 + 2;

vector <SegmentTree> ST;
vector < pair<int,int> > G[Nmax];
int size[Nmax], path[Nmax], pos_in_path[Nmax], path_length[Nmax], start_node[Nmax];
int depth[Nmax], father[Nmax], valueNode[Nmax];

pair<int,int> edge[Nmax];

int N, nrPaths, Q;

void DFS( int node )
{
    int heavySon = 0;
    size[node] = 1;

    for ( auto y: G[node] )
    {
        int x = y.first;
        int cost = y.second;

        if ( father[x] == 0 )
        {
            depth[x] = depth[node] + 1;
            father[x] = node;
            valueNode[x] = cost;

            DFS( x );

            size[node] += size[x];

            if ( size[x] > size[heavySon] )
                heavySon = x;
        }
    }

    if ( heavySon == 0 )
        path[node] = nrPaths++;
    else
        path[node] = path[heavySon];

    pos_in_path[node] = path_length[ path[node] ]++;
}

void build_heavy_path()
{
    father[1] = 1;
    depth[1] = 0;
    valueNode[1] = 0;

    DFS( 1 );

    for ( int i = 1; i <= N; ++i )
    {
        pos_in_path[i] = path_length[ path[i] ] - pos_in_path[i] - 1;

        if ( pos_in_path[i] == 0 )
            start_node[ path[i] ] = i;
    }
}

void build_segment_trees()
{
    vector<vector<int>> pathValues = vector < vector<int> >( nrPaths );

    for ( int i = 0; i < nrPaths; ++i )
        pathValues[i] = vector<int>( path_length[i] );

    for ( int i = 1; i <= N; ++i )
        pathValues[ path[i] ][ pos_in_path[i] ] = valueNode[i];

    for ( int i = 0; i < nrPaths; ++i )
        ST.push_back( SegmentTree( pathValues[i].size(), pathValues[i] ) );
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

void update( int node, int value )
{
    valueNode[node] = value;

    ST[ path[node] ].update( pos_in_path[node], value );
}

int query( int x, int y )
{
    if ( depth[ start_node[ path[x] ] ] < depth[ start_node[ path[y] ] ] )
        swap( x, y );

    if ( path[x] == path[y] )
        return ST[ path[x] ].query( min( pos_in_path[x], pos_in_path[y] ), max( pos_in_path[x], pos_in_path[y] ) );
    else
        return ST[ path[x] ].query( 0, pos_in_path[x] ) + query( father[ start_node[ path[x] ] ], y );
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio( false );

    cin >> N;

    for ( int i = 1, a, b, c; i < N; ++i )
    {
        cin >> a >> b >> c;

        edge[i].first = a;
        edge[i].second = b;

        G[a].push_back( pair<int,int>( b, c ) );
        G[b].push_back( pair<int,int>( a, c ) );
    }

    build_heavy_path();
    build_segment_trees();

    cin >> Q;

    for ( int i = 1, tip, a, b; i <= Q; ++i )
    {
        cin >> tip >> a >> b;

        if ( tip == 1 )
        {
            if ( father[ edge[a].first ] == edge[a].second )
                update( edge[a].first, b );
            else
                update( edge[a].second, b );
        }
        else
        {
            cout << query( a, b ) - valueNode[ lca( a, b ) ] << "\n";
        }
    }

    return 0;
}
