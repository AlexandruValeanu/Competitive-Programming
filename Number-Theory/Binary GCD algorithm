#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a == b)
        return a;

    if (a == 0)
        return b;

    if (b == 0)
        return a;

    if (~a & 1) /// a is even
    {
        if (b & 1) ///b is odd
            return gcd(a >> 1, b);
        else
            return gcd(a >> 1, b >> 1) << 1;
    }
    else ///a is odd
    {
        if (~b & 1) ///b is even
            return gcd(a, b >> 1);
    }

    if (a > b)
        return gcd((a - b) >> 1, b);
    else
        return gcd((b - a) >> 1, a);
}

int main()
{
    return 0;
}
