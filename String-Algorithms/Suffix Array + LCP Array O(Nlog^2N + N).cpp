#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Lmax = 1e5 + 2;

char S[Lmax];
int SA[Lmax], invSA[Lmax], lcp[Lmax];
int Rank[Lmax], tmpRank[Lmax]; /// used for lexicographic renaming

/**Each iteration i has two steps:
    -Sorting by 2^i-grams, using the lexicographic names from the previous iteration to enable comparisons in 2 steps (i.e. O(1) time) each
    -Creating new lexicographic names
**/

int N, gap;

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

void buildSuffixArray()
{
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

        if ( tmpRank[N - 1] == N - 1 ) break;
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
    cin >> S;

    N = strlen( S );

    buildSuffixArray();
    LCP();

    return 0;
}
