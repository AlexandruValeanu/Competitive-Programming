#include <bits/stdc++.h>

using namespace std;

/**
    <O(MOD), O(MOD)> preprocess
    <O(logMod), O(1)> query
**/

const int MOD_MAX = 1e6 + 10;

int factorial[MOD_MAX];
int inverseFactorial[MOD_MAX];

int MOD; /// is prime

int power(int a, int p)
{
    int sol = 1;

    while (p)
    {
        if (p & 1)
            sol = (1LL * a * sol) % MOD;

        a = (1LL * a * a) % MOD;
        p >>= 1;
    }

    return sol;
}

void preprocess()
{
    factorial[0] = 1;

    for (int i = 1; i < MOD; ++i)
        factorial[i] = (1LL * i * factorial[i - 1]) % MOD;

    inverseFactorial[MOD - 1] = power(factorial[MOD - 1], MOD - 2);

    for (int i = MOD - 2; i >= 0; i--)
        inverseFactorial[i] = (1LL * inverseFactorial[i + 1] * (i + 1)) % MOD;
}

/// n, k <= MOD
int auxComb(int n, int k)
{
    if (n < k)
        return 0;

    int sol = factorial[n];
    sol = (1LL * sol * inverseFactorial[k]) % MOD;
    sol = (1LL * sol * inverseFactorial[n - k]) % MOD;

    return sol;
}

int C(long long n, long long k)
{
    int sol = 1;

    while (n && k && sol)
    {
        sol = (1LL * sol * auxComb(n % MOD, k % MOD)) % MOD;

        n /= MOD;
        k /= MOD;
    }

    return sol;
}

int main()
{
    return 0;
}
