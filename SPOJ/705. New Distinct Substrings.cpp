#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Lmax = 5e4 + 2;

char S[Lmax];
int SA[Lmax], invSA[Lmax], lcp[Lmax];
int Rank[Lmax], tmpRank[Lmax];

int T, N, gap;

int sufComp( int i, int j )
{
    if ( Rank[i] != Rank[j] )
        return Rank[i] < Rank[j];

    i += gap;
    j += gap;

    if ( i < N && j < N )
        return Rank[i] < Rank[j];
    else
        return i > j;
}

void SuffixArray()
{
    N = strlen( S );

    for ( int i = 0; i < N; ++i )
    {
        SA[i] = i;
        Rank[i] = S[i];
    }

    for ( gap = 1; ; gap *= 2 )
    {
        sort( SA, SA + N, sufComp );

        for ( int i = 1; i < N; ++i )
            tmpRank[i] = tmpRank[i - 1] + sufComp( SA[i - 1], SA[i] );

        for ( int i = 0; i < N; ++i )
            Rank[ SA[i] ] = tmpRank[i];

        if ( tmpRank[N - 1] == N - 1 )
            break;
    }
}

void LCP()
{
    for ( int i = 0; i < N; ++i )
        invSA[ SA[i] ] = i;

    int l = 0;

    for ( int i = 0; i < N; ++i )
    {
        if ( invSA[i] )
        {
            int k = invSA[i];
            int j = SA[k - 1];

            while ( S[i + l] == S[j + l] ) l++;

            lcp[k] = l;

            if ( l > 0 )
                l--;
        }
    }
}

int main()
{
    ///ifstream cin("data.in");

    cin >> T;

    while ( T-- )
    {
        cin >> S;

        SuffixArray();
        LCP();

        long long sol = 1LL * N * ( N + 1 ) / 2;

        for ( int i = 0; i < N; ++i )
            sol -= lcp[i];

        cout << sol << "\n";
    }

    return 0;
}
