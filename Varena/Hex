#include <bits/stdc++.h>

using namespace std;

const int dl[] = { -1, -1, 0, 0, 1, 1 };
const int dc[] = { 0, 1, -1, 1, -1, 0 };

const int Nmax = 500;

int tata[2][Nmax * Nmax + 1];
char type[2][Nmax * Nmax + 1];
char apart[Nmax + 1][Nmax + 1];

int N, NN;

int Find( int player, int x )
{
    if ( x != tata[player][x] )
        return tata[player][x] = Find( player, tata[player][x] );
    else
        return x;
}

int Union( int player, int x, int y )
{
    if ( rand() % 2 == 0 )
        tata[player][x] = y;
    else
        tata[player][y] = x;

    type[player][x] |= type[player][y];
    type[player][y] |= type[player][x];

    return ( type[player][x] == 3 );
}

void init()
{
    srand( time( NULL ) );

    memset( type, 0, sizeof( type ) );
    memset( apart, 0, sizeof( apart ) );

    for ( int i = 1; i <= N * N; ++i )
        tata[0][i] = tata[1][i] = i;

    for ( int i = 1; i <= N; ++i )
    {
        type[1][ ( i - 1 ) * N + 1 ] = 1;
        type[1][ ( i - 1 ) * N + N ] = 2;
    }

    for ( int i = 1; i <= N; ++i )
    {
        type[0][i] = 1;
        type[0][ ( N - 1 ) * N + i ] = 2;
    }
}

int valid( int player, int x, int y )
{
    return ( 1 <= x && x <= N && 1 <= y && y <= N && apart[x][y] == player + 1 );
}

int main()
{
    ifstream in("hex.in");
    ofstream out("hex.out");

    in >> N;

    init();

    for ( int i = 1; i <= N * N; ++i )
    {
        int a, b;

        in >> a >> b;

        apart[a][b] = ( i & 1 ) + 1;

        int stop = 0;

        for ( int k = 0; k < 6; ++k )
        {
            int x = a + dl[k];
            int y = b + dc[k];

            if ( valid( ( i & 1 ), x, y ) )
            {
                int fx = Find( i & 1, N * ( x - 1 ) + y );
                int fy = Find( i & 1, N * ( a - 1 ) + b );

                if ( fx != fy )
                {
                    stop |= Union( i & 1, fx, fy );
                }
            }
        }

        if ( stop )
        {
            out << i << "\n";
            i = N * N + 1;
        }
    }

    in.close();
    out.close();

    return 0;
}
