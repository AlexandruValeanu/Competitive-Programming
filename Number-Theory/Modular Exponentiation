#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    return 0;
}
