#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int pw(int a, int p)
{
    int sol = 1;

    while ( p )
    {
        if ( p & 1 )
            sol = (1LL * sol * a) % MOD;

        a = (1LL * a * a) % MOD;
        p >>= 1;
    }

    return sol;
}

int main()
{
    ifstream in("azerah.in");
    ofstream out("azerah.out");

    int T, N;
    in >> T;

    while ( T-- )
    {
        in >> N;

        int nrPare = 0, nrImpare = 0;

        while ( N-- )
        {
            int a;
            in >> a;

            if ( a % 2 )
                nrImpare++;
            else
                nrPare++;
        }

        int sol = pw(2, nrPare);

        sol = (1LL * sol * pw(2, nrImpare)) % MOD;

        if ( nrImpare )
            sol = (1LL * sol * pw(2, MOD - 2)) % MOD;

        sol = (sol - 1 + MOD) % MOD;

        out << sol << "\n";
    }

    return 0;
}
