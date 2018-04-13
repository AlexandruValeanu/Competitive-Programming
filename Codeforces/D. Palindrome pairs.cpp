#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const ull BASE = 666013;
const int Lmax = 2e3 + 2;

char S[Lmax];
int N;

int start[Lmax];
int finish[Lmax];

ull H1[Lmax];
ull H2[Lmax];
ull Hpow[Lmax];

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= N; ++i )
        Hpow[i] = Hpow[i - 1] * BASE;

    for ( int i = 1; i <= N; ++i )
    {
        H1[i] = H1[i - 1] * BASE + S[i];
        H2[i] = H2[i - 1] * BASE + S[N - i + 1];
    }
}

ull getHash( ull H[], int i, int j )
{
    return H[j] - H[i - 1] * Hpow[j - i + 1];
}

int main()
{
    ///ifstream cin("data.in");

    cin.sync_with_stdio( false );

    cin >> ( S + 1 );
    N = strlen( S + 1 );

    pregen();

    for ( int i = 1; i <= N; ++i )
        for ( int j = i; j <= N; ++j )
            if ( getHash( H1, i, j ) == getHash( H2, N - j + 1, N - i + 1 ) )
            {
                start[i]++;
                finish[j]++;
            }

    long long sol = 0;
    long long nr_end = 0;

    for ( int i = 1; i <= N; ++i )
    {
        nr_end += finish[i - 1];
        sol += 1LL * nr_end * start[i];
    }

    cout << sol << "\n";

    return 0;
}
