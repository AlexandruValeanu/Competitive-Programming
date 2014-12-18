#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1024;

int dp[Nmax][Nmax];
int T, N, K, A;

int main()
{
    ios_base::sync_with_stdio( false );

    cin >> T;

    while ( T-- )
    {
        memset( dp, 0, sizeof( dp ) );

        dp[0][0] = 1;

        cin >> N >> K;

        for ( int i = 1; i <= N; ++i )
        {
            cin >> A;

            for ( int j = 0; j < Nmax; ++j )
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j ^ A];
        }

        int maxim = 0;

        for ( int i = 0; i < Nmax; ++i )
            maxim = max( maxim, ( K ^ i ) * dp[N][i] );

        cout << maxim << "\n";
    }

    return 0;
}
