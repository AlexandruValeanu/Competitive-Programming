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

const int Nmax = 13;
const int NN = 1 << Nmax;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int dp[NN];
int T, N, K;

int game( int state )
{
    if ( dp[state] != -1 )
        return dp[state];

    if ( state == 0 )
        return dp[state] = 0;

    int sol = 0;

    for ( int lg = 1; lg <= K; ++lg )
    {
        int mask = 0;

        for ( int j = 0; j <= lg - 1; ++j )
            mask |= ( 1 << j );

        for ( int j = 0; j + lg - 1 < Nmax; ++j )
        {
            if ( ( state & ( mask << j ) ) == ( mask << j ) )
            {
                int newState = state ^ ( mask << j );

                if ( game( newState ) == 0 )
                    sol = 1;
            }

            if ( sol ) break;
        }

        if ( sol ) break;
    }

    return dp[state] = sol;
}

int main()
{
    FIN("carti.in");
    FOUT("carti.out");

    cin >> T;

    while ( T-- )
    {
        ms( dp, -1 );

        cin >> N >> K;

        int state = 0;

        for ( int i = 0; i < N; ++i )
        {
            char ch;
            cin >> ch;
            int nr = ch - '0';

            if ( isdigit( ch ) )
            {
                if ( ch == '1' )
                {
                    cin >> ch;
                    state ^= ( 1 << 9 );
                }
                else
                    state ^= ( 1 << ( nr - 1 ) );
            }
            else
            {
                if ( ch == 'A' )
                    state ^= ( 1 << 0 );

                if ( ch == 'J' )
                    state ^= ( 1 << 10 );

                if ( ch == 'Q' )
                    state ^= ( 1 << 11 );

                if ( ch == 'K' )
                    state ^= ( 1 << 12 );
            }
        }

        if ( game( state ) )
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }

    return 0;
}
