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

class Point
{
public:

    int x, y;

    Point() : x(0), y(0) {}

    Point(const int _x, const int _y) : x(_x), y(_y) {}

    bool operator < ( const Point &P ) const
    {
        if ( y != P.y )
            return y < P.y;
        else
            return x < P.x;
    }

    bool operator == ( const Point &P ) const
    {
        return ( x == P.x ) && ( y == P.y );
    }

    long long distanceToPoint( const Point &P ) const
    {
        return  ( 1.0 * ( x - P.x ) * ( x - P.x ) + 1.0 * ( y - P.y ) * ( y - P.y ) );
    }

    friend istream& operator >> ( istream &stream, Point &P )
    {
        stream >> P.x >> P.y;
        return stream;
    }

    friend ostream& operator << ( ostream &stream, const Point &P )
    {
        stream << P.x << " " << P.y;
        return stream;
    }
};

Point rotatie( Point p, Point o )
{
    Point A = p;

    A.x -= o.x;
    A.y -= o.y;

    int auxX = -A.y;
    int auxY = A.x;

    A.x = auxX;
    A.y = auxY;

    A.x += o.x;
    A.y += o.y;

    return A;
}

const double SQRT2 = 1.4142135623;

const int N = 4;
Point P[N], O[N], A[N];
int st[N];

int best;
long long d[N * N + N];

bool check()
{
    int ind = 0;

    for ( int i = 0; i < N; ++i )
        for ( int j = i + 1; j < N; ++j )
            if ( A[i] == A[j] )
                return false;
            else
            {
                d[ ++ind ] = A[i].distanceToPoint( A[j] );
            }

    sort( d + 1, d + ind + 1 );

    int diferite = 1;
    long long last = d[1];

    for ( int i = 2; i <= ind; ++i )
    {
        if ( d[i] == last )
            continue;

        diferite++;
        last = d[i];

        if ( diferite > 2 )
            return false;
    }

    return ( diferite == 2 );
}

void bkt( int k )
{
    if ( k == N )
    {
        int suma = 0;

        for ( int i = 0; i < N; ++i )
        {
            int aux = st[i];
            suma += aux;
            A[i] = P[i];

            while ( aux-- )
            {
                A[i] = rotatie( A[i], O[i] );
            }
        }

        if ( check() )
            best = min( best, suma );
    }
    else
    {
        for ( int i = 0; i < 4; ++i )
        {
            st[k] = i;
            bkt( k + 1 );
        }
    }
}

int solve()
{
    best = INF;

    bkt( 0 );

    if ( best == INF )
        return -1;
    else
        return best;
}

int main()
{
    ///FIN("data.in");
    ///FOUT("data.out");

    int n;
    cin >> n;

    while ( n-- )
    {
        for ( int i = 0; i < N; ++i )
            cin >> P[i] >> O[i];

        cout << solve() << "\n";
    }

    return 0;
}
