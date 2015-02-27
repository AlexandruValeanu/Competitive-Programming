#include <bits/stdc++.h>

using namespace std;

const int Nmax = 500 + 1;
const int MOD = 10007;

int **dp;
int N, K, X;

int memo(int n, int k)
{
    if ( k > n )
        return 0;

    if ( k == n )
        return 1;

    if ( n <= 0 || k <= 0 )
        return 0;

    if ( dp[n][k] != -1 )
        return dp[n][k];

    return dp[n][k] = (memo(n - 1, k - 1) + memo(n - k, k)) % MOD;
}

int main()
{
    ifstream in("desc2.in");
    ofstream out("desc2.out");

    in >> N >> K >> X;

    int A = N - X * K * (K - 1) / 2;

    dp = new int*[A + 1];

    for ( int i = 0; i <= A; ++i )
    {
        dp[i] = new int[K + 1];

        for ( int j = 0; j < K + 1; ++j )
            dp[i][j] = -1;
    }

    out << memo(A, K) << "\n";

    return 0;
}
