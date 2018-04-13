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

    do
    {
        ch = getchar();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar();

    } while( isdigit( ch ) );
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

const int Nmax = 1e3 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int A[Nmax][Nmax];
int P[Nmax][Nmax];
int st[Nmax], dr[Nmax];
int N, M, sol;

void Manacher( int ind )
{
    int indx = 0, mx = 0;

    for ( int i = 1; i <= M; ++i )
    {
        if ( mx >= i )
            P[ind][i] = min( P[ind][2 * indx - i], mx - i );

        while ( i - P[ind][i] - 1 >= 0 && i + P[ind][i] + 1 <= M &&
                A[ind][ i - P[ind][i] - 1 ] == A[ind][ i + P[ind][i] + 1 ]
              )
                P[ind][i]++;

        if ( i + P[ind][i] > mx )
        {
            mx = i + P[ind][i];
            indx = i;
        }
    }
}

void solve()
{
    stack <int> S;

    for ( int j = 1; j <= M; ++j )
    {
        for ( int i = 1; i <= N; ++i )
        {
            while ( S.size() && P[ S.top() ][j] >= P[i][j] )
            {
                dr[ S.top() ] = i - 1;
                S.pop();
            }

            if ( S.size() == 0 )
                st[i] = 1;
            else
                st[i] = S.top() + 1;

            S.push( i );
        }

        while ( S.size() )
        {
            dr[ S.top() ] = N;
            S.pop();
        }

        for ( int i = 1; i <= N; ++i )
            sol = max( sol, ( 2 * P[i][j] + 1 ) * ( dr[i] - st[i] + 1 ) );
    }
}

int main()
{
    FIN("dreptpal.in");
    FOUT("dreptpal.out");

    read( N ); read( M );

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            read( A[i][j] );

    for ( int i = 1; i <= N; ++i )
        Manacher( i );

    solve();

    printf("%d\n", sol);

    return 0;
}
