#include <bits/stdc++.h>

using namespace std;

const int Vmax = 1000000 + 1;

int sieve[Vmax];
bool use[Vmax];
bool prime[Vmax];
bool valid[Vmax];

int N, M;

int main()
{
    ifstream in("pairs.in");
    ofstream out("pairs.out");

    in >> N;

    for ( int i = 1; i <= N; ++i )
    {
        int a;
        in >> a;
        use[a] = 1;
        M = max(M, a);
    }

    long long sol = 0;

    for ( int i = 2; i <= M; ++i )
    {
        if ( prime[i] == false )
        {
            for ( int j = i; j <= M; j += i )
            {
                sieve[j]++;
                prime[j] = true;

                if ( j % (i * i) == 0 )
                    valid[j] = true;
            }
        }
    }

    for ( int i = 2; i <= M; ++i )
    {
        if ( valid[i] == false )
        {
            int nr = 0;

            for ( int j = i; j <= M; j += i )
                nr += use[j];

            if ( sieve[i] & 1 )
                sol += 1LL * nr * (nr - 1) / 2;
            else
                sol -= 1LL * nr * (nr - 1) / 2;
        }
    }

    out << 1LL * N * (N - 1) / 2 - sol << "\n";

    return 0;
}
