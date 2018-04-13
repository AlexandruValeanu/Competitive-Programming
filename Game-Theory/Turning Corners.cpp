#include <bits/stdc++.h>

using namespace std;

/**
    Name: Turning Corners

    Description: A move consists of turning over four distinct coins at the corners of a rectangle, i.e.
                 (a, b), (a, y), (x, b) and (x, y), where 0≤a<x and 0≤b<y.

    Strategy: The Sprague-Grundy function of this game satisfies the condition
                  g(x, y) = mex { g(x, b) ⊕ g(a, y) ⊕ g(a, b) : 0≤a<x,0≤b<y }

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

    for ( int a = 0; a < x; ++a )
        for ( int b = 0; b < y; ++b )
            Set.insert( mex( a, b ) ^ mex( a, y ) ^ mex( x, b ) );

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
