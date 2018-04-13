#include <bits/stdc++.h>

using namespace std;

/**
    Name: The 100 game

    Description:  Two players start from 0 and alternatively add a number from 1 to 10 to the sum.
                  The player who reaches 100 wins.

    Strategy: The winning strategy is to reach a number in which the digits are subsequent (e.g. 01, 12, 23, 34,...)
              and control the game by jumping through all the numbers of this sequence.
              Once reached 89, the opponent has lost (he can only tell numbers from 90 to 99, and the next answer can in any case be 100).

    Sprague-Grundy values (0 based): 1, (0,10,9,8,7,6,5,4,3,2,1), (0,10,9,8,7,6,5,4,3,2,1), ...
**/

const int Vmax = 100;

int grundy[Vmax + 1];
int N, K = 10;

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
