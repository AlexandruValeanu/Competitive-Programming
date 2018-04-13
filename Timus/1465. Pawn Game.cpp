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

const int LgMax = log2(Nmax) + 1;

using namespace std;

int grundy[Nmax];
int visited[Nmax];

int mex( int n )
{
    if ( grundy[n] != -1 )
        return grundy[n];

    if ( n <= 1 )
        return grundy[n] = n;

    /// pun primul sau ultimul (consum 2 casute: 1,2 sau n-1,n)
    visited[ mex( n - 2 ) ] = n;

    for ( int i = 2; i < n; ++i )
    {
        /// pun la i (consum i-1,i,i+1)
        int st = i - 2;
        int dr = n - ( i + 2 ) + 1;

        int valSt = 0, valDr = 0;

        if ( st >= 1 ) valSt = mex( st );
        if ( dr >= 1 ) valDr = mex( dr );

        visited[ valSt ^ valDr ] = n;
    }

    grundy[n] = 0;

    while ( visited[ grundy[n] ] == n )
        grundy[n]++;

    return grundy[n];
}

int findValue( int n )
{
    if ( n <= 102 )
        return grundy[n];
    else
        return grundy[ 69 + ( n - 69 ) % 34 ];
}

int main()
{
    ms( grundy, -1 );
    ms( visited, 0 );

    for ( int i = 1; i < Nmax; ++i )
        grundy[i] = mex( i );

    int N;

    cin >> N;

    if ( findValue( N ) )
        cout << "White\n";
    else
        cout << "Black\n";


    return 0;
}
