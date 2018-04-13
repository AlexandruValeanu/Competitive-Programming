#include <bits/stdc++.h>

using namespace std;

/**
    Name: Acrostic Twins

    Description: A move is to turn over two coins, either in the same row or
                 the same column, with the southeast coin going from heads to tails.

    Strategy:

        g(x, y) = mex { g(x, b), g(a, y) : 0≤b<y, 0≤a<x };
        g(x, y) = x ^ y;
**/

const int Nmax = 100;

int grundy[Nmax][Nmax];

int mex( int x, int y )
{
    if ( grundy[x][y] != -1 )
        return grundy[x][y];

    if ( x == 0 && y == 0 )
        return grundy[x][y] = 0;

    unordered_set <int> Set;

    for ( int i = 0; i < y; i++ )
        Set.insert( mex( x, i ) );

    for ( int i = 0; i < x; ++i )
        Set.insert( mex( i, y ) );

    grundy[x][y] = 0;

    while ( Set.count( grundy[x][y] ) )
        grundy[x][y]++;

    return grundy[x][y];
}

int main()
{
    memset( grundy, -1, sizeof( grundy ) );

    for ( int i = 0; i <= 9; ++i, cout << endl )
        for ( int j = 0; j <= 9; ++j )
            cout << mex( i, j ) << " ";

    return 0;
}
