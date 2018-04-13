#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;

const ull BASE = 666013;
const int Lmax = 15e2 + 2;
const int SIGMA = 26 + 2;

unordered_set <ull> Set;

int good[SIGMA];
int sum_bad[Lmax];
char alpha[SIGMA];

char S[Lmax];
int N, nr_bad;

ull H[Lmax], Hpow[Lmax];

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= N; ++i )
        Hpow[i] = Hpow[i - 1] * BASE;

    for ( int i = 1; i <= N; ++i )
        H[i] = H[i - 1] * BASE + S[i];
}

ull getHash( int i, int j )
{
    return H[j] - H[i - 1] * Hpow[j - i + 1];
}

int main()
{
    ///ifstream cin("data.in");

    cin.sync_with_stdio( false );

    cin >> ( S + 1 );
    N = strlen( S + 1 );

    cin >> alpha;

    cin >> nr_bad;

    pregen();

    for ( int i = 0; i < SIGMA - 2; ++i )
        good[i] = alpha[i] - '0';

    for ( int i = 1; i <= N; ++i )
        sum_bad[i] = sum_bad[i - 1] + ( good[ S[i] - 'a' ] == 0 );

    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = i; j <= N; ++j )
        {
            if ( sum_bad[j] - sum_bad[i - 1] <= nr_bad )
                Set.insert( getHash( i, j ) );
        }
    }

    cout << Set.size() << "\n";

    return 0;
}
