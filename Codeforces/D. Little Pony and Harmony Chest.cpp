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

const int Nmax = 1e2 + 2;
const int Pmax = 16;
const int PP = 1 << Pmax;
const int Vmax = 60;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int b[Pmax] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 };

int dp[Nmax][PP];
int dad[Nmax][PP];
int value[Nmax][PP];
int A[Nmax], B[Nmax];
int mask[Vmax];
int N;

int main()
{
    ///FIN("data.in");
    ///FOUT("data.out");

    cin >> N;

    for ( int i = 0; i < N; ++i )
        cin >> A[i];

    for ( int i = 1; i < Vmax; ++i )
        for ( int j = 0; j < Pmax; ++j )
            if ( i % b[j] == 0 )
                mask[i] |= ( 1 << j );

    for ( int i = 0; i <= N; ++i )
        for ( int j = 0; j < PP; ++j )
            dp[i][j] = INF;

    dp[0][0] = 0;

    for ( int i = 0; i < N; ++i )
    {
        for ( int state = 0; state < PP; ++state )
        {
            for ( int val = 1; val < Vmax; ++val )
            {
                if ( ( state & mask[val] ) == 0 )
                {
                    if ( dp[i + 1][state | mask[val]] > dp[i][state] + abs( A[i] - val ) )
                    {
                        dp[i + 1][state | mask[val]] = dp[i][state] + abs( A[i] - val );
                        dad[i + 1][state | mask[val]] = state;
                        value[i + 1][state | mask[val]] = val;
                    }
                }
            }
        }
    }

    int minim = INF;
    int pos = -1;

    for ( int state = 0; state < PP; ++state )
    {
        if ( dp[N][state] < minim )
        {
            minim = dp[N][state];
            pos = state;
        }
    }

    for ( int i = N; i >= 1; i-- )
    {
        int stare = dad[i][pos];
        int val = value[i][pos];

        B[i - 1] = val;

        pos = stare;
    }

    for ( int i = 0; i < N; ++i )
        cout << B[i] << " ";

    return 0;
}
