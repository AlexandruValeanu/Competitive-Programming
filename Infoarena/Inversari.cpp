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

const int Nmax = 5e3 + 2;
const int Mmax = 1e5 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

VII lg[Nmax];
int A[Nmax];
int sol[Mmax];
int DP[2][Nmax], I[2][Nmax];

int N, M;

int solve( int i, int j )
{
    int sum = 0;

    for ( int k = j - i + 1; k < j; ++k )
        if ( A[k] > A[j] )
            sum++;

    return sum;
}

int main()
{
    FIN("inversari.in");
    FOUT("inversari.out");

    read( N ); read( M );

    for ( int i = 1; i <= N; ++i )
        read( A[i] );

    for ( int i = 1, x, y; i <= M; ++i )
    {
        read( x ); read( y );

        lg[ y - x + 1 ].pb( pp( y, i ) );
    }

    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = i; j <= N; ++j )
        {
            int st = j - i + 1;
            int dr = j;

            I[i & 1][j] = I[(i - 1) & 1][j];

            if ( A[j - i + 1] > A[j] )
                I[i & 1][j]++;

            DP[i & 1][j] = DP[(i - 1) & 1][j - 1] + I[i & 1][j];
        }

        for ( auto x: lg[i] )
        {
            sol[ x.se ] = DP[i & 1][ x.fi ];
        }
    }

    for ( int i = 1; i <= M; ++i )
        cout << sol[i] << "\n";

    return 0;
}
