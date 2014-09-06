#include <bits/stdc++.h>

using namespace std;

/**
    Name: Euclid's Game

    Description: During his move the player chooses decreases the larger integer in the pair by a positive multiple
                 of the smaller integer in the pair in such a way that both integers in the pair remain positive.

    Strategy:

    Sprague-Grundy values:

        The function for Euclid's game is g(a,b) = abs(a*a-b*b)/(a*b)
        Obviously: g(a,a) = 0
 **/


int sprague_grundy( int a, int b )
{
    return abs( a * a - b * b ) / ( a * b );
}

int main()
{
    int A, B;

    cin >> A >> B;
    cout << sprague_grundy( A, B ) << "\n";

    return 0;
}
