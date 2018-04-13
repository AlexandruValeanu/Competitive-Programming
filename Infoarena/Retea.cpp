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

const int BS = ( 1 << 18 );
char buffer[BS];
int position = BS;

inline char getChar()
{
    if ( position == BS )
    {
        position = 0;
        fread( buffer, 1, BS, stdin );
    }

    return buffer[ position++ ];
}

inline void read( int &a )
{
    register char ch;
    a = 0;

    do
    {
        ch = getChar();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getChar();

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

const double INF = 2e9;
const double EPS = 1e-9;

const int Nmax = 1e3 + 1;
const int Kmax = 10 + 1;

const int LgMax = log2(Nmax) + 1;

using namespace std;

float A[Nmax][Kmax];
VII G[Nmax];

struct node
{
    int nod;
    int k;
    double val;

    node( int a, int b, double c )
    {
        nod = a;
        k = b;
        val = c;
    }

    bool operator < ( const node &X ) const
    {
        return val > X.val;
    }
};

priority_queue < node, vector<node> > Q;

int N, M, K;

void Dijkstra()
{
    for ( int i = 1; i <= N; ++i )
        for ( int j = 0; j <= K; ++j )
            A[i][j] = INF;

    A[1][0] = 0;
    Q.push( node( 1, 0, 0 ) );

    while ( Q.size() )
    {
        int nod = Q.top().nod;
        int k = Q.top().k;
        double c = Q.top().val;
        Q.pop();

        if ( nod == N && k == K ) return;
        if ( c != A[nod][k] ) continue;

        for ( auto x: G[nod] )
        {
            int vec = x.fi;
            double cost = x.se;

            for ( int l = K - k; l >= 0; l-- )
            {
                double pw = ( 1 << l );
                double C = 1.0 * cost / pw;

                if ( A[vec][l + k] > A[nod][k] + C )
                {
                    A[vec][l + k] = A[nod][k] + C;
                    Q.push( node( vec, l + k, A[vec][l + k] ) );
                }
            }
        }
    }
}

int main()
{
    FIN("retea.in");
    FOUT("retea.out");

    read( N ); read( M ); read( K );

    for ( int i = 1, a, b, c; i <= M; ++i )
    {
        read( a ); read( b ); read( c );

        G[a].pb( mp( b, c ) );
        G[b].pb( mp( a, c ) );
    }

    Dijkstra();

    cout << fixed << setprecision( 4 );
    cout << A[N][K] << "\n";

    return 0;
}
