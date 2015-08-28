#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000000;

bitset<MAX_N+1> sieve;

void generate_sieve1()
{
    sieve.reset();

    sieve[1] = true;

    for (int i = 4; i <= MAX_N; i += 2)
        sieve[i] = true;

    for (int i = 3; i <= MAX_N; i += 2)
        if (sieve[i] == 0)
            for (int j = 3 * i; j <= MAX_N; j += 2 * i)
                sieve[j] = 1;

    int nr = 0;

    for (int i = 2; i <= MAX_N; ++i)
        if (sieve[i] == 0)
            nr++;

    cout << nr << "\n";
}

void generate_sieve2()
{
    sieve.reset();

    sieve[1] = true;

    for (int i = 2; i * i <= MAX_N; ++i)
        if (sieve[i] == 0)
            for (int j = i * i; j <= MAX_N; j += i)
                sieve[j] = 1;

    int nr = 0;

    for (int i = 2; i <= MAX_N; ++i)
        if (sieve[i] == 0)
            nr++;

    cout << nr << "\n";
}

int main()
{
    generate_sieve1();
    generate_sieve2();

    return 0;
}
