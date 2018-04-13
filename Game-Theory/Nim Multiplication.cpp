#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    memset( table, -1, sizeof( table ) );

    for ( int i = 0; i < 10; ++i, cout << endl )
        for ( int j = 0; j < 10; ++j )
            cout << mex( i, j ) << " ";

    return 0;
}
