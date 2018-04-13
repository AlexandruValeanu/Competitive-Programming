#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long pw( long long a, long long b )
{
    long long sol = 1;

    while ( b )
    {
        if ( b & 1 )
            sol = ( 1LL * sol * a ) % MOD;

        a = ( 1LL * a * a ) % MOD;
        b >>= 1;
    }

    return sol;
}

long long solve( int r, int s ) /// r de 1, s de 2
{
    if ( r  - 1 >= 0 )
    {
        long long a = pw( 2, r - 1 );
        long long b = pw( 3, s + 1 );

        return ( 1LL * a * ( b - 1 ) ) % MOD;
    }
    else
    {
        long long b = pw( 3, s + 1 );

        return ( 1LL * pw( 2, MOD - 2 ) * ( b - 1 ) ) % MOD;
    }
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio( false );

    long long N;
    int T;

    cin >> T;

    while ( T-- )
    {
        cin >> N;

        int r = 0, s = 0;

        while ( N )
        {
            while ( N % 3 == 0 )
            {
                N /= 3;
            }

            while ( N % 3 == 1 )
            {
                r++;
                N /= 3;
            }

            while ( N % 3 == 2 )
            {
                s++;
                N /= 3;
            }
        }

        cout << solve( r, s ) << "\n";
    }

    return 0;
}
