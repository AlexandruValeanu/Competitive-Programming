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

const int Nmax = 2e5 + 1;
const int Tmax = 2e4 + 1;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int A[Nmax];
int apart[Tmax];
int pos[Tmax];

int N, T;

int valid( int lg )
{
    ms( pos, 0 );

    int number = 0;

    for ( int i = 1; i <= N; ++i )
    {
        if ( apart[ A[i] ] && pos[ A[i] ] == 0 )
            number++;

        if ( apart[ A[i] ] )
            pos[ A[i] ] = i;

        if ( i - lg >= 1 )
        {
            if ( apart[ A[i - lg] ] && pos[ A[i - lg] ] <= i - lg )
                pos[ A[i - lg] ] = 0,
                number--;

            if ( number == T )
                return 1;
        }
    }

    return 0;
}

int cauta()
{
    int st = T, dr = N, m, gasit = N;

    while ( st <= dr )
    {
        m = ( st + dr ) / 2;

        if ( valid( m ) )
        {
            gasit = m;
            dr = m - 1;
        }
        else
        {
            st = m + 1;
        }
    }

    return gasit;
}

int main()
{
    FIN("panouri.in");
    FOUT("panouri.out");

    read( N ); read( T );

    for ( int i = 1; i <= N; ++i )
        read( A[i] );

    for ( int i = 1, a; i <= T; ++i )
    {
        read( a );
        apart[a] = 1;
    }

    cout << cauta() - 1 << "\n";

    return 0;
}
