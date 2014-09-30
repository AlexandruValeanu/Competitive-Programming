#include <bits/stdc++.h>

#define VI vector<int>
#define VII vector< pair<int,int> >
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
#define bit(n,i) ( n & ( 1LL << i ) )
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
    int sign = 1;

    do
    {
        ch = getchar();

    } while ( !isdigit( ch ) && ch != '-' );

    if ( ch == '-' )
    {
        sign = -1;
        ch = getchar();
    }

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar();

    } while( isdigit( ch ) );

    a *= sign;
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
        putchar( '-' );

    while ( i >= 0 ) putchar( s[ i-- ] );
}

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int dl[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const int INF = 2e9;
const double EPS = 1e-9;

const int Nmax = 2e3 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

class DSU
{
public:

    DSU() {}

    DSU( const int _N )
    {
        N = _N;

        Father = vector<int>( N + 1, 0 );
        Rank = vector<int> ( N + 1, 0 );

        initialise();
    }

    void initialise()
    {
        for ( int i = 1; i <= N; ++i )
        {
            Father[i] = i;
            Rank[i] = 1;
        }
    }

    int Find( int node )
    {
        int root, auxNode;

        for ( root = node; Father[ root ] != root; root = Father[ root ] );

        while ( node != Father[ node ] )
        {
            auxNode = Father[ node ];
            Father[ node ] = root;
            node = auxNode;
        }

        return root;
    }

    int Check( int x, int y )
    {
        return ( Find( x ) == Find( y ) );
    }

    void Union( int x, int y )
    {
        x = Find( x );
        y = Find( y );

        if ( Rank[x] < Rank[y] )
            Father[x] = y;
        else
            Father[y] = x;

        if ( Rank[x] == Rank[y] )
            Rank[y]++;
    }

private:

    vector <int> Father, Rank;
    int N;
};

struct Edge
{
    int a, b, c;

    Edge( int _x = 0, int _y = 0, int _c = 0 )
    {
        a = _x;
        b = _y;
        c = _c;
    }

    bool operator < ( const Edge &E ) const
    {
        return c < E.c;
    }
};

Edge muchie[Nmax * Nmax];
VII G[Nmax];
int D[Nmax][Nmax];
int A[Nmax][Nmax];
int vis[Nmax];

int N, E;

void DFS( int root, int nod )
{
    vis[nod] = 1;

    for ( int i = 0; i < G[nod].size(); ++i )
    {
        int x = G[nod][i].fi;
        int y = G[nod][i].se;

        if ( !vis[x] )
        {
            A[root][x] = A[root][nod] + y;
            DFS( root, x );
        }
    }
}

int main()
{
    ///FIN("data.in");
    ///FOUT("data.out");

    read( N );

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
            read( D[i][j] );

    if ( N == 1 )
    {
        if ( D[1][1] )
            cout << "NO\n";
        else
            cout << "YES\n";

        return 0;
    }

    for ( int i = 1; i <= N; ++i )
        if ( D[i][i] )
        {
            cout << "NO\n";
            return 0;
        }

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
            if ( i != j && D[i][j] == 0 )
            {
                cout << "NO\n";
                return 0;
            }

    for ( int i = 1; i <= N; ++i )
        for ( int j = i + 1; j <= N; ++j )
            if ( D[i][j] != D[j][i] )
            {
                cout << "NO\n";
                return 0;
            }

    for ( int i = 1; i <= N; ++i )
        for ( int j = i + 1; j <= N; ++j )
            muchie[ ++E ] = Edge( i, j, D[i][j] );

    sort( muchie + 1, muchie + E );

    DSU dsu( N );

    for ( int i = 1; i <= E; ++i )
    {
        int a = muchie[i].a;
        int b = muchie[i].b;
        int c = muchie[i].c;

        if ( dsu.Check( a, b ) == 0 )
        {
            dsu.Union( a, b );

            G[a].pb( pp( b, c ) );
            G[b].pb( pp( a, c ) );
        }
    }

    for ( int i = 1; i <= N; ++i )
    {
        ms( vis, 0 );
        DFS( i, i );
    }

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
            if ( D[i][j] != A[i][j] )
            {
                cout << "NO\n";
                return 0;
            }

    cout << "YES\n";

    return 0;
}
