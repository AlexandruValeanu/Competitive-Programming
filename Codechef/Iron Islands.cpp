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

const int SIZE = ( 1 << 20 );
char buffer[SIZE];
int cursor = SIZE;

inline char getChar()
{
    if ( cursor == SIZE )
    {
        cursor = 0;
        fread( buffer, SIZE, 1, stdin );
    }

    return buffer[ cursor++ ];
}

inline char findCharacter()
{
    char ch = getChar();

    while ( !isdigit( ch ) )
    {
        ch = getChar();
    }

    return ch;
}

inline void read( int &a )
{
    register char ch;
    a = 0;
    int sign = 1;

    do
    {
        ch = getChar();

    } while ( !isdigit( ch ) && ch != '-' );

    if ( ch == '-' )
    {
        sign = -1;
        ch = getChar();
    }

    do
    {
        a = a * 10 + ch - '0';
        ch = getChar();

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

const int Nmax = 1000 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

class Bitmask
{
public:

    unsigned bits[32];

    Bitmask()
    {
        ms( bits, 0 );
    }

    void flip( int pos )
    {
        bits[ pos >> 5 ] ^= ( 1ul << ( (unsigned) pos & 31ul ) );
    }

    int get_first_bit()
    {
        int result = 0;

        for ( int i = 0; i < 32; i++, result += 32 )
        {
            if ( bits[i] )
            {
                unsigned current_bit = 0;

                while( !( bits[i] & ( 1ul << (unsigned)current_bit ) ) ) current_bit++;

                return result + (int)current_bit;
            }
        }

        return -1;
    }
};

Bitmask operator + ( Bitmask a, Bitmask b )
{
    Bitmask c;

    for ( int i = 0; i < 32; ++i )
        c.bits[i] = a.bits[i] & b.bits[i];

    return c;
}

Bitmask G[Nmax];

char str[Nmax];
int dist[Nmax];
int coada[Nmax];

int T, N, Q, V, M;

void BFS( int V )
{
    for ( int i = 0; i < N; ++i )
    {
        dist[i] = INF;
    }

    int st = 1, dr = 1;

    dist[V] = 0;
    coada[ st ] = V;

    Bitmask unvisited;

    for ( int i = 0; i < N; ++i )
        unvisited.flip( i );

    unvisited.flip( V );

    while ( st <= dr )
    {
        int nod = coada[ st++ ];

        Bitmask vecini = G[nod] + unvisited;

        while( 1 )
        {
            int x = vecini.get_first_bit();

            if ( x == -1 ) break;

            dist[x] = dist[nod] + 1;
            coada[ ++dr ] = x;
            vecini.flip( x );
            unvisited.flip( x );
        }
    }

}

int main()
{
    ///FIN("data.in");

    read( T );

    while ( T-- )
    {
        read( N );

        ms( G, 0 );

        for ( int i = 0; i < N; ++i )
        {
            for ( int j = 0; j < N; ++j )
            {
                if ( findCharacter() == '1' )
                    G[i].flip( j );
            }
        }

        read( Q );

        while ( Q-- )
        {
            read( V ); read( M );
            V--;

            while ( M-- )
            {
                int a, b;

                read( a ); read( b );
                a--; b--;

                G[a].flip( b );
            }

            BFS( V );
            int sum = 0;

            for ( int i = 0; i < N; ++i )
                if ( dist[i] != INF )
                    sum += dist[i];

            printf("%d\n", sum);
        }
    }

    return 0;
}
