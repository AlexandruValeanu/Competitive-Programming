#include <bits/stdc++.h>

using namespace std;

/**
    Name: The subtraction game S(1,2,...,k)

    Description: It is similar to Nim. An upper bound is imposed
                 on the number of objects that can be removed in a turn.
                 Instead of removing arbitrarily many objects, a player
                 can only remove 1 or 2 or ... or k at a time.

    Strategy:

        The first one loses if:
            n ≡ 0 (mod k+1) (in normal play)
            n ≡ 1 (mod k+1) (in misère play)

        Sprague-Grundy values: (0,1,2,3,...,k),(0,1,2,3,...,k),...
**/

const int Nmax = 100;

int grundy[Nmax];
int N, K;

int sprague_grundy( int state )
{
    if ( grundy[state] != -1 )
        return grundy[state];

    if ( state == 0 )
        return 0;

    unordered_set <int> Set;

    for ( int i = 1; i <= K; ++i )
        if ( state >= i )
            Set.insert( sprague_grundy( state - i ) );

    grundy[state] = 0;

    while ( Set.count( grundy[state] ) )
        grundy[state]++;

    return grundy[state];
}

int main()
{
    memset( grundy, -1, sizeof( grundy ) );

    cin >> N >> K;

    if ( sprague_grundy( N ) ) /// N % ( K + 1 ) != 0
        cout << "First wins\n";
    else
        cout << "Second wins\n";

    return 0;
}
