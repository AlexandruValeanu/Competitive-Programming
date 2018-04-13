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

const int Nmax = 4e5 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

struct nod
{
    int val;
    int ind;

    bool operator < ( const nod &X ) const
    {
        if ( val != X.val )
            return val < X.val;
        else
            return ind > X.ind;
    }

} V[Nmax];

int scos[Nmax];
int sol[Nmax][6];
int urm[Nmax], prv[Nmax];

int N, M, k, p, G, H;

int main()
{
    FIN("ismquery.in");
    FOUT("ismquery.out");

    read( N ); read( M );

    for ( int i = 1; i <= N; ++i )
    {
        read( V[i].val );
        V[i].ind = i;
    }

    for ( int i = 1; i <= N; ++i )
    {
        prv[i] = i - 1;
        urm[i] = i + 1;
    }

    urm[N] = 0;

    read( G ); read( H );

    sort( V + 1, V + N + 1 );

    for ( int i = 1; i <= N; ++i )
    {
        int nod = urm[ V[i].ind ];
        int k = 1;

        while ( nod && k <= 5 )
        {
            sol[ V[i].ind ][k] = nod;
            k++;
            nod = urm[nod];
        }

        int pr = prv[ V[i].ind ];
        int ur = urm[ V[i].ind ];

        urm[ pr ] = ur;
        prv[ ur ] = pr;

        scos[ V[i].ind ] = 1;
    }

    k = 1; p = 1;

    for ( int i = 1; i <= M; ++i )
    {
        p = 1 + ( i + p * G ) % N;
        k = 1 + ( i + k * H ) % 5;

        cout << sol[p][k] << "\n";
    }

    return 0;
}
