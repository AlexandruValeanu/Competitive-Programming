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

const int Nmax = 1e4 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

unordered_map <string, int> UM;
int G[20];
string s[20];
int N, M, P;

int main()
{
    ///FIN("data.in");

    cin >> N >> M;

    for ( int i = 0; i < N; ++i )
    {
        cin >> s[i];

        if ( !UM[  s[i] ] ) UM[  s[i] ] = P++;
    }

    for ( int i = 1; i <= M; ++i )
    {
        string a, b;

        cin >> a >> b;

        G[ UM[a] ] |= ( 1 << UM[b] );
        G[ UM[b] ] |= ( 1 << UM[a] );
    }

    int sol = -INF;
    int state = -1;

    for ( int i = 0; i < ( 1 << N ); ++i )
    {
        if ( popcount( i ) < sol ) continue;

        int valid = 1;

        for ( int j = 0; j < N; ++j )
            if ( bit( i, j ) && ( i & G[j] ) != 0 )
                valid = 0;

        if ( valid )
        {
            if ( popcount( i ) > sol )
            {
                sol = popcount( i );
                state = i;
            }
        }
    }

    set <string> S;

    cout << sol << "\n";

    for ( int j = 0; j < N; ++j )
        if ( bit( state, j ) )
            S.insert( s[j] );

    for ( auto x: S )
        cout << x << "\n";

    return 0;
}
