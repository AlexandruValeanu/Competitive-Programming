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
        ch = getchar();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar();

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
        putchar( '-' );

    while ( i >= 0 ) putchar( s[ i-- ] );
}

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int dl[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const int INF = 2e9;
const double EPS = 1e-9;

const int Nmax = 22;
const int NN = ( 1 << Nmax );

const int LgMax = log2(Nmax) + 1;

using namespace std;

char dp[NN];

char gen_game( int state )
{
    if ( dp[state] != '-' )
        return dp[state];

    char sol = '0';
    int st = -1;

    for ( int i = 0; i < Nmax && sol == '0'; ++i )
    {
        if ( bit( state, i ) )
        {
            if ( st != -1 )
            {
                int auxState = state;
                auxState ^= ( 1 << i );
                auxState ^= ( 1 << ( st ) );

                char p = gen_game( auxState );

                if ( p == '0' )
                    sol = '1';
            }
        }
        else
            st = i;
    }

    return dp[state] = sol;
}

int N;

int main()
{
    FIN("coins.in");
    FOUT("coins.out");

    for ( int i = 0; i < NN; ++i )
        dp[i] = '-';

    for ( int i = 0; i < Nmax; ++i )
        dp[ ( 1 << i ) - 1 ] = '1';

    read( N );

    int solution = 0;

    while ( N-- )
    {
        int state = 0;

        for ( int i = 0, v; i < Nmax; ++i )
        {
            read( v );
            state ^= ( 1 << i ) * v;
        }

        if ( gen_game( state ) == '1' )
            solution += popcount( state );
    }

    write( solution );

    return 0;
}
