#include <bits/stdc++.h>

using namespace std;

///---------------------------------

const int BS = ( 1 << 16 );
char buffer[BS];
int position = BS;

inline char getChar()
{
    if ( position == BS )
    {
        position = 0;
        fread( buffer, BS, 1, stdin );
    }

    return buffer[ position++ ];
}

inline int getNr()
{
    int a = 0;
    char ch;

    do
    {
        ch = getChar();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getChar();

    } while ( isdigit( ch ) );

    return a;
}

///--------------------------------------

const int Nmax = 100000 + 1;

bool vis[Nmax];
int postordine[Nmax], apart[Nmax];
int grad_in[Nmax];

int lista[3 * Nmax], urm[3 * Nmax], vecini[3 * Nmax], contor;
int listaT[3 * Nmax], urmT[3 * Nmax], veciniT[3 * Nmax], contorT;

int N, M, nrCTC, P;

void addEdge( int lista[], int urm[], int vecini[], int &contor, int x, int y )
{
    contor++;
    lista[contor] = y;
    urm[contor] = vecini[x];
    vecini[x] = contor;
}

void DFS( int nod )
{
    vis[nod] = 1;

    int p = vecini[nod];

    while ( p )
    {
        int n = lista[p];

        if ( !vis[n] )
            DFS( n );

        p = urm[p];
    }

    postordine[ ++P ] = nod;
}

void DFST( int nod )
{
    vis[nod] = 0;

    int p = veciniT[nod];

    while ( p )
    {
        int n = listaT[p];

        if ( vis[n] )
            DFST( n );

        p = urmT[p];
    }

    apart[nod] = nrCTC;
}

void tare_con()
{
    for ( int i = 1; i <= N; ++i )
        if ( !vis[i] )
            DFS( i );

    for ( int i = P; i >= 1; i-- )
        if ( vis[ postordine[i] ] )
        {
            nrCTC++;
            DFST( postordine[i] );
        }
}

void build_dag()
{
    for ( int i = 1; i <= N; ++i )
    {
        int p = vecini[i];

        while ( p )
        {
            if ( apart[ i ] != apart[ lista[p] ] )
                grad_in[ apart[ lista[p] ] ]++;

            p = urm[p];
        }
    }

    vector <int> sol;
    int EXIST_SOL = 0;

    for ( int i = 1; i <= nrCTC; ++i )
        if ( grad_in[i] == 0 )
        {
            EXIST_SOL++;

            for ( int j = 1; j <= N; ++j )
                if ( apart[j] == i )
                    sol.push_back( j );

            if ( EXIST_SOL == 2 )
                i = nrCTC + 1;
        }

    if ( EXIST_SOL == 1 )
    {
        cout << sol.size() << "\n";

        for ( unsigned i = 0; i < sol.size(); ++i )
            cout << sol[i] << "\n";
    }
    else
    {
        cout << "0\n";
    }
}

int main()
{
    freopen("matroid.in", "r", stdin);
    freopen("matroid.out", "w", stdout);

    N = getNr(); M = getNr();

    while ( M-- )
    {
        int a, b;

        a = getNr(); b = getNr();

        addEdge( lista, urm, vecini, contor, a, b );
        addEdge( listaT, urmT, veciniT, contorT, b, a );
    }

    tare_con();
    build_dag();

    return 0;
}
