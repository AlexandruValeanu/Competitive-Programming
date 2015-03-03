#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000000;

int sieve[Nmax + 1];
bool valid[Nmax + 1];
int C, D;

int main()
{
    ifstream in("mins.in");
    ofstream out("mins.out");

    in >> C >> D;
    C--; D--;

    int L = min(C, D);
    long long sol = 1LL * C * D;

    for ( int i = 2; i <= L; ++i )
    {
        if ( sieve[i] ) continue;

        for ( int j = i; j <= L; j += i )
            sieve[j]++;

        if ( 1LL * i * i <= L )
            for (int j = i * i; j <= L; j += i * i )
                valid[j] = true;
    }

    for ( int i = 2; i <= L; ++i )
        if ( valid[i] == false )
        {
            if ( sieve[i] & 1 )
                sol -= 1LL * (C / i) * (D / i);
            else
                sol += 1LL * (C / i) * (D / i);
        }

    out << sol << "\n";

    return 0;
}
