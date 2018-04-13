#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
const ull BASE = 666013;

const int Lmax = 5e6 + 2;

int pal[Lmax];
char S[Lmax];
int N, solution;

ull H1[Lmax], H2[Lmax], Hpow[Lmax];

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

    pal[1] = 1;

    for ( int i = 2; i <= N; ++i )
    {
        if ( getHash( H1, 1, i ) == getHash( H2, N - i + 1, N ) )
        {
            pal[i] = pal[i / 2] + 1;
        }

        solution += pal[i];
    }

    cout << solution + 1 << "\n";

    return 0;
}
