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

const int Nmax = 1e4 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

#define Point pp
#define x first
#define y second

Point points[Nmax];
int N;

int dist( Point A, Point B )
{
    return ( A.x - B.x ) * ( A.x - B.x ) + ( A.y - B.y ) * ( A.y - B.y );
}

int cmp( Point A, Point B )
{
    return dist( A, Point( 0, 0 ) ) > dist( B, Point( 0, 0 ) );
}

int n, r;

int solution;
int st[Nmax];
int answer[Nmax];

void bkt( int k, int ind, int local )
{
    if ( ind > N ) return;

    if ( k > n )
    {
        if ( local > solution )
        {
            solution = local;

            for ( int i = 1; i <= n; ++i )
                answer[i] = st[i];
        }
    }
    else
    {
        bkt( k, ind + 1, local );
        st[k] = ind;

        int ans = 0;

        for ( int i = 1; i < k; ++i )
            ans += dist( points[ st[i] ], points[ st[k] ] );

        bkt( k + 1, ind, local + ans );
    }
}

int main()
{
    cin >> n >> r;

    for ( int i = -r; i <= r; ++i )
        for ( int j = -r; j <= r; ++j )
            if ( dist( Point( i, j ), Point( 0, 0 ) ) <= r * r )
                points[ ++N ] = Point( i, j );

    sort( points + 1, points + N + 1, cmp );

    N = min( 36, N );

    ///cout << N << "\n";

    bkt( 1, 1, 0 );

    cout << solution << "\n";

    for ( int i = 1; i <= n; ++i )
        cout << points[ answer[i] ].x << " " << points[ answer[i] ].y << "\n";

    return 0;
}
