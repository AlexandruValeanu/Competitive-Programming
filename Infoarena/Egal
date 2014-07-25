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
        ch = getchar_unlocked();

    } while ( !isdigit( ch ) || ch == '-' );

    if ( ch == '-' )
    {
        sign = -1;
        ch = getchar_unlocked();
    }

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar_unlocked();

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
        putchar_unlocked( '-' );

    while ( i >= 0 ) putchar_unlocked( s[ i-- ] );
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

unordered_map <int, int> UM[Nmax];

int vecini[Nmax];
int node[2 * Nmax], urm[2 * Nmax];
VI G[Nmax];

int father[Nmax];
int key[Nmax];
int maxim[Nmax];
int apar[Nmax];
int redirect[Nmax];
int dim[Nmax];

int N;
int PP;

inline void addVecin( int x, int y )
{
    node[ ++PP ] = y;
    urm[ PP ] = vecini[x];
    vecini[x] = PP;
}

void DFS( int nod )
{
    int hson = 0;
    dim[nod] = 1;

    int p = vecini[nod];

    while ( p != 0 )
    {
        int x = node[p];

        if ( !father[x] )
        {
            father[x] = nod;
            DFS( x );

            dim[nod] += dim[x];

            if ( dim[hson] < dim[x] )
                hson = x;

            if ( apar[x] > apar[nod] )
            {
                apar[nod] = apar[x];
                maxim[nod] = maxim[x];
            }
            else
            {
                if ( apar[x] == apar[nod] )
                {
                    maxim[nod] = min( maxim[nod], maxim[x] );
                }
            }
        }

        p = urm[p];
    }


    if ( hson == 0 )
    {
        maxim[nod] = key[nod];
        UM[nod][ maxim[nod] ]++;
        apar[nod] = 1;

        redirect[nod] = nod;
    }
    else
    {
        redirect[nod] = redirect[hson];

        UM[ redirect[nod] ][ key[nod] ]++;
        maxim[nod] = key[nod];

        p = vecini[nod];

        while ( p != 0 )
        {
            int x = node[p];

            if ( x != hson )
            {
                for ( auto y: UM[ redirect[x] ] )
                {
                    UM[ redirect[nod] ][y.fi] += y.se;

                    int val1 = UM[ redirect[nod] ][y.fi];
                    int val2 = UM[ redirect[nod] ][ maxim[nod] ];

                    if ( val1 > val2 )
                    {
                        maxim[nod] = y.fi;
                    }
                    else
                    {
                        if ( val1 == val2 )
                        {
                            maxim[nod] = min( maxim[nod], y.fi );
                        }
                    }
                }
            }

            p = urm[p];
        }

        apar[nod] = UM[ redirect[nod] ][ maxim[nod] ];

        if ( UM[ redirect[nod] ][ maxim[hson] ] > UM[ redirect[nod] ][ maxim[nod] ] )
        {
            maxim[nod] = maxim[hson];
            apar[nod] = UM[ redirect[nod] ][ maxim[hson] ];
        }
        else
        {
            if ( UM[ redirect[nod] ][ maxim[hson] ] == UM[ redirect[nod] ][ maxim[nod] ] )
                maxim[nod] = min( maxim[nod], maxim[hson] );
        }
    }
}

int main()
{
    FIN("egal.in");
    FOUT("egal.out");

    read( N );

    for ( int i = 1, a, b; i < N; ++i )
    {
        read( a ); read( b );

        addVecin( a, b );
        addVecin( b, a );
    }

    for ( int i = 1; i <= N; ++i )
        read( key[i] );

    father[1] = 1;
    DFS( 1 );

    for ( int i = 1; i <= N; ++i )
    {
        write( maxim[i] );
        putchar( ' ' );
        write( apar[i] );
        putchar( '\n' );
    }

    return 0;
}
