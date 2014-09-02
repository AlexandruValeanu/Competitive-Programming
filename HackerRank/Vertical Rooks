#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2e3 + 2;

int A[2 * Nmax];
int T, N;

int main()
{
    cin >> T;

    while ( T-- )
    {
        cin >> N;

        for ( int i = 1; i <= 2 * N; ++i )
            cin >> A[i];

        int xorsum = 0;

        for ( int i = 1; i <= N; ++i )
            xorsum ^= abs( A[i] - A[i + N] ) - 1;

        if ( xorsum )
            cout << "player-2\n";
        else
            cout << "player-1\n";
    }

    return 0;
}
