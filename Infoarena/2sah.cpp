#include <bits/stdc++.h>

using namespace std;

const int MOD = 100003;
const int Kmax = 3;

int SOL[Kmax][Kmax], I[Kmax][Kmax], aux[Kmax][Kmax];

int pw(int a, int p)
{
    int res = 1;

    while (p)
    {
        if (p & 1)
            res = (1LL * res * a) % MOD;

        a = (1LL * a * a) % MOD;
        p >>= 1;
    }

    return res;
}

void mult(int A[][Kmax], int B[][Kmax], int C[][Kmax])
{
    for ( int i = 0; i < Kmax; ++i )
        for ( int j = 0; j < Kmax; ++j )
            C[i][j] = 0;

    for ( int k = 0; k < Kmax; ++k )
        for ( int i = 0; i < Kmax; ++i )
            for ( int j = 0; j < Kmax; ++j )
                C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;

    for ( int i = 0; i < Kmax; ++i )
        for ( int j = 0; j < Kmax; ++j )
            A[i][j] = C[i][j];
}

int power(int p)
{
    for ( int i = 0; i < Kmax; ++i )
        I[i][i] = 1;

    SOL[0][1] = SOL[1][2] = 1;
    SOL[2][0] = SOL[2][1] = SOL[2][2] = 1;

    while (p)
    {
        if (p & 1)
            mult(I, SOL, aux);

        mult(SOL, SOL, aux);
        p >>= 1;
    }

    return (I[2][0] + I[2][1] + 2 * I[2][2]) % MOD;
}

int main()
{
    ifstream in("2sah.in");
    ofstream out("2sah.out");

    int p, N, K;

    in >> p;
    in >> N >> K;

    if (p == 1)
        out << pw(3, K - 1) << "\n";
    else
        out << power(N + 1 - K + 1 - 3);

    return 0;
}
