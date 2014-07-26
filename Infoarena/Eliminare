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

const int Nmax = 1e6 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int v[Nmax];
int vis[Nmax];

int A[4 * Nmax];
int P[4 * Nmax];

int aib[Nmax];

int N, M;

void update( int pos, int val )
{
    for ( int i = pos; i <= N; i += lsb( i ) )
        aib[i] += val;
}

int query( int x )
{
    int s = 0;

    for ( int i = x; i >= 1; i -= lsb( i ) )
        s += aib[i];

    return s;
}

int bin_search( int sum )
{
    int initSum = sum;
    int step = ( 1 << 20 ), i = 0;

    for ( ; step; step >>= 1 )
    {
        if ( i + step <= N && sum > aib[i + step] )
        {
            i += step;
            sum -= aib[i];
        }
    }

    if ( query( i + 1 ) != initSum )
        return -1;
    else
        return i + 1;
}

void upd( int nod )
{
    if ( A[2 * nod] >= A[2 * nod + 1] )
    {
        A[nod] = A[2 * nod];
        P[nod] = P[2 * nod];
    }
    else
    {
        A[nod] = A[2 * nod + 1];
        P[nod] = P[2 * nod + 1];
    }
}

void build( int nod, int st, int dr )
{
    if ( st == dr )
    {
        A[nod] = v[st];
        P[nod] = st;
    }
    else
    {
        int m = ( st + dr ) / 2;

        build( 2 * nod, st, m );
        build( 2 * nod + 1, m + 1, dr );

        upd( nod );
    }
}

void update( int nod, int st, int dr, int pos )
{
    if ( st == dr )
    {
        A[nod] = -1e9;
    }
    else
    {
        int m = ( st + dr ) / 2;

        if ( pos <= m ) update( 2 * nod, st, m, pos );
        else            update( 2 * nod + 1, m + 1, dr, pos );

        upd( nod );
    }
}

pp query( int nod, int st, int dr, int st_q, int dr_q )
{
    if ( st_q <= st && dr <= dr_q )
    {
        return mp( A[nod], P[nod] );
    }
    else
    {
        int m = ( st + dr ) / 2;
        pp sol = mp( -1e9, 0 );

        if ( st_q <= m )
        {
            pp p = query( 2 * nod, st, m, st_q, dr_q );

            if ( sol.fi < p.fi )
                sol = p;
        }

        if ( m < dr_q )
        {
            pp p = query( 2 * nod + 1, m + 1, dr, st_q, dr_q );

            if ( sol.fi < p.fi )
                sol = p;
        }

        return sol;
    }
}

int main()
{
    FIN("eliminare.in");
    FOUT("eliminare.out");

    read( N ); read( M );

    for ( int i = 1; i <= N; ++i )
    {
        read( v[i] );
        update( i, 1 );
    }

    build( 1, 1, N );

    for ( int i = 1, x, y; i <= M; ++i )
    {
        read( x ); read( y );

        int a = bin_search( x );
        int b = bin_search( y );

        pp sol = query( 1, 1, N, a, b );

        vis[ sol.se ] = 1;
        update( sol.se, -1 );
        update( 1, 1, N, sol.se );
    }

    for ( int i = 1; i <= N; ++i )
        if ( vis[i] == 0 )
            write( v[i] ),
            putchar( '\n' );

    return 0;
}
