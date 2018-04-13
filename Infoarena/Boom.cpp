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

const int INF = 1e9;
const double EPS = 1e-9;

const int Nmax = 20;
const int NN = 1 << Nmax;
const int Mmax = 50;

const int LgMax = log2(Nmax) + 1;

using namespace std;

struct Sarja
{
    int cost;
    int mask;

} S[Mmax];

priority_queue <pp, vector<pp>, greater<pp> > MinHeap;

int dist[NN], tata[NN], sarja[NN];
int N, M;

void afis( int nod )
{
    for ( int i = 0; i < N; ++i )
        cout << (bool)bit( nod, i );

    cout<<endl;
}

void Dijkstra()
{
    ms( dist, 0x3f );

    dist[( 1 << N ) - 1] = 0;
    MinHeap.push( pp( 0, ( 1 << N ) - 1 ) );

    while ( MinHeap.size() )
    {
        pp nod = MinHeap.top();
        MinHeap.pop();

        for ( int j = 0; j < M; ++j )
        {
            int atacate = nod.se & S[j].mask;
            int ramase = nod.se ^ atacate;

            int newNode = ( ramase << 1 ) | ( ramase >> 1 );

            if ( bit( newNode, N ) )
                newNode ^= ( 1 << N );

            if ( dist[newNode] > dist[nod.se] + S[j].cost )
            {
                dist[newNode] = dist[nod.se] + S[j].cost;
                tata[newNode] = nod.se;
                sarja[newNode] = j;
                MinHeap.push( pp( dist[newNode], newNode ) );
            }
        }
    }
}

int main()
{
    FIN("boom.in");
    FOUT("boom.out");

    read( N ); read( M );

    for ( int i = 0; i < M; ++i )
    {
         read( S[i].cost );

         int nr, a;

         read( nr );

         while ( nr-- )
         {
             read( a );
             S[i].mask |= ( 1 << ( a - 1 ) );
         }
    }

    Dijkstra();

    VI sol;

    write( dist[0] );
    putchar( '\n' );

    int nod = 0;

    while ( nod != ( 1 << N ) - 1 )
    {
        sol.pb( sarja[nod] );
        nod = tata[nod];
    }

    write( sol.size() );
    putchar( '\n' );

    for ( int i = sol.size() - 1; i >= 0; i-- )
    {
        write( sol[i] + 1 );
        putchar( '\n' );
    }

    return 0;
}
