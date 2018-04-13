#include <bits/stdc++.h>

using namespace std;

/**
    Name: Grundy's game

    Description: Grundy's game is a two-player mathematical game of strategy.
                 The starting configuration is a single heap of objects,
                 and the two players take turn splitting a single heap into two heaps of different sizes.
                 The game ends when only heaps of size two and smaller remain, none of which can be split unequally.
                 The game is usually played as a normal play game, which means that the last person who can make an allowed move wins.

    Strategy: Whether the sequence of nim-values of Grundy's game ever becomes periodic is an unsolved problem

    Sprague-Grundy values:

        Heap size           : 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 ...
        Equivalent Nim heap : 0  0  0  1  0  2  1  0  2  1  0  2  1  3  2  1  3  2  4  3  0 ...
**/

const int Nmax = 100;

int grundy[Nmax + 1];

int sprague_grundy( int heap_size )
{
    if ( grundy[heap_size] != -1 )
        return grundy[heap_size];

    unordered_set <int> Set;

    for ( int i = 1; i <= heap_size / 2; ++i )
        if ( i != heap_size - i )
            Set.insert( sprague_grundy( i ) ^ sprague_grundy( heap_size - i ) );

    grundy[heap_size] = 0;

    while ( Set.count( grundy[heap_size] ) )
        grundy[heap_size]++;

    return grundy[heap_size];
}

int main()
{
    memset( grundy, -1, sizeof( grundy ) );

    for ( int i = 0; i <= 20; ++i )
        cout << sprague_grundy( i ) << " ";

    return 0;
}
