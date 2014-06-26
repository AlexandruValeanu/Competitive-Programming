#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
const ull BASE = 137;

const int Lmax = 1e3 + 2;

char S[Lmax];
ull H[Lmax];
ull Hpow[Lmax];
int SA[Lmax];
int T, N;

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i < Lmax; ++i )
        Hpow[i] = Hpow[i - 1] * BASE;
}

ull getHash( int i, int dim )
{
    return H[i] - H[i + dim] * Hpow[dim];
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

void SuffixArray()
{
    for ( int i = 0; i < N; ++i )
        SA[i] = i;

    H[N] = 0;

    for ( int i = N - 1; i >= 0; i-- )
    {
        H[i] = H[i + 1] * BASE + S[i];
    }

    stable_sort( SA, SA + N, cmp );
}

int lcp( int i, int j )
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

    return hi;
}

int main()
{
    ///ifstream cin("data.in");

    cin.sync_with_stdio( false );

    pregen();

    cin >> T;

    while ( T-- )
    {
        cin >> S;

        N = strlen( S );

        SuffixArray();

        long long sol = N * ( N + 1 ) / 2;

        for ( int i = 0; i < N - 1; ++i )
        {
            sol -= lcp( SA[i], SA[i + 1] );
        }

        cout << sol << "\n";
    }

    return 0;
}
