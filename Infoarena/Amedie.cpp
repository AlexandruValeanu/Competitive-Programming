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

const int Nmax = 8e2 + 2;
const int Vmax = 100000;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int aib[Vmax + 2];
int A[Nmax][Nmax];

int N, M, Q;

void update( int pos, int val )
{
    for ( int i = pos; i <= Vmax; i += lsb( i ) )
        aib[i] += val;
}

int query( int pos )
{
    int s = 0;

    for ( int i = pos; i >= 1; i -= lsb( i ) )
        s += aib[i];

    return s;
}

int bin_search( int sum )
{
    int st = 1, dr = Vmax, m, gasit = -1;

    while ( st <= dr )
    {
        m = ( st + dr ) / 2;

        int v = query( m );

        if ( v >= sum )
        {
            gasit = m;
            dr = m - 1;
        }
        else
        {
            st = m + 1;
        }
    }

    return gasit;
}

int main()
{
    FIN("amedie.in");
   FOUT("amedie.out");

    read( N ); read( M ); read( Q );

    int total = N * M;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
        {
            read( A[i][j] );
            update( A[i][j], 1 );
        }

    while ( Q-- )
    {
        char ch;
        int ind;

        cin >> ch;

        if ( ch != 'Q' )
            read( ind );
        else
        {
            write( bin_search( ( total + 1 ) / 2 ) );
            putchar( '\n' );
        }

        if ( ch == 'L' )
        {
            for ( int i = 1; i <= M; ++i )
            {
                if ( A[ind][i] != -1 )
                    update( A[ind][i], -1 ),
                    total--;

                A[ind][i] = -1;
            }
        }

        if ( ch == 'C' )
        {
            for ( int i = 1; i <= N; ++i )
            {
                if ( A[i][ind] != -1 )
                    update( A[i][ind], -1 ),
                    total--;

                A[i][ind] = -1;
            }
        }
    }

    return 0;
}
