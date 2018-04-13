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

const int Nmax = 1e3 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

struct edge
{
    int x, y, z;

    edge( int a = 0, int b = 0, int c = 0)
    {
        x = a;
        y = b;
        z = c;
    }

    bool operator < ( const edge &E ) const
    {
        return z < E.z;
    }
};

VII G[Nmax];
int dist[Nmax];
vector <edge> Edge;

int N, M;

void Bellman_Ford( int nod )
{
    for ( int i = 1; i <= N; ++i )
        dist[i] = INF;

    dist[nod] = 0;

    for ( int i = 0; i < Edge.size(); ++i )
    {
        int x = Edge[i].x;
        int y = Edge[i].y;
        int z = Edge[i].z;

        if ( dist[x] > dist[y] + z )
        {
            dist[x] = dist[y] + z;
        }
    }
}

int main()
{
    FIN("viteza2.in");
    FOUT("viteza2.out");

    read( N ); read( M );

    for ( int i = 1, a, b, c; i <= M; ++i )
    {
        read( a ); read( b ); read( c );

        Edge.pb( edge( a, b, c ) );
        Edge.pb( edge( b, a, c ) );
    }

    sort( Edge.begin(), Edge.end() );

    for ( int i = 1; i <= N; ++i )
    {
        Bellman_Ford( i );

        for ( int j = 1; j <= N; ++j )
        {
            if ( dist[j] != INF )
                write( dist[j] );
            else
                write( -1 );

            putchar( ' ' );
        }

        putchar( '\n' );
    }

    return 0;
}
