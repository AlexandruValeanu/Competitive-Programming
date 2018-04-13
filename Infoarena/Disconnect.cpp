#include <bits/stdc++.h>

using namespace std;

///---------------------------------------------

const int BS = ( 1 << 16 );
char buffer[BS];
int position = BS;

inline char getChar()
{
    if ( position == BS )
    {
        fread( buffer, BS, 1, stdin );
        position = 0;
    }

    return buffer[ position++ ];
}

inline int getNr()
{
    char ch;
    int a = 0;

    do
    {
        ch = getChar();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getChar();

    } while ( isdigit( ch ) );

    return a;
}

class SegmentTree
{
public:

    int N;
    vector<int> A;

    SegmentTree( vector<int> &v )
    {
        N = v.size();
        A = vector<int>( 4 * N );

        build( 1, 0, N - 1, v );
    }

    void build( int nod, int st, int dr, vector<int> &v )
    {
        if ( st == dr )
            A[nod] = v[st];
        else
        {
            int m = ( st + dr ) / 2;

            build( 2 * nod, st, m, v );
            build( 2 * nod + 1, m + 1, dr, v );

            A[nod] = A[2 * nod] + A[2 * nod + 1];
        }
    }

    void update( int x, int y )
    {
        update( 1, 0, N - 1, x, y );
    }

    void update( int nod, int st, int dr, int p, int val )
    {
        if ( st == dr )
            A[nod] = val;
        else
        {
            int m = ( st + dr ) / 2;

            if ( p <= m )
                update( 2 * nod, st, m, p, val );
            else
                update( 2 * nod + 1, m + 1, dr, p, val );

            A[nod] = A[2 * nod] + A[2 * nod + 1];
        }
    }

    int query( int x, int y )
    {
        return query( 1, 0, N - 1, x, y );
    }

    int query( int nod, int st, int dr, int x, int y )
    {
        if ( x <= st && dr <= y )
            return A[nod];
        else
        {
            int v = 0;
            int m = ( st + dr ) / 2;

            if ( x <= m ) v += query( 2 * nod, st, m, x, y );
            if ( m <  y ) v += query( 2 * nod + 1, m + 1, dr, x, y );

            return v;
        }
    }
};

const int Nmax = 1e5 + 2;

vector <SegmentTree> ST;
vector <int> G[Nmax];
int depth[Nmax], father[Nmax], size[Nmax], value[Nmax];
int length_path[Nmax], start_node[Nmax], pos_in_path[Nmax], path[Nmax];

int N, Q, nrPaths;

void DFS( int nod )
{
    int hson = 0;
    size[nod] = 1;

    for ( auto x: G[nod] )
    {
        if ( father[x] == 0 )
        {
            father[x] = nod;
            depth[x] = depth[nod] + 1;

            DFS( x );

            size[nod] += size[x];

            if ( size[x] > size[hson] )
                hson = x;
        }
    }

    if ( hson == 0 )
        path[nod] = nrPaths++;
    else
        path[nod] = path[hson];

    pos_in_path[nod] = length_path[ path[nod] ]++;
}

void build_heavy_paths()
{
    father[1] = 1;
    depth[1] = 0;
    DFS( 1 );

    for ( int i = 1; i <= N; ++i )
    {
        pos_in_path[i] = length_path[ path[i] ] - pos_in_path[i] - 1;

        if ( pos_in_path[i] == 0 )
            start_node[ path[i] ] = i;
    }
}

void build_segment_trees()
{
    vector< vector<int> > pathValues( nrPaths );

    for ( int i = 0; i < nrPaths; ++i )
        pathValues[i] = vector<int>( length_path[i] );

    for ( int i = 1; i <= N; ++i )
        pathValues[ path[i] ][ pos_in_path[i] ] = value[i];

    for ( int i = 0; i < nrPaths; ++i )
        ST.push_back( SegmentTree( pathValues[i] ) );
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

int query( int x, int y )
{
    if ( depth[ start_node[ path[x] ] ] < depth[ start_node[ path[y] ] ] )
        swap( x, y );

    if ( path[x] == path[y] )
        return ST[ path[x] ].query( min( pos_in_path[x], pos_in_path[y] ), max( pos_in_path[x], pos_in_path[y] ) );
    else
        return ST[ path[x] ].query( 0, pos_in_path[x] ) + query( father[ start_node[ path[x] ] ], y );
}

void removeEdge( int a, int b )
{
    if ( depth[a] > depth[b] ) /// b->a
    {
        value[a] = 1;
        ST[ path[a] ].update( pos_in_path[a], 1 );
    }
    else
    {
        value[b] = 1;
        ST[ path[b] ].update( pos_in_path[b], 1 );
    }
}

int main()
{
    freopen("disconnect.in", "r", stdin);
    freopen("disconnect.out", "w", stdout);

    N = getNr(); Q = getNr();

    for ( int i = 0, a, b; i < N - 1; ++i )
    {
        a = getNr(); b = getNr();

        G[a].push_back( b );
        G[b].push_back( a );
    }

    build_heavy_paths();
    build_segment_trees();

    int V = 0;

    for ( int i = 0; i < Q; ++i )
    {
        int type, x, y;

        type = getNr(); x = getNr(); y = getNr();

        int a = x ^ V;
        int b = y ^ V;

        if ( type == 1 )
        {
            removeEdge(a, b);
        }
        else
        {
            if  (query(a, b) - value[ lca(a, b) ] == 0 )
            {
                cout << "YES\n";
                V = a;
            }
            else
            {
                cout << "NO\n";
                V = b;
            }
        }
    }

    return 0;
}
