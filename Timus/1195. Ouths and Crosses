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

const int Nmax = 3;

const int LgMax = log2(Nmax) + 1;

using namespace std;

char moves[] = { 'X', 'O' };

char X[Nmax + 2][Nmax + 2];

void refaTabla( int table, int liber )
{
    for ( int i = 0; i < Nmax; ++i )
        for ( int j = 0; j < Nmax; ++j )
        {
            int x = i * Nmax + j;

            if ( liber & ( 1 << x ) )
                X[i][j] = '#';
            else
            {
                if ( table & ( 1 << x ) )
                    X[i][j] = 'X';
                else
                    X[i][j] = 'O';
            }
        }
}

int stareFinala( int table, int liber, int player )
{
    refaTabla( table, liber );

    for ( int i = 0; i < Nmax; ++i )
    {
        int valid = 1;

        for ( int j = 0; j < Nmax; ++j )
            if ( X[i][j] != X[i][0] )
                valid = 0;

        if ( valid )
        {
            if ( X[i][0] == moves[player] && X[i][0] != '#' )
                return 1;
            else
                return -1;
        }
    }

    for ( int j = 0; j < Nmax; ++j )
    {
        int valid = 1;

        for ( int i = 0; i < Nmax; ++i )
            if ( X[0][j] != X[i][j] )
                valid = 0;

        if ( valid )
        {
            if ( X[0][j] == moves[player] && X[0][j] != '#' )
                return 1;
            else
                return -1;
        }
    }

    int valid = 0;

    if ( X[0][0] == X[1][1] && X[1][1] == X[2][2] && X[0][0] != '#' )
        valid = 1;

    if ( valid )
    {
        if ( X[0][0] == moves[player] )
            return 1;
        else
            return -1;
    }

    valid = 0;

    if ( X[0][2] == X[1][1] && X[1][1] == X[2][0] && X[0][2] != '#' )
        valid = 1;

    if ( valid )
    {
        if ( X[0][2] == moves[player] )
            return 1;
        else
            return -1;
    }

    for ( int i = 0; i < Nmax; ++i )
        for ( int j = 0; j < Nmax; ++j )
            if ( X[i][j] == '#' )
                return 2;

    return 0;
}

int min_max( int table, int liber, int player )
{
    int sol = -1;

    for ( int i = 0; i < Nmax; ++i )
        for ( int j = 0; j < Nmax; ++j )
            if ( liber & ( 1 << ( i * Nmax + j ) ) )
            {
                int x = i * Nmax + j;
                int auxTable = table ^ ( ( 1 << x ) * ( 1 - player ) );
                int auxLiber = liber ^ ( 1 << x );

                int auxSF = stareFinala( auxTable, auxLiber, player );

                if ( auxSF == 2 )
                {
                    int aux = min_max( auxTable, auxLiber, player ^ 1 );

                    sol = max( sol, -aux ) ;
                }
                else
                {
                    return auxSF;
                }

            }

    return sol;
}

int main()
{
    ///FIN("data.in");
   /// FOUT("data.out");

    for ( int i = 0; i < Nmax; ++i )
        cin >> X[i];

    int tabla = 0;
    int liber = ( 1 << 9 ) - 1;

    for ( int i = 0; i < Nmax; ++i )
        for ( int j = 0; j < Nmax; ++j )
            if ( X[i][j] != '#' )
            {
                int x = i * Nmax + j;
                liber ^= ( 1 << x );
                tabla ^= ( 1 << x ) * ( X[i][j] == 'X' );
            }

    int state = min_max( tabla, liber, 0 );

    if ( state == 1 )
        cout << "Crosses win";

    if ( state == 0 )
        cout << "Draw";

    if ( state == -1 )
        cout << "Ouths win";

    return 0;
}
