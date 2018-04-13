#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const ull BASE = 137;
const int Lmax = 1e5 + 2;

char S[Lmax];
int SA[Lmax];
ull H[Lmax], Hpow[Lmax];
int N;

ull getHash( int i, int dim )
{
    return ( H[i] - H[i + dim] * Hpow[dim] );
}

bool cmp( int i, int j )
{
    int lo = 1, hi = min( N - i, N - j );

    while ( lo <= hi )
    {
        int m = ( lo + hi ) / 2;

        if ( getHash( i, m ) == getHash( j, m ) )
            lo = m + 1;
        else
            hi = m - 1;
    }

    return S[i + hi] < S[j + hi];
}

void buildSuffixArray()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= N; ++i )
            Hpow[i] = Hpow[i - 1] * BASE;

    H[N] = 0;

    for ( int i = N - 1; i >= 0; i-- )
    {
        H[i] = H[i + 1] * BASE + S[i];
        SA[i] = i;
    }

    stable_sort( SA, SA + N, cmp );
}

int main()
{
    cin.sync_with_stdio( false );

    cin >> S;

    N = strlen( S );

    buildSuffixArray();

    for ( int i = 0; i < N; ++i )
            cout << SA[i] << "\n";

    return 0;
}
