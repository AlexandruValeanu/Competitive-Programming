#include <bits/stdc++.h>

using namespace std;

long long T, R, K;

int main()
{
    ///ifstream cin("data.in");

    cin >> T;

    while ( T-- )
    {
        cin >> R >> K;

        long long r = 1LL * R;
        long long c1 = 0, c3 = 0;

        for ( long long i = 1; i * i <= r; ++i )
        {
            if ( r % i == 0 )
            {
                if ( i % 4 == 1 )
                    c1++;

                if ( i % 4 == 3 )
                    c3++;

                if ( i != r / i )
                {
                    if ( ( r / i ) % 4 == 1 )
                        c1++;

                    if ( ( r / i ) % 4 == 3 )
                        c3++;
                }
            }
        }

        if ( K >= 4LL * ( c1 - c3 ) )
            cout << "possible\n";
        else
            cout << "impossible\n";

    }
    return 0;
}
