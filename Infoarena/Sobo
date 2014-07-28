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

const int Nmax = 15;
const int NN = 1 << Nmax;
const int Lmax = 1e3;

const int LgMax = log2(Nmax) + 1;

using namespace std;

string v[Nmax];
int cost[Lmax];
int dp[NN];
int who[Lmax]; /// cine are 1 la who[i]

int N, L, mask;

int memo( int state )
{
    if ( dp[state] != -1 )
        return dp[state];

    if ( state == 0 )
        return dp[state] = 0;

    int res = 1e9;

    for ( int i = 0; i < L; ++i )
    {
        int newState1 = ( state & who[i] ); /// daca se raspunde cu 1
        int newState2 = ( state ^ newState1 ); /// daca se raspunde cu 0

        if ( ( newState1 != state && newState2 != state ) && ( newState1 && newState2 ) )
        {
            int sol1 = memo( newState1 );
            int sol2 = memo( newState2 );

            int ans = max( sol1, sol2 ) + cost[i];
            res = min( res, ans );
        }
    }

    if ( res == 1e9 ) res = 0;

    return dp[state] = res;
}

int main()
{
    FIN("sobo.in");
    FOUT("sobo.out");

    cin >> N >> L;

    mask = ( 1 << N ) - 1;

    for ( int i = 0; i < N; ++i )
        cin >> v[i];

    for ( int i = 0; i < L; ++i )
        cin >> cost[i];

    for ( int i = 0; i < NN; ++i )
        dp[i] = -1;

    for ( int i = 0; i < N; ++i )
    {
        for ( int j = 0; j < L; ++j )
        {
            if ( v[i][j] == '1' )
                who[j] |= ( 1 << i );
        }
    }

    cout << memo( mask ) << "\n";

    return 0;
}
