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

const int Nmax = 1e3 + 2;
const int Kmax = 5 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int pos[Kmax][Nmax], value[Kmax][Nmax], dp[Nmax];
int N, K;

int main()
{
    cin >> N >> K;

    for ( int i = 1; i <= K; ++i )
        for ( int j = 1; j <= N; ++j )
        {
            cin >> value[i][j];
            pos[i][ value[i][j] ] = j;
        }

    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = 1; j < i; ++j )
        {
            int x = value[1][i], y = value[1][j], ok = 1;

            for ( int k = 2; k <= K; ++k )
                if ( pos[k][x] < pos[k][y] )
                    ok = 0;

            if ( ok )
                dp[i] = max( dp[i], dp[j] + 1 );
        }
    }

    cout << *max_element( dp + 1, dp + N + 1 ) + 1;

    return 0;
}
