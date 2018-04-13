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

const int Nmax = 1e5 + 2;
const int Vmax = 2e6 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

const int NrStive = 10000;

VI G[Nmax];
VI divisors[Nmax];

pp query[Nmax];
set <pp> Set[Vmax];

int N, Q, P;

void changeDivisorsNode( int nod, int value )
{
    divisors[nod].clear();

    for ( int i = 2; i * i <= value; ++i )
    {
        if ( value % i == 0 )
        {
            divisors[nod].pb( i );

            while ( value % i == 0 ) value /= i;
        }
    }

    if ( value > 1 )
        divisors[nod].pb( value );
}

void DFS( int nod, int tata, int depth )
{
    query[nod] = pp( -1, -1 );

    for ( auto x: divisors[nod] )
    {
        if ( Set[x].size() )
            query[nod] = max( query[nod], *Set[x].rbegin() );

        Set[x].insert( pp( depth, nod ) );
    }

    for ( auto x: G[nod] )
    {
        if ( x != tata )
            DFS( x, nod, depth + 1 );
    }

    for ( auto x: divisors[nod] )
        Set[x].erase( pp( depth, nod ) );
}

int main()
{
    read( N ); read( Q );

    for ( int i = 1, value; i <= N; ++i )
    {
        read( value );
        changeDivisorsNode( i, value );
    }

    for ( int i = 1, a, b; i < N; ++i )
    {
        read( a ); read( b );

        G[a].pb( b );
        G[b].pb( a );
    }

    DFS( 1, 0, 0 );

    while ( Q-- )
    {
        int tip, v, w;

        read( tip );

        if ( tip == 1 )
        {
            read( v );
            cout << query[v].se << "\n";
        }
        else
        {
            read( v ); read( w );

            changeDivisorsNode( v, w );
            DFS( 1, 0, 0 );
        }
    }

    return 0;
}
