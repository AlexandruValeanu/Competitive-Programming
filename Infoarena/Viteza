#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;

struct Query
{
    int x, y, k;
    int ind;

    bool operator < ( const Query &X) const
    {
        if ( k != X.k )
            return k < X.k;
        else
            return ind > X.ind;
    }

} Q[2 * Nmax];

vector <int> G[Nmax];
int value[Nmax], father[Nmax], size[Nmax], depth[Nmax];
int AIB[2 * Nmax], First[Nmax], Last[Nmax];
int pos_in_path[Nmax], path[Nmax], length_path[Nmax], start_node[Nmax], sol[Nmax];
int N, M, E, NumberPaths;

void DFS( int node )
{
    int hson = 0;
    size[node] = 1;

    First[node] = ++E;

    for ( auto x: G[node] )
    {
        if ( father[x] == 0 )
        {
            father[x] = node;
            depth[x] = depth[node] + 1;

            DFS( x );

            size[node] += size[x];

            if ( size[hson] < size[x] )
                hson = x;
        }
    }

    Last[node] = ++E;

    if ( hson == 0 )
        path[node] = NumberPaths++;
    else
        path[node] = path[hson];

    pos_in_path[node] = length_path[ path[node] ]++;
}

void build_hpd()
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

inline int lsb( int x )
{
    return x & ( -x );
}

void update( int pos, int val )
{
    for ( int i = pos; i <= E; i += lsb( i ) )
        AIB[i] += val;
}

int query( int pos )
{
    int s = 0;

    for ( int i = pos; i >= 1; i -= lsb( i ) )
        s += AIB[i];

    return s;
}

int query( int x, int y )
{
    return query( y ) - query( x - 1 );
}

int main()
{
    ifstream in("viteza.in");
    ofstream out("viteza.out");

    in.sync_with_stdio( false );

    in >> N >> M;

    for ( int i = 1, a, b; i < N; ++i )
    {
        in >> a >> b;

        G[a].push_back( b );
        G[b].push_back( a );
    }

    for ( int i = 1; i <= N; ++i )
        in >> value[i];

    build_hpd();

    for ( int i = 1; i <= N; ++i )
    {
        Q[i + M].x = Q[i + M].y = i;
        Q[i + M].ind = i + M;
        Q[i + M].k = value[i];
    }

    for ( int i = 1; i <= M; ++i )
    {
        in >> Q[i].x >> Q[i].y >> Q[i].k;
        Q[i].ind = i;
    }

    sort( Q + 1, Q + N + M + 1 );

    cout << E << endl;

    for ( int i = 1; i <= N + M + 1; ++i )
    {
        int x = Q[i].x;
        int y = Q[i].y;
        int k = Q[i].k;

        if ( Q[i].ind > M )
        {
            update( First[x], 1 );
            update( Last[x], -1 );
        }
        else
        {
            int L = lca( x, y );

            int ans = query( First[L], First[x] ) + query( First[L], First[y] );

            if ( value[L] <= k )
                ans--;

            sol[ Q[i].ind ] = ans;
        }
    }

    for ( int i = 1; i <= M; ++i )
        out << sol[i] << "\n";

    return 0;
}
