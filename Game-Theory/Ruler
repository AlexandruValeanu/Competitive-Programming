#include <bits/stdc++.h>

using namespace std;

/**
    Name: Ruler

    Description: Any number of coins may be turned over but they must be consecutive, and the rightmost
                 coin must be turned from heads to tails.

    Strategy:
            g(n)=mex{0,g(n−1),g(n−1)⊕g(n−2),...,g(n−1)⊕...⊕g(1)}.
            Thus, g(x) is the largest power of 2 dividing x.
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
    Set.insert( 0 );

    int xorsum = 0;

    for ( int i = state - 1; i >= 1; i-- )
    {
        xorsum ^= mex( i );
        Set.insert( xorsum );
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
        cout << i << " " << mex( i ) << "\n";

    return 0;
}
