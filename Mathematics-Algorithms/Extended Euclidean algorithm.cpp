#include <bits/stdc++.h>

using namespace std;

int euclid(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int x0, y0;
        int d = euclid(b, a % b, x0, y0);

        x = y0;
        y = x0 - (a / b) * y0;

        return d;
    }
}

int gcd(int a, int b)
{
    int x, y;
    return euclid(a, b, x, y);
}

int modularInverse(int a, int p)
{
    int x, y;
    euclid(a, p, x, y);

    if (x < 0)
        x = x + p;

    return x;
}

int main()
{
    return 0;
}
