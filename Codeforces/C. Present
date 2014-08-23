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

const int LgMax = log2(Nmax) + 1;

using namespace std;

long long lazy[4 * Nmax];
long long minim[4 * Nmax];
int position[4 * Nmax];
int v[Nmax];

void init( int nod, int st, int dr )
{
    if ( st == dr )
    {
        minim[nod] = v[st];
        position[nod] = st;
    }
    else
    {
        int m = ( st + dr ) / 2;

        init( 2 * nod, st, m );
        init( 2 * nod + 1, m + 1, dr );

        if ( minim[2 * nod] <= minim[2 * nod + 1] )
        {
            minim[nod] = minim[2 * nod];
            position[nod] = position[2 * nod];
        }
        else
        {
            minim[nod] = minim[2 * nod + 1];
            position[nod] = position[2 * nod + 1];
        }
    }
}

void update( int nod, int st, int dr, int st_q, int dr_q, int value )
{
    if ( st_q <= st && dr <= dr_q )
    {
        minim[nod] += value;
        lazy[nod] += value;
    }
    else
    {
        lazy[2 * nod] += lazy[nod];
        lazy[2 * nod + 1] += lazy[nod];

        minim[2 * nod] += lazy[nod];
        minim[2 * nod + 1] += lazy[nod];

        lazy[nod] = 0;

        int m = ( st + dr ) / 2;

        if ( st_q <= m ) update( 2 * nod, st, m, st_q, dr_q, value );
        if ( m < dr_q ) update( 2 * nod + 1, m + 1, dr, st_q, dr_q, value );

        if ( minim[2 * nod] <= minim[2 * nod + 1] )
        {
            minim[nod] = minim[2 * nod];
            position[nod] = position[2 * nod];
        }
        else
        {
            minim[nod] = minim[2 * nod + 1];
            position[nod] = position[2 * nod + 1];
        }
    }
}

pair<long long, int> query()
{
    return pair<long long, int>( minim[1], position[1] );
}

int N, M, W;

int main()
{
    ///FIN("data.in");

    cin >> N >> M >> W;

    for ( int i = 1, a; i <= N; ++i )
    {
        cin >> v[i];
    }

    init( 1, 1, N );

    for ( int i = 1; i <= M; ++i )
    {
        pair<long long, int> sol = query();

        int st = sol.second;
        int dr = min( N, sol.second + W - 1 );

        update( 1, 1, N, st, dr, 1 );
    }

    cout << query().first << "\n";

    return 0;
}
