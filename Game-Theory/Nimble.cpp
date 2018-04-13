#include <bits/stdc++.h>

using namespace std;

/**
    Name: Nimble

    Description: Nimble is played on a game board consisting of a line of squares labeled: 0, 1, 2, 3, ... n.
                 A finite number of coins is placed on the squares with possible more than one coin on a single square.
                 A move consists of taking one of the coins and moving it to any square to the left, possibly moving
                 over some of the coins, and possibly onto a square already containing one or more coins.
                 The players alternate moves and the game ends when all coins a
                 re on the square labeled 0. The last player to move wins.

    Strategy: A coin on square n is the same as a nim-heap of size n.
**/

const int Nmax = 100;

int coins[Nmax + 1];
int N;

int main()
{
    cin >> N;

    for ( int i = 0; i <= N; ++i )
        cin >> coins[i];

    int xorsum = 0;

    for ( int i = 1; i <= N; ++i )
        if ( coins[i] & 1 )
            xorsum ^= i;

    if ( xorsum )
        cout << "First wins!";
    else
        cout << "Second wins!";

    return 0;
}
