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

const int Nmax = 20 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int grundy[Nmax][Nmax][Nmax][Nmax];
int L[Nmax][Nmax], R[Nmax][Nmax];
int T[Nmax][Nmax], B[Nmax][Nmax];
char A[Nmax][Nmax];

int tests, N, M;

int mex( int x1, int y1, int x2, int y2 )
{
    if ( grundy[x1][y1][x2][y2] != -1 )
        return grundy[x1][y1][x2][y2];

    if ( x1 > x2 || y1 > y2 )
        return grundy[x1][y1][x2][y2] = 0;

    unordered_set <int> Set;

    for ( int i = x1; i <= x2; ++i )
        for ( int j = y1; j <= y2; ++j )
        {
            if ( min( min( L[i][j], R[i][j] ), min( T[i][j], B[i][j] ) ) >= 3 )
            {
                int a1 = mex( x1, y1, i - 1, j - 1 );
                int a2 = mex( i + 1, y1, x2, j - 1 );
                int a3 = mex( x1, j + 1, i - 1, y2 );
                int a4 = mex( i + 1, j + 1, x2, y2 );

                Set.insert( a1 ^ a2 ^ a3 ^ a4 );
            }
        }

    grundy[x1][y1][x2][y2] = 0;

    while ( Set.count( grundy[x1][y1][x2][y2] ) )
        grundy[x1][y1][x2][y2]++;

    return grundy[x1][y1][x2][y2];
}

int main()
{
    ///FIN("data.in");
    ///FOUT("data.out");

    cin >> tests;

    while ( tests-- )
    {
        ms( grundy, -1 );
        ms( L, 0 ); ms( R, 0 );
        ms( T, 0 ); ms( B, 0 );

        cin >> N >> M;

        for ( int i = 1; i <= N; ++i )
            cin >> ( A[i] + 1 );

        for ( int i = 1; i <= N; ++i )
        {
            for ( int j = 1; j <= M; ++j )
                if ( A[i][j] == '#' )
                    L[i][j] = 0;
            else
                    L[i][j] = 1 + L[i][j - 1];

            for ( int j = M; j >= 1; j-- )
                if ( A[i][j] == '#' )
                    R[i][j] = 0;
                else
                    R[i][j] = 1 + R[i][j + 1];
        }

        for ( int j = 1; j <= M; ++j )
        {
            for ( int i = 1; i <= N; ++i )
                if ( A[i][j] == '#' )
                    T[i][j] = 0;
                else
                    T[i][j] = 1 + T[i - 1][j];

            for ( int i = N; i >= 1; i-- )
                if ( A[i][j] == '#' )
                    B[i][j] = 0;
                else
                    B[i][j] = 1 + B[i + 1][j];
        }

        if ( mex( 1, 1, N, M ) )
            cout << "Asuna\n";
        else
            cout << "Kirito\n";
    }

    return 0;
}
