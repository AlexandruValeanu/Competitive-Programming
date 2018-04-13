#include <bits/stdc++.h>

using namespace std;

int getRandomInt(int x, int y)
{
    return x + rand() % (y - x + 1);
}

///pseudo-random function
int f(int x, int c, int n) /// f(x) = x^2 + c (mod n)
{
    return (1LL * x * x + c) % n;
}

int rho(const int n) ///returns a proper divisor of n or n (if it fails!)
{
    if (n % 2 == 0)
        return 2;

    int a = getRandomInt(1, n - 1);
    int c = getRandomInt(1, n - 1);

    int x = a;
    int y = a;
    int divisor;

    do
    {
        x = f(x, c, n);

        y = f(y, c, n);
        y = f(y, c, n);

        divisor = __gcd(abs(x - y), n);

    } while (divisor == 1);

    return divisor;
}

int pollard_rho(const int n) ///returns a proper divisor of n (IT FAILS IF n IS PRIME!)
{
    srand(time(nullptr));

    int d;

    do
    {
        d = rho(n);

    } while (d == n);

    return d;
}

int main()
{
    return 0;
}
