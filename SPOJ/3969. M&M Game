#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, N, value;

    cin >> T;

    while ( T-- )
    {
        cin >> N;

        int numberOfOne = 0, xorsum = 0;

        for ( int i = 1; i <= N; ++i )
        {
            cin >> value;

            if ( value == 1 )
                numberOfOne++;

            xorsum ^= value;
        }

        if ( numberOfOne == N )
        {
            if ( numberOfOne % 2 == 0 )
                cout << "John\n";
            else
                cout << "Brother\n";
        }
        else
        {
            if ( numberOfOne == N - 1 )
                cout << "John\n";
            else
            {
                if ( xorsum )
                    cout << "John\n";
                else
                    cout << "Brother\n";
            }
        }
    }


    return 0;
}
