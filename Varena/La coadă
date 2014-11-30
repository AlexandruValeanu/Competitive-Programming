#include <bits/stdc++.h>

using namespace std;

const int BS = ( 1 << 10 );
char buffer[BS];
int position = BS;

inline char GetChar( FILE *&f )
{
    if ( position == BS )
    {
        position = 0;
        fread( buffer, BS, 1, f );
    }

    return buffer[ position++ ];
}

inline void read( int &a, FILE *&f )
{
    register char ch;
    a = 0;
    int sign = 1;

    do
    {
        ch = GetChar( f );

    } while ( !isdigit( ch ) && ch != '-' );

    if ( ch == '-' )
    {
        sign = -1;
        ch = GetChar( f );
    }

    do
    {
        a = a * 10 + ch - '0';
        ch = GetChar( f );

    } while( isdigit( ch ) );

    a *= sign;
}

unsigned short HashTable[560000 + 1];

const int Nmax = 60000;
const int nil = 0;

unsigned short urm[Nmax + 1];
unsigned short prec[Nmax + 1];
int valuePos[Nmax + 1];
unsigned short freePos[Nmax + 1];
int N, K, prim, last, nrFree;

void adauga( const int value, const unsigned short pos )
{
    HashTable[value] = pos;
}

void sterge( const int value )
{
    HashTable[value] = 0;
}

unsigned short cauta( const int value )
{
    return HashTable[value];
}

void initialize()
{
    for ( int i = 1; i <= N; ++i )
    {
        valuePos[i] = i;
        adauga( i, i );
    }

    for ( int i = 2; i < N; ++i )
    {
        prec[i] = i - 1;
        urm[i] = i + 1;
    }

    urm[1] = 2;
    prec[1] = nil;

    urm[N] = nil;
    prec[N] = N - 1;

    prim = 1; last = N;
    nrFree = 0;
}

int main()
{
    FILE *f = fopen("lacoada.in", "r");

    read( N, f ); read( K, f );

    initialize();
    int persoana = N;
    int nrInQueue = N;

    while ( K-- )
    {
        int tip, x;

        read( tip, f );

        if ( tip == 3 )
        {
            read( x, f );

            int p = cauta( x );

            if ( p != prim )
            {
                if ( p == last )
                {
                    int u = prec[p];

                    urm[u] = nil;
                    last = u;

                    urm[p] = prim;
                    prec[prim] = p;
                    prec[p] = nil;
                    prim = p;
                }
                else
                {
                    int u1 = prec[p];
                    int u2 = urm[p];

                    urm[u1] = u2;
                    prec[u2] = u1;

                    urm[p] = prim;
                    prec[prim] = p;
                    prec[p] = nil;
                    prim = p;
                }
            }
        }
        else
        {
            if ( tip == 1 )
            {
                nrInQueue--;
                sterge( valuePos[prim] );

                freePos[ ++nrFree ] = prim;

                int u = urm[prim];

                if ( u == nil )
                {
                    prec[prim] = urm[prim] = nil;
                    prim = last = nil;
                }
                else
                {
                    prec[u] = nil;
                    prim = u;
                }
            }
            else
            {
                nrInQueue++;
                persoana++;

                int p = freePos[ nrFree-- ];

                valuePos[p] = persoana;
                adauga( persoana, p );

                if ( prim == nil )
                {
                    prim = last = p;
                    prec[p] = urm[p] = nil;
                }
                else
                {
                    prec[p] = last;
                    urm[last] = p;
                    urm[p] = nil;
                    last = p;
                }
            }
        }
    }

    FILE *g = fopen("lacoada.out", "w");

    fprintf(g,"%d\n", nrInQueue);

    int p = prim;

    while ( p )
    {
        fprintf(g,"%d ", valuePos[p]);
        p = urm[p];
    }

    return 0;
}
