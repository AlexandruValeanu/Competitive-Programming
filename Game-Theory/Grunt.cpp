#include <bits/stdc++.h>

using namespace std;

/**
    Name: Grunt

    Description: Turn over four symmetric coins, one of which is the leftmost coin, with
                 the rightmost coin going from heads to tails.

    Strategy: A singleton heads in positions 0, 1, or 2, is a terminal position and so has SG-value 0.
              A singleton heads in position n ≥ 3 gets replaced by heads in positions 0, x and n−x for some x<n/2.
              The heads in position 0 has SG-value 0, so this is like taking a pile of n counters and splitting it
              into two nonempty piles of different sizes — exactly Grundy’s Game.
**/

const int Nmax = 100;

int grundy[Nmax];

int mex( int state )
{
    if ( grundy[state] != -1 )
        return grundy[state];

    if ( state < 3 )
        return grundy[state] = 0;

    unordered_set <int> Set;

    for ( int i = 1; i <= state / 2; ++i )
    {
        if ( i != state - i )
            Set.insert( mex( 0 ) ^ mex( i ) ^ mex( state - i ) );
    }

    grundy[state] = 0;

    while ( Set.count( grundy[state] ) )
        grundy[state]++;

    return grundy[state];
}

int main()
{
    memset( grundy, -1, sizeof( grundy ) );

    for ( int i = 0; i <= 20; ++i )
        cout << mex( i ) << ",";

    return 0;
}
