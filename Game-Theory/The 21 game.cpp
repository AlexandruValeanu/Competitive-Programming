#include <bits/stdc++.h>

using namespace std;

/**
    Name: The 21 game

    Description: The game "21" is played as a misère game with any number of players who take turns saying a number.
                 The first player says "1" and each player in turn increases the number by 1, 2, or 3, but may not exceed 21;
                 the player forced to say "21" loses

    Strategy: The winning strategy for the two-player version of this game is to always say a multiple of 4;
              it is then guaranteed that the other player will ultimately have to say 21.

**/

const int Vmax = 21;

int grundy[Vmax + 1];
int N, K = 3;

int sprague_grundy( int state )
{
    if ( grundy[state] != -1 )
        return grundy[state];

    if ( state == Vmax )
        return grundy[state] = 0;

    unordered_set <int> Set;

    for ( int i = 1; i <= K; ++i )
        if ( state + i <= Vmax )
            Set.insert( sprague_grundy( state + i ) );

    grundy[state] = 0;

    while ( Set.count( grundy[state] ) )
        grundy[state]++;

    return grundy[state];
}

int main()
{
    memset( grundy, -1, sizeof( grundy ) );

    if ( sprague_grundy( 0 ) )
        cout << "First wins\n";
    else
        cout << "Second wins\n";

    return 0;
}
