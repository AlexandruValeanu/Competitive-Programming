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

const int Nmax = 1e4 + 2;
const int Mmax = 1e5 + 2;
const int Wmax = 1e6 + 2;
const int LgMax = log2(Nmax) + 1;

using namespace std;

VII G[Nmax];
VI border;
priority_queue <pp, vector<pp>, greater<pp> > MinHeap;

int timp[Nmax];
int power[Wmax];
bool in_q[Nmax];

int N, M, W;

void Dijsktra()
{
    for ( int i = 1; i <= N; ++i )
        timp[i] = INF;

    in_q[1] = 1;
    timp[1] = 0;

    for ( auto x: G[1] )
    {
        int vec = x.fi;
        int cost = x.se;

        if ( !in_q[vec] )
            MinHeap.push( pp( cost, vec ) );
    }

    for ( int i = 1; i <= W; ++i )
    {
        VI border;

        while ( MinHeap.size() && MinHeap.top().fi <= power[i] )
        {
            int nod = MinHeap.top().se;

            in_q[nod] = 1;
            timp[nod] = min( timp[nod], i );

            MinHeap.pop();
            border.pb( nod );
        }

        for ( auto nod: border )
        {
            for ( auto x: G[nod] )
            {
                int vec = x.fi;
                int cost = x.se;

                if ( !in_q[vec] )
                    MinHeap.push( pp( cost, vec ) );
            }
        }
    }
}

int main()
{
    FIN("mine.in");
    FOUT("mine.out");

    read( N ); read( M );

    for ( int i = 1, a, b, c; i <= M; ++i )
    {
        read( a ); read( b ); read( c );

        G[a].pb( pp( b, c ) );
        G[b].pb( pp( a, c ) );
    }

    read( W );

    for ( int i = 1; i <= W; ++i )
        read( power[i] );

    Dijsktra();

    if ( timp[N] != INF )
        write( timp[N] );
    else
        write( -1 );

    return 0;
}
