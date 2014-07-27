#include <bits/stdc++.h>

#define VI vector<int>
#define VII vector<pair<int,int>>
#define QI queue<int>

#define ms(a,v) memset( a, v, sizeof( a ) )
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define foreach(v, c) for( typeof( (c).begin() ) v = (c).begin(); v != (c).end(); ++v)

#define pb push_back
#define pp pair<int,int>
#define mp make_pair
#define fi first
#define se second

#define popcount __builtin_popcount
#define gcd __gcd
#define bit(n,i) ( n & ( 1 << i ) )
#define lsb(x) ( x & ( -x ) )

#define FIN(str) freopen(str,"r",stdin)
#define FOUT(str) freopen(str,"w",stdout)
#define Fin(str) ifstream(str)
#define Fout(str) ostream(str)
#define SYNC ios_base::sync_with_stdio(0);

#define ll long long
#define ull unsigned long long

inline void read( int &a )
{
    register char ch;
    a = 0;

    do
    {
        ch = getchar_unlocked();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar_unlocked();

    } while( isdigit( ch ) );
}

inline void write( int a )
{
    char s[20];
    int i = 0;
    int sign = 1;

    if ( a < 0 )
        sign = -1,
        a = -a;

    do
    {
        s[ i++ ] = a % 10 + '0';
        a /= 10;

    } while ( a );

    i--;

    if ( sign == -1 )
        putchar_unlocked( '-' );

    while ( i >= 0 ) putchar_unlocked( s[ i-- ] );
}

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int dl[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const int INF = 2e9;
const double EPS = 1e-9;

const int Nmax = 2e5 + 2;

const int LgMax = log2(Nmax) + 2;

using namespace std;

VI G[Nmax];
int father[Nmax], depth[Nmax];
int size[Nmax], path[Nmax], lengthPath[Nmax], pos_in_path[Nmax], start_node[Nmax];

int N, Q, nrPaths, timp;

void DFS( int node )
{
    int heavySon = 0;
    size[node] = 1;

    for ( auto x: G[node] )
    {
        if ( father[x] == 0 )
        {
            father[x] = node;
            depth[x] = depth[node] + 1;
            DFS( x );

            size[node] += size[x];

            if ( size[heavySon] < size[x] )
                heavySon = x;
        }
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

int dist( int x, int y )
{
    return depth[x] + depth[y] - 2 * depth[ lca( x, y ) ];
}

int main()
{
    read( N );

    for ( int i = 1, a, b; i < N; ++i )
    {
        read( a ); read( b );
        G[a].pb( b );
        G[b].pb( a );
    }

    build_heavy_path();

    read( Q );

    while ( Q-- )
    {
        int r, u, v;

        read( r ); read( u ); read( v );

        pp a[7];

        a[0].se = r;
        a[1].se = u;
        a[2].se = v;
        a[3].se = lca( r, u );
        a[4].se = lca( r, v );
        a[5].se = lca( u, v );

        for ( int i = 0; i < 6; ++i )
            a[i].fi = dist( a[i].se, u ) + dist( a[i].se, v ) + dist( a[i].se, r );

        sort( a, a + 6 );

        write( a[0].se );
        putchar( '\n' );
    }

    return 0;
}
