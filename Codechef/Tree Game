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

const int Nmax = 10000 + 20;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int T, N;

VI G[Nmax];
int depth[Nmax];
VI nivel[Nmax];
int vis[Nmax];

void DFS( int nod )
{
    for ( auto x: G[nod] )
    {
        if ( !vis[x] )
        {
            vis[x] = 1;
            depth[x] = depth[nod] + 1;
            DFS( x );
        }
    }
}

int main()
{
    ///FIN("data.in");
    ///FOUT("data.out");

    cin >> T;

    while ( T-- )
    {
        cin >> N;

        for ( int i = 0; i < Nmax; ++i )
        {
            G[i].clear();
            nivel[i].clear();
            depth[i] = 0;
            vis[i] = 0;
        }

        for ( int i = 1; i < N; ++i )
        {
            int a, b;

            cin >> a >> b;

            G[a].pb( b );
            G[b].pb( a );
        }

        vis[1] = 1;
        DFS( 1 );

        int maxim = 0;

        for ( int i = 1; i <= N; ++i )
        {
            nivel[ depth[i] ].pb( i );
            maxim = max( maxim, depth[i] );
        }

        int nrMoves = 0;
        int player = 0;

        int nivelAlice = 0;
        int nivelBob = maxim;

        while ( 1 )
        {
            if ( player == 0 )
            {
                while ( nivelAlice <= maxim && nivel[ nivelAlice ].size() == 0 ) nivelAlice++;

                if ( nivelAlice > maxim ) break;

                nivel[ nivelAlice ].clear();
                nrMoves++;
            }
            else
            {
                while ( nivelBob >= 0 && nivel[ nivelBob ].size() == 0 ) nivelBob--;

                if ( nivelBob < 0 ) break;

                nivel[ nivelBob ].pop_back();
                nrMoves++;
            }

            player ^= 1;
        }

        for ( int i = 0; i <= N; ++i )
            if ( nivel[i].size() )
                assert( 1 == 0 );

        cout << nrMoves << "\n";
    }

    return 0;
}
