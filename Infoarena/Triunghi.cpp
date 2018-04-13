#include <bits/stdc++.h>

#define VI vector<int>
#define VII vector<pair<int,int>>

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

    do
    {
        s[ i++ ] = a % 10 + '0';
        a /= 10;

    } while ( a );

    i--;

    while ( i >= 0 ) putchar_unlocked( s[ i-- ] );
}

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int dl[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const int INF = 1e9;
const double EPS = 1e-9;

const int Nmax = 18 + 2;
const int Smax = 1e6 + 2;
const int LgMax = log2(Nmax) + 1;

using namespace std;

int V[Nmax];
int dp[Nmax][Nmax];
bool format[Smax];
int back[Smax];
int a[Nmax];

int N, S;

int calc_dp()
{
    for ( int i = 1; i <= N; ++i )
        dp[N][i] = V[i];

    for ( int i = N - 1; i >= 1; i-- )
        for ( int j = 1; j <= i; ++j )
            dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];

    int s = 0;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= i; ++j )
            s += dp[i][j];

    return s;
}

int main()
{
    FIN("triunghi.in");
    FOUT("triunghi.out");

    read( N ); read( S );

    for ( int i = 1; i <= N; ++i )
    {
        V[i] = 1;
        a[i] = calc_dp();
        V[i] = 0;
    }

    for ( int i = 1; i <= N; ++i )
        V[i] = 1;

    S -= calc_dp();

    format[0] = 1;

    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = 0; j <= S - a[i]; ++j )
        {
            if ( format[j] && format[j + a[i]] == 0 )
            {
                format[j + a[i]] = 1;
                back[j + a[i]] = j;
            }
        }
    }

    int sum = S;

    while ( sum )
    {
        int val = sum - back[sum];

        for ( int i = 1; i <= N; ++i )
            if ( a[i] == val )
            {
                V[i]++;
                break;
            }

        sum = back[sum];
    }


    calc_dp();

    for ( int i = 1; i <= N; ++i, putchar( '\n' ) )
        for ( int j = 1; j <= i; ++j )
        {
            write( dp[i][j] );
            putchar( ' ' );
        }

    return 0;
}
