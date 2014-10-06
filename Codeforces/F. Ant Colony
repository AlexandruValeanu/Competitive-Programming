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

const int BS = ( 1 << 18 );
char buffer[BS];
int position = BS;

inline char GetChar()
{
    if ( position == BS )
    {
        position = 0;
        fread( buffer, BS, 1, stdin );
    }

    return buffer[ position++ ];
}

inline void read( int &a )
{
    register char ch;
    a = 0;
    int sign = 1;

    do
    {
        ch = GetChar();

    } while ( !isdigit( ch ) && ch != '-' );

    if ( ch == '-' )
    {
        sign = -1;
        ch = GetChar();
    }

    do
    {
        a = a * 10 + ch - '0';
        ch = GetChar();

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

const int LgMax = log2(Nmax) + 2;

using namespace std;

int A[Nmax], rmq[LgMax][Nmax], lg[Nmax];
int ST[Nmax], DR[Nmax];
int N, Q;

void RMQ()
{
    for ( int i = 1; i <= N; ++i )
            rmq[0][i] = A[i];

    for ( int i = 1; ( 1 << i ) <= N; ++i )
            for ( int j = 1; j + ( 1 << i ) - 1 <= N; ++j )
            {
                int p = 1 << ( i - 1 );

                rmq[i][j] = __gcd( rmq[i - 1][j], rmq[i - 1][j + p] );
            }

    for ( int i = 2; i < Nmax; ++i )
            lg[i] = lg[i / 2] + 1;
}

int query( int st, int dr )
{
    int diff = dr - st + 1;
    int k = lg[diff];
    int p = 1 << k;
    int sh = diff - p;

    return __gcd( rmq[k][st], rmq[k][st + sh] );
}

vector <int> G[4 * Nmax];

void build( int nod, int st, int dr )
{
    G[nod] = vector<int>( dr - st + 1 );

    if ( st == dr )
    {
        G[nod][0] = A[st];
    }
    else
    {
        int m = ( st + dr ) / 2;

        build( 2 * nod, st, m );
        build( 2 * nod + 1, m + 1, dr );

        merge( G[2 * nod].begin(), G[2 * nod].end(), G[2 * nod + 1].begin(), G[2 * nod + 1].end(), G[nod].begin() );
    }
}

int ask( int nod, int st, int dr, int st_q, int dr_q, int val )
{
    if ( st_q <= st && dr <= dr_q )
    {
        auto it1 = lower_bound( G[nod].begin(), G[nod].end(), val ) - G[nod].begin();
        auto it2 = upper_bound( G[nod].begin(), G[nod].end(), val ) - G[nod].begin();

        if ( it2 > it1 )
            return it2 - it1;
        else
            return 0;
    }
    else
    {
        int m = ( st + dr ) / 2;
        int s = 0;

        if ( st_q <= m )
            s += ask( 2 * nod, st, m, st_q, dr_q, val );

        if ( m < dr_q )
            s += ask( 2 * nod + 1, m + 1, dr, st_q, dr_q, val );

        return s;
    }
}

int main()
{
    ///FIN("data.in");
    ///FOUT("data.out");

    read( N );

    for ( int i = 1; i <= N; ++i )
        read( A[i] );

    RMQ();
    build( 1, 1, N );

    read( Q );

    while ( Q-- )
    {
        int a, b;
        read( a ); read( b );
        cout << ( b - a + 1 ) - ask( 1, 1, N, a, b, query( a, b ) ) << "\n";
    }

    return 0;
}
