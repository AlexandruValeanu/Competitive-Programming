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

const int Nmax = 5e1 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

char A[Nmax][Nmax];
int rows[Nmax];
int column[Nmax];
int indice[Nmax];

int T, N, M;

int main()
{
    ///FIN("data.in");
    ///FOUT("data.out");

    read( T );

    while ( T-- )
    {
        read( N ); read( M );

        for ( int i = 1; i <= N; ++i )
            scanf("%s\n", A[i] + 1);

        VII laser;

        for ( int i = 1; i <= N; ++i )
            for ( int j = 1; j <= M; ++j )
                if ( A[i][j] == 'L' )
                    laser.pb( pp( i, j ) );

        const int nrLaser = laser.size();

        int solution = 0;

        for ( int i = 0; i < ( 1 << nrLaser ); ++i )
        {
            ms( rows, 0 );
            ms( column, 0 );
            ms( indice, 0 );

            for ( int j = 0; j < nrLaser; ++j )
            {
                if ( bit( i, j ) )
                {
                    column[ laser[j].se ] = max( column[ laser[j].se ], laser[j].fi );
                }
                else
                {
                    rows[ laser[j].fi ]++;
                    indice[ laser[j].fi ] = j;
                }
            }

            int valid = 1;

            for ( int j = 1; j <= N && valid; ++j )
            {
                if ( rows[j] == 0 )
                {
                    for ( int k = 1; k <= M; ++k )
                    {
                        if ( A[j][k] == 'E' && column[k] < j )
                            valid = 0;
                    }
                }

                if ( rows[j] == 1 )
                {
                    int stanga = 0;
                    int dreapta = 0;

                    int ind = indice[j];

                    int x = laser[ind].fi;
                    int y = laser[ind].se;

                    for ( int k = y - 1; k >= 1; k-- )
                        if ( A[j][k] == 'E' && column[k] < j )
                            stanga++;

                    for ( int k = y + 1; k <= M; ++k )
                        if ( A[j][k] == 'E' && column[k] < j )
                            dreapta++;

                    if ( stanga && dreapta )
                        valid = 0;
                }
            }

            if ( valid )
            {
                solution = 1;
                break;
            }
        }

        if ( solution )
            puts("Possible");
        else
            puts("Impossible");
    }

    return 0;
}
