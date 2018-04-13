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

const int INF = 2e9;
const double EPS = 1e-9;

const int Nmax = 1e5 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

const ull BASE = 666013;

ull Hpow[Nmax], HA[Nmax], HB[Nmax];

char A[Nmax], B[Nmax];

int NA, NB, K;

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= NB; ++i )
        Hpow[i] = Hpow[i - 1] * BASE;

    for ( int i = 1; i <= NA; ++i )
        HA[i] = HA[i - 1] * BASE + A[i];

    for ( int j = 1; j <= NB; ++j )
        HB[j] = HB[j - 1] * BASE + B[j];
}

ull getHash( ull X[], int i, int j )
{
    return X[j] - X[i - 1] * Hpow[j - i + 1];
}

int findNextBad( int posA, int posB )
{
    int st = 0, dr = min( NB - posB, NA - posA ), m, gasit = -1;

    while ( st <= dr )
    {
        m = ( st + dr ) / 2;

        if ( getHash( HA, posA, posA + m ) != getHash( HB, posB, posB + m ) )
        {
            gasit = m;
            dr = m - 1;
        }
        else
            st = m + 1;
    }

    return gasit;
}

int main()
{
    FIN("partialmatch.in");
    FOUT("partialmatch.out");

    cin >> ( A + 1 ) >> ( B + 1 );

    NA = strlen( A + 1 );
    NB = strlen( B + 1 );

    cin >> K;

    pregen();

    if ( NA > NB )
    {
        cout << "0\n";
        return 0;
    }

    if ( NA == NB )
    {
        int fail = 0;

        for ( int i = 1; i <= NA; ++i )
            fail += ( A[i] != B[i] );

        if ( fail > K )
            cout << "0\n";
        else
            cout << "1\n0\n";

        return 0;
    }

    VI sol;

    for ( int i = 1; i + NA - 1 <= NB; ++i )
    {
        int fail = 0;

        int posA = 1;
        int posB = i;

        while ( fail <= K )
        {
            int p = findNextBad( posA, posB );

            if ( p == -1 )
                break;

            fail++;
            posB = posB + p + 1;
            posA = posA + p + 1;
        }

        if ( fail <= K )
            sol.pb( i - 1 );
    }

    cout << sol.size() << "\n";

    for ( auto x: sol )
        cout << x << "\n";

    return 0;
}
