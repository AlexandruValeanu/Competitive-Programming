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

int NA, NB, N;
char A[Nmax], B[2 * Nmax];
int pi[Nmax], d[2 * Nmax];

void prefix()
{
    int lgprefix = 0;

    for ( int i = 2; i <= NA; ++i )
    {
        while ( lgprefix && A[lgprefix + 1] != A[i] )
            lgprefix = pi[lgprefix];

        if ( A[lgprefix + 1] == A[i] )
            lgprefix++;

        pi[i] = lgprefix;
    }
}

void KMP()
{
    int best = 0;
    int sol = 0;
    int lgprefix = 0;

    for ( int i = 1; i <= N; ++i )
    {
        while ( lgprefix && B[i] != A[lgprefix + 1] )
            lgprefix = pi[lgprefix];

        if ( B[i] == A[lgprefix + 1] )
            lgprefix++;

        d[i] = lgprefix;

        if ( d[i] > best )
        {
            best = d[i];
            sol = i - lgprefix;
        }
    }

    cout << sol << "\n";
}

int main()
{
    ///ifstream cin("data.in");

    cin >> N;
    cin >> ( A + 1 ) >> ( B + 1 );

    NA = N;
    NB = 2 * N;

    for ( int i = 1; i <= N; ++i )
        B[i + N] = B[i];

    prefix();
    KMP();

    return 0;
}
