#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100 + 2;

int T, N;

int main()
{
    cin >> T;

    while ( T-- )
    {
        cin >> N;

        int xorsum = 0;

        for ( int i = 1, A; i <= N; ++i )
        {
            cin >> A;

            while ( A >= i )
            {
                xorsum ^= 1;
                A -= i;
            }
        }

        if ( xorsum )
            cout << "ALICE\n";
        else
            cout << "BOB\n";
    }

    return 0;
}
