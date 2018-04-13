#include <bits/stdc++.h>

using namespace std;

///---------------------------------

const int BS = ( 1 << 16 );
char buffer[BS];
int position = BS;

inline char getChar( FILE *f )
{
    if ( position == BS )
    {
        position = 0;
        fread( buffer, BS, 1, f );
    }

    return buffer[ position++ ];
}

inline int getNr( FILE *f )
{
    int a = 0;
    char ch;

    do
    {
        ch = getChar( f );

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getChar( f );

    } while ( isdigit( ch ) );

    return a;
}

///--------------------------------------

const int Nmax = 100000 + 1;

typedef struct
{
    int nod;
    int urm;

} lista;

lista G[2 * Nmax];
int vecini[Nmax];

int tata[Nmax];
int dist[Nmax];
int coada[Nmax];

int N, M;

void addEdge( int x, int y )
{
    M++;
    G[M].nod = y;
    G[M].urm = vecini[x];
    vecini[x] = M;
}

int BFS( int nod )
{
    memset( tata, 0, sizeof( tata ) );

    int st, dr;

    coada[st = dr = 1] = nod;
    dist[nod] = 0;
    tata[nod] = nod;

    while ( st <= dr )
    {
        nod = coada[ st++ ];

        for ( int p = vecini[nod]; p != 0; p = G[p].urm )
        {
            int vecin = G[p].nod;

            if ( !tata[vecin] )
            {
                tata[vecin] = nod;
                dist[vecin] = dist[nod] + 1;

                coada[ ++dr ] = vecin;
            }
        }
    }

    int p = 0;

    for ( int i = 1; i <= N; ++i )
        if ( dist[i] > dist[p] )
            p = i;

    return p;
}

int main()
{
    FILE *f = fopen("diametru.in", "r");
    FILE *g = fopen("diametru.out", "w");

    N = getNr( f );

    for ( int i = 1, a, b; i < N; ++i )
    {
        a = getNr( f ); b = getNr( f );

        addEdge( a, b );
        addEdge( b, a );
    }

    int nodInceput = BFS( 1 );
    int nodFinal = BFS( nodInceput );

    fprintf(g, "%d\n", dist[nodFinal]);

    int aux = nodFinal;

    while ( aux != nodInceput )
    {
        fprintf(g, "%d ", aux);
        aux = tata[aux];
    }

    fprintf(g, "%d\n", nodInceput);

    return 0;
}
