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

const int Nmax = 5e4 + 1;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int N, T;

int grundy[Nmax];
int query[Nmax];
bool visited[Nmax];

int mex( int n )
{
    unordered_set <int> Set;

    for ( int i = 1; i <= n; ++i )
    {
        /// dobor pionul i
        Set.insert( grundy[i - 1] ^ grundy[n - i] );

        /// dobor pionii i,i+1
        if ( i + 1 <= n )
            Set.insert( grundy[i - 1] ^ grundy[n - i - 1] );
    }

    int sol = 0;

    while ( Set.find( sol ) != Set.end() )
        sol++;

    return sol;
}

int value_grundy( int n )
{
    if ( n <= 72 )
        return grundy[n];
    else
        return grundy[72 + ( n - 72 ) % 12];
}

int sprague_grundy( vector<int>& nimbers )
{
    int sol = 0;

    for ( auto x: nimbers )
    {
        sol ^= value_grundy( x );
    }

    return sol;
}

int main()
{
    FIN("bowling.in");
    FOUT("bowling.out");

    grundy[0] = 0;

    for ( int i = 1; i < 84; ++i )
        grundy[i] = mex( i );

    read( T );

    while ( T-- )
    {
        read( N );

        for ( int i = 1; i <= N; ++i )
            read( query[i] );

        VI nimbers;

        int contor = 0;
        query[N + 1] = 0;

        for ( int i = 1; i <= N + 1; ++i )
            if ( query[i] == 0 )
            {
                if ( contor )
                {
                    nimbers.pb( contor );
                    contor = 0;
                }
            }
            else
                contor++;

        if ( sprague_grundy( nimbers ) )
            cout << "Nargy\n";
        else
            cout << "Fumeanu\n";
    }

    return 0;
}
