#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 1000000;
const int MOD = 9973;

bitset<MAX_VAL+1> sieve;
vector<int> primes;

void generate_sieve()
{
    for (int i = 4; i <= MAX_VAL; i += 2)
        sieve[i] = true;

    primes.push_back(2);

    for (int i = 3; i <= MAX_VAL; i += 2)
        if (sieve[i] == false)
        {
            primes.push_back(i);

            for (int j = 3 * i; j <= MAX_VAL; j += 2 * i)
                sieve[j] = true;
        }
}

int modular_exponentiation(int a, int p, int n) /// a^p (mod n)
{
    int solution = 1;

    while (p)
    {
        if (p & 1)
            solution = (1LL * solution * a) % n;

        a = (1LL * a * a) % n;
        p >>= 1;
    }

    return solution;
}

void euclid(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
    }
    else
    {
        int x0, y0;

        euclid(b, a % b, x0, y0);

        x = y0;
        y = x0 - (a / b) * y0;
    }
}

int modularInverse(int A, int N)
{
    int x, y;
    euclid(A, N, x, y);

    if (x <= 0)
        x = N + x % N;

    return x;
}

int add_mod(int a, int b)
{
    a = (a + b) % MOD;
    return a;
}

int substract(int a, int b)
{
    a = (a - b + MOD) % MOD;
    return a;
}

int multiply(int a, int b)
{
    a = (1LL * a * b) % MOD;
    return a;
}

int divide(int a, int b)
{
    a = (1LL * a * modularInverse(b, MOD)) % MOD;
    return a;
}

int numberOfDivisors(long long n)
{
    int nr = 1;

    for (size_t i = 0; 1LL * primes[i] * primes[i] <= n && i < primes.size(); ++i)
        if (n % primes[i] == 0)
        {
            int e = 0;

            while (n % primes[i] == 0)
            {
                e++;
                n /= primes[i];
            }

            nr = multiply(nr, e + 1);
        }

    if (n > 1)
    {
        nr = multiply(nr, 2);
    }

    return nr;
}

int sumOfDivisors(long long n)
{
    int sum = 1;

    for (size_t i = 0; 1LL * primes[i] * primes[i] <= n && i < primes.size(); ++i)
        if (n % primes[i] == 0)
        {
            int e = 0;

            while (n % primes[i] == 0)
            {
                e++;
                n /= primes[i];
            }

            sum = multiply(sum, substract(modular_exponentiation(primes[i], e + 1, MOD), 1));
            sum = divide(sum, primes[i] - 1);
        }

    if (n > 1)
    {
        sum = multiply(sum, substract(modular_exponentiation(n, 2, MOD), 1));
        sum = divide(sum, n - 1);
    }

    return sum;
}

int main()
{
    generate_sieve();

    return 0;
}
