#include <bits/stdc++.h>

using namespace std;

/**
    Name: Twins

    Description: In Turning Turtles, we may turn over one or two coins, with the rightmost coin going from heads to tails.
    In the game, Twins, the rules are: Turn over exactly two coins, with the rightmost coin going from heads to tails.

    Strategy: If we label the positions of the coins from the left starting with 0, then the Sprague-Grundy
              function will be g(x)=x, the same as nim.
**/

const int Nmax = 100;

int grundy[Nmax];

int mex( int state )
{
    if ( grundy[state] != -1 )
        return grundy[state];

    if ( state == 0 )
        return grundy[state] = 0;

    unordered_set <int> Set;

    for ( int i = 0; i < state; ++i )
    {
        Set.insert( mex( i ) );
    }

    grundy[state] = 0;

    while ( Set.count( grundy[state] ) )
        grundy[state]++;

    return grundy[state];
}

int main()
{
    memset( grundy, -1, sizeof( grundy ) );

    for ( int i = 0; i < 10; ++i )
        cout << mex( i ) << ",";

    return 0;
}
