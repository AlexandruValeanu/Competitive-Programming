#include <bits/stdc++.h>

using namespace std;

const int Vmax = 1000;
const int Lmax = 200 + 1;
const int BASE = 1e9;

typedef int BigInteger[Lmax];

BigInteger dp[2][Vmax + 1];
int N;

void init(BigInteger B, int x)
{
    memset(B, sizeof(B), 0);

    do
    {
        B[ ++B[0] ] = x % BASE;
        x /= BASE;

    } while ( x );
}

void copiaza(BigInteger A, BigInteger B)
{
    for ( int i = 0; i <= B[0]; ++i )
        A[i] = B[i];
}

void add(BigInteger A, int x)
{
    int T = 0;

    for ( int i = 1; i <= A[0]; ++i )
    {
        A[i] += x + T;
        T = A[i] / BASE;
        A[i] %= BASE;
        x = 0;
    }

    while ( T )
    {
        A[ ++A[0] ] = T % BASE;
        T /= BASE;
    }
}

void add(BigInteger A, BigInteger B)
{
    int T = 0;

    A[0] = max(A[0], B[0]);

    for ( int i = 1; i <= A[0]; ++i )
    {
        A[i] += T + B[i];
        T = A[i] / BASE;
        A[i] %= BASE;
    }

    while ( T )
    {
        A[ ++A[0] ] = T % BASE;
        T /= BASE;
    }
}

int main()
{
    freopen ("indep.in", "r", stdin);
    freopen ("indep.out", "w", stdout);

    cin >> N;

    for ( int i = 0; i <= 1; ++i )
        for ( int j = 1; j <= Vmax; ++j )
            init(dp[i][j], 0);

    for ( int i = 1; i <= N; ++i )
    {
        int value;
        int cr = i & 1;
        int pr = cr ^ 1;

        cin >> value;

        add(dp[cr][value], 1);

        for ( int j = 1; j <= Vmax; ++j )
        {
            int GCD = __gcd(j, value);

            add(dp[cr][GCD], dp[pr][j]);
        }

        for ( int j = 1; j <= Vmax; ++j )
            copiaza(dp[pr][j], dp[cr][j]);
    }

    printf("%d", dp[N & 1][1][ dp[N & 1][1][0] ]);

    for ( int i = dp[N & 1][1][0] - 1; i >= 1; i-- )
        printf("%09d", dp[N & 1][1][i]);

    return 0;
}
