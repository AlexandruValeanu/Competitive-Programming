#include <bits/stdc++.h>

using namespace std;

int T, S;

int main()
{
    cin >> T;

    while ( T-- )
    {
        cin >> S;

        int xorsum = 0;

        for ( int i = 1, a; i <= S; ++i )
        {
            cin >> a;

            if ( a % 2 )
                xorsum ^= i;
        }

        if ( xorsum )
            cout << "Tom Wins\n";
        else
            cout << "Hanks Wins\n";
    }

    return 0;
}
