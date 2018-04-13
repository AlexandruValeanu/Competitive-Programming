#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e6 + 2;

int dp[2][1000002];
int N, K;

int main()
{
    cin >> N >> K;

    int tip = 0;

    for ( int i = 0; i < N; ++i )
    {
        char ch;

        cin >> ch;

        dp[tip][i] = ch - 'A';
    }

    for ( int j = 0; ( 1 << j ) <= K; ++j )
    {
        if ( ( 1 << j ) & K )
        {
            for ( int i = 0; i < N; ++i )
                dp[tip ^ 1][i] = dp[tip][i] ^ dp[tip][(i + (1<<j)) % N];

            tip ^= 1;
        }
    }

    for ( int i = 0; i < N; ++i )
        cout << char( dp[tip][i] + 'A' );

    return 0;
}
