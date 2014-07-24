#include <bits/stdc++.h>

#define VI vector<int>
#define VII vector<pair<int,int>>

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

    do
    {
        s[ i++ ] = a % 10 + '0';
        a /= 10;

    } while ( a );

    i--;

    while ( i >= 0 ) putchar_unlocked( s[ i-- ] );
}

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int dl[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
const int dc[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

const int INF = 1e9;
const double EPS = 1e-9;

const int Nmax = 1e3 + 2;
const int LgMax = log2(Nmax) + 1;

using namespace std;

int A[Nmax][Nmax];
int C[Nmax][Nmax];
char s[Nmax];
vector <int> G[Nmax * Nmax];
int father[Nmax * Nmax], depth[Nmax * Nmax], good[Nmax * Nmax], suma[Nmax * Nmax];
int N, M, Q, NrNodes;

int valid( int x, int y )
{
    return ( 1 <= x && x <= N && 1 <= y && y <= M );
}

void FILL( int x, int y, int c )
{
    C[x][y] = c;

    for ( int k = 0; k < 8; ++k )
    {
        if ( valid( x + dl[k], y + dc[k] ) && A[x][y] == A[x + dl[k]][y + dc[k]] && C[x + dl[k]][y + dc[k]] == 0 )
                FILL( x + dl[k], y + dc[k], c );
    }
}

void DFS( int nod )
{
    for ( auto x: G[nod] )
    {
        if ( !father[x] )
        {
            depth[x] = depth[nod] + 1;
            father[x] = nod;

            suma[x] = suma[nod];

            if ( good[x] )
                suma[x]++;

            DFS( x );
        }
    }
}

int LCA( int x, int y )
{
    while ( x != y )
    {
        if ( depth[x] < depth[y] )
            y = father[y];
        else
            x = father[x];
    }

    return x;
}

int nrGood( int x, int L )
{
    return suma[x] - suma[L];
}

int query( int x, int y )
{
    int L = LCA( x, y );
    int ans = nrGood( x, L ) + nrGood( y, L );

    if ( good[L] )
        ans++;

    return ans;
}

int main()
{
    ifstream in("pirati.in");
    ofstream out("pirati.out");

    in.sync_with_stdio( false );

    in >> N >> M >> Q;

    for ( int i = 1; i <= N; ++i )
    {
        in >> s;

        for ( int j = 0; j < M; ++j )
            A[i][j + 1] = s[j] - '0';
    }

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            if ( C[i][j] == 0 )
            {
                NrNodes++;
                FILL( i, j, NrNodes );
            }

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            for ( int k = 0; k < 8; ++k )
                if ( valid( i + dl[k], j + dc[k] ) )
                    if ( C[i][j] != C[i + dl[k]][j + dc[k]] && C[i + dl[k]][j + dc[k]] )
                        G[ C[i][j] ].push_back( C[i + dl[k]][j + dc[k]] );


    for ( int i = 1; i <= NrNodes; ++i )
        good[i] = 1;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            if ( A[i][j] == 0 )
                good[ C[i][j] ] = 0;

    if ( good[1] == 1 )
        suma[1] = 1;

    father[1] = 1;
    DFS( 1 );

    int x1, y1, x2, y2;

    while ( Q-- )
    {
        in >> x1 >> y1 >> x2 >> y2;
        out << query( C[x1][y1], C[x2][y2] ) << "\n";
    }

    return 0;
}
