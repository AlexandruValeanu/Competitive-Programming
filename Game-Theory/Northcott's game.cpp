#include <bits/stdc++.h>

using namespace std;

/**
    Name: Northcott's game

    Description: In every row of a rectangular board, there are two checkers: one white and one black.
                 A move consists in sliding a single checker in its original row without jumping over another checker.
                 You play white, computer plays black.
                 As usual, the player to make the last move wins.

    Strategy: The the number of spaces between the two tokens on each row are the sizes of the Nim heaps.
              This is the same as Poker Nim. If your opponent increases the number of spaces between two tokens,
              just decrease it on your next move.
              Else, play the game of Nim and make the Nim-sum of the number of spaces between the tokens on each row be 0.
**/

const int Nmax = 100;

int black[Nmax], white[Nmax]; /// (black[i] = the x coordinate of the black checker of row i)
int W, H;

int main()
{
    cin >> W >> H;

    for ( int i = 1; i <= H; ++i )
        cin >> black[i];

    for ( int i = 1; i <= H; ++i )
        cin >> white[i];

    int xorsum = 0;

    for ( int i = 1; i <= H; ++i )
        xorsum ^= abs( black[i] - white[i] );

    if ( xorsum )
        cout << "White wins!";
    else
        cout << "Black wins!";

    return 0;
}
