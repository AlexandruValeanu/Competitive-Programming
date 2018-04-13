#include <bits/stdc++.h>

using namespace std;

const int Nmax = 500 + 1;

int dp[2][Nmax];
int A;
int N, M;

int main()
{
    ifstream in("traseu.in");
    ofstream out("traseu.out");

    ios_base::sync_with_stdio( false );

    in >> N >> M;

    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = 1; j <= M; ++j )
        {
            in >> A;
            dp[i & 1][j] = max( dp[i & 1 ^ 1][j], dp[i & 1][j - 1] ) + A;
        }
    }

    out << dp[N & 1][M] << "\n";

    return 0;
}
