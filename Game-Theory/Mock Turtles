#include <bits/stdc++.h>

using namespace std;

/**
    Name: Mock Turtles

    Description: It is like Turning Turtles but we are allowed to turn over up to three coins. The rules are :
                 Turn over one, two, or three coins with the rightmost going from heads to tails.

    Strategy:

        position x: 0 1 2 3 4  5  6  7  8  9 10
              g(x): 1 2 4 7 8 11 13 14 16 19 21

        What are these numbers? It seems as if g(x) is equal to either 2x or 2x+ 1; but which one?
        The answer depends on the number of 1’s appearing in the binary expansion of 2x.
**/

const int Nmax = 100;

int grundy[Nmax];

int mex( int state )
{
    if ( grundy[state] != -1 )
        return grundy[state];

    if ( state == 0 )
        return grundy[state] = 1;

    unordered_set <int> Set;

    Set.insert( 0 ); /// I turn 1

    for ( int i = 0; i < state; ++i ) /// I turn another 1
    {
        Set.insert( mex( i ) );
    }

    for ( int i = 0; i < state; ++i ) /// I turn another 2
        for ( int j = i + 1; j < state; ++j )
            Set.insert( mex( i ) ^ mex( j ) );

    grundy[state] = 0;

    while ( Set.count( grundy[state] ) )
        grundy[state]++;

    return grundy[state];
}

int main()
{
    memset( grundy, -1, sizeof( grundy ) );

    for ( int i = 0; i <= 14; ++i )
        cout << mex( i ) << ",";

    return 0;
}
