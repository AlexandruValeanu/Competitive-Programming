#include <bits/stdc++.h>

using namespace std;

const int Nmax = 32e3 + 1;
const int Mmax = 5e5 + 1;
const int LgMax = 15 + 1;

vector < pair<int,int> > G[Nmax];
int rmq[LgMax][Nmax];
int dad[LgMax][Nmax];
int father[Nmax], level[Nmax], size[Nmax];
int pos_in_path[Nmax], start_node[Nmax], path[Nmax], length_path[Nmax];

int NumberPaths;

int N, M, P, logN;
int X, Y, Z;
int A, B, C, D;

void DFS( int node )
{
    int hson = 0;
    size[node] = 1;

    for ( auto x: G[node] )
    {
        if ( father[x.first] == 0 )
        {
            father[x.first] = node;
            rmq[0][x.first] = x.second;
            dad[0][x.first] = node;
            level[x.first] = level[node] + 1;

            DFS( x.first );

            size[node] += size[x.first];

            if ( size[x.first] > size[hson] )
                hson = x.first;
        }
    }

    if ( hson == 0 )
        path[node] = NumberPaths++;
    else
        path[node] = path[hson];

    pos_in_path[node] = length_path[ path[node] ]++;
}

void build_heavy_path()
{
    father[1] = 1;
    rmq[0][1] = 1e9;
    dad[0][1] = 1;
    level[1] = 0;

    DFS( 1 );

    for ( int i = 1; i <= N; ++i )
    {
        pos_in_path[i] = length_path[ path[i] ] - pos_in_path[i] - 1;

        if ( pos_in_path[i] == 0 )
            start_node[ path[i] ] = i;
    }
}

void build_rmq()
{
    for ( int i = 1; ( 1 << i ) <= N; ++i )
        for ( int j = 1; j <= N; ++j )
        {
            dad[i][j] = dad[i - 1][ dad[i - 1][j] ];
            rmq[i][j] = min( rmq[i - 1][j], rmq[i - 1][ dad[i - 1][j] ] );
        }
}

int lca( int x, int y )
{
    while ( path[x] != path[y] )
    {
        if ( level[ start_node[ path[x] ] ] < level[ start_node[ path[y] ] ] )
            y = father[ start_node[ path[y] ] ];
        else
            x = father[ start_node[ path[x] ] ];
    }

    return pos_in_path[x] < pos_in_path[y] ? x : y;
}

int get_min( int x, int L )
{
    int sol = 1e9;
    int dif = abs( level[x] - level[L] );

    for ( int i = 0; ( 1 << i ) <= dif; ++i )
    {
        if ( ( 1 << i ) & dif )
        {
            sol = min( sol, rmq[i][x] );
            x = dad[i][x];
        }
    }

    return sol;
}

int solve( int x, int y )
{
    if ( x == y )
        return 0;

    int L = lca( x, y );

    return min( get_min( x, L ), get_min( y, L ) );
}

int main()
{
    ifstream in("atac.in");
    ofstream out("atac.out");

    in.sync_with_stdio( false );

    in >> N >> M >> P;

    for ( int i = 2, a, c; i <= N; ++i )
    {
        in >> a >> c;

        G[a].push_back( make_pair( i, c ) );
        G[i].push_back( make_pair( a, c ) );
    }

    in >> X >> Y >> A >> B >> C >> D;

    build_heavy_path();
    build_rmq();

    for ( int i = 1; i <= M; ++i )
    {
        Z = solve( X, Y );

        if ( i >= M - P + 1 )
            out << Z << "\n";

        X = ( 1LL * X * A + 1LL * Y * B ) % N + 1;
        Y = ( 1LL * Y * C + 1LL * Z * D ) % N + 1;
    }

    return 0;
}
