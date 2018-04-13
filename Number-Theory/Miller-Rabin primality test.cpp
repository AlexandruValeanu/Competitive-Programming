#include <bits/stdc++.h>

using namespace std;

int modular_exponentiation(int a, int p, int mod) /// a^p % mod
{
    int res = 1;

    while (p)
    {
        if (p & 1)
            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;
        p >>= 1;
    }

    return res;
}

bool witness(int a, int n) ///check if n is composite using 'a' as 'witness'
{
    int x[64];

    int tmp = n - 1;
    int u, t = 0;

    while (tmp % 2 == 0)
    {
        t++;
        tmp >>= 1;
    }

    u = tmp;

    ///n = u*(2^t)

    x[0] = modular_exponentiation(a, u, n);

    for (int i = 1; i <= t; ++i)
    {
        x[i] = (1LL * x[i - 1] * x[i - 1]) % n;

        if (x[i] == 1 && (x[i - 1] != 1 && x[i - 1] != n - 1))
            return true; ///n is composite
    }

    if (x[t] != 1)
        return true; ///n is composite
    else
        return false; ///n is 'probably' prime
}

bool miller_rabin(int n)
{
    if (n == 1)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    if (n == 7 || n == 61)
        return true;

    if (witness(2, n) || witness(7, n) || witness(61, n))
        return false; ///n is composite

    return true; ///n is 'probably' prime
}

int main()
{
    return 0;
}
