#include <bits/stdc++.h>

using namespace std;

/**
    Name: Rugs = Ruler × Ruler

    Description: A move in Rugs is to turn over all coins in any rectangular block of coins.

    Strategy: From "The Tartan Theorem" having the SG function g1 for Ruler
              the SG function for Rugs is g(x,y) = g1(x) x g1(y) (the Nim Multiplication)
**/

const int Nmax = 100;

int table[Nmax][Nmax];

int mex( int x, int y )
{
    if ( table[x][y] != -1 )
        return table[x][y];

    if ( x == 0 && y == 0 )
        return table[x][y] = 0;

    unordered_set <int> Set;

    for ( int a = 0; a < x; ++a )
        for ( int b = 0; b < y; ++b )
            Set.insert( mex( a, b ) ^ mex( a, y ) ^ mex( x, b ) );

    table[x][y] = 0;

    while ( Set.count( table[x][y] ) )
        table[x][y]++;

    return table[x][y];
}

void compute_nim_table()
{
    memset( table, -1, sizeof( table ) );

    for ( int i = 0; i < Nmax; ++i )
        for ( int j = 0; j < Nmax; ++j )
            table[i][j] = mex( i, j );
}

int grundy[Nmax];

int mex1( int state )
{
    if ( grundy[state] != -1 )
        return grundy[state];

    if ( state == 0 )
        return grundy[state] = 0;

    unordered_set <int> Set;
    Set.insert( 0 );

    int xorsum = 0;

    for ( int i = state - 1; i >= 1; i-- )
    {
        xorsum ^= mex1( i );
        Set.insert( xorsum );
    }

    grundy[state] = 0;

    while ( Set.count( grundy[state] ) )
        grundy[state]++;

    return grundy[state];
}

int main()
{
    compute_nim_table();
    memset( grundy, -1, sizeof( grundy ) );

    int x, y;

    cin >> x >> y;
    cout << table[ mex1( x ) ][ mex1( y ) ];

    return 0;
}
