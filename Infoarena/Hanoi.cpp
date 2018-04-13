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

const ull INF = 1e18;
const double EPS = 1e-9;

const int Nmax = 250 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int X[100];

void mult( int B )
{
      int i, t = 0;

      for ( i = 1; i <= X[0] || t; i++, t /= 10 )
              X[i] = ( t += X[i] * B ) % 10;

      X[0] = i - 1;
}

void afis()
{
    for ( int i = X[0]; i >= 1; i-- )
        cout << X[i];
}

///Frame–Stewart algorithm

ull dp[251][151];

ull T( int n, int r )
{
    if ( dp[n][r] > 0 )
        return dp[n][r];

    if ( n == 0 || n == 1 )
        return n;

    if ( r == 3 )
    {
        if ( n > 60 )
            return INF;

        return dp[n][r] = ( 1LL << n ) - 1;
    }

    ull sol = INF;

    for ( int k = n - 1; k >= 1; k-- )
    {
        sol = min( sol, 2 * T( k, r ) + T( n - k, r - 1 ) );
    }

    return dp[n][r] = sol;
}

int N, K;

int main()
{
    FIN("hanoi.in");
    FOUT("hanoi.out");

    cin >> N >> K;

    if ( K == 3 )
    {
        X[0] = X[1] = 1;

        for ( int i = 1; i <= N; ++i )
            mult( 2 );

        X[1]--;

        afis();
    }
    else
    {
        cout << T( N, K );
    }

    return 0;
}
