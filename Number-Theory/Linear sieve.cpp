#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000000;

int smallestFactor[MAX_N + 1];
vector<int> primes;

void linear_sieve()
{
    for (int i = 2; i <= MAX_N; ++i)
    {
        if (smallestFactor[i] == 0)
        {
            smallestFactor[i] = i;
            primes.push_back(i);
        }

        for (int j = 0; j < (int)primes.size() && primes[j] <= smallestFactor[i] && i * primes[j] <= MAX_N; ++j)
            smallestFactor[i * primes[j]] = primes[j];
    }
}

int main()
{
    return 0;
}
