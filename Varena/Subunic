#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 2;
const int SIGMA = 256;

int bucket[Nmax];
int group[Nmax], auxGroup[Nmax];
int SA[Nmax], auxSA[Nmax], invSA[Nmax];
int LCP[Nmax]; /// intre lcp[i] = (i-1,i)

char str[Nmax];
int N, nrGroups;

void init()
{
    for ( int i = 0; i < SIGMA; ++i )
        bucket[i] = 0;

    for ( int i = 0; i < N; ++i )
        ++bucket[ str[i] ];

    for ( int i = 1; i < SIGMA; ++i )
        bucket[i] += bucket[i - 1];

    for ( int i = N - 1; i >= 0; i-- )
        SA[ --bucket[ str[i] ] ] = i;

    nrGroups = 0;
    group[ SA[0] ] = 0;

    for ( int i = 1; i < N; ++i )
    {
        if ( str[ SA[i - 1] ] != str[ SA[i] ] )
            nrGroups++;

        group[ SA[i] ] = nrGroups;
    }
}

void SuffixArray()
{
    for ( int d = 0; ( 1 << d ) < N; ++d )
    {
        for ( int i = 0; i < N; ++i )
        {
            auxSA[i] = SA[i] - ( 1 << d );

            if ( auxSA[i] < 0 )
                auxSA[i] += N;
        }

        for ( int i = 0; i < nrGroups + 1; ++i )
            bucket[i] = 0;

        for ( int i = 0; i < N; ++i )
            ++bucket[ group[ auxSA[i] ] ];

        for ( int i = 1; i < nrGroups + 1; ++i )
            bucket[i] += bucket[i - 1];

        for ( int i = N - 1; i >= 0; i-- )
            SA[ --bucket[ group[ auxSA[i] ] ] ] = auxSA[i];

        nrGroups = 0;
        auxGroup[ SA[0] ] = 0;

        for ( int i = 1; i < N; ++i )
        {
            int id1 = ( SA[i - 1] + ( 1 << d ) ) % N;
            int id2 = ( SA[i]     + ( 1 << d ) ) % N;

            if ( group[ SA[i - 1] ] != group[ SA[i] ] || group[id1] != group[id2] )
                nrGroups++;

            auxGroup[ SA[i] ] = nrGroups;
        }

        for ( int i = 0; i < N; ++i )
            group[i] = auxGroup[i];
    }
}

void lcp()
{
    for ( int i = 0; i < N; ++i )
        invSA[ SA[i] ] = i;

    int l = 0;

    for ( int i = 0; i < N; ++i )
    {
        if ( invSA[i] != 0 )
        {
            int j = SA[ invSA[i] - 1 ];

            while ( str[i + l] == str[j + l] ) l++;

            LCP[ invSA[i] ] = l;

            if ( l > 0 )
                l--;
        }
    }
}

int main()
{
    ifstream in("subunic.in");
    ofstream out("subunic.out");

    ios_base::sync_with_stdio( false );

    in >> str;
    N = strlen( str );

    str[ N++ ] = '#';

    init();
    SuffixArray();

    for ( int i = 0; i < N - 1; ++i )
        SA[i] = SA[i + 1];

    N--;
    str[N] = '\0';

    lcp();

    int p = 0;
    int best = 1e9;

    for ( int i = 0; i < N; ++i )
    {
        int lgSuffix = N - SA[i];
        int m = LCP[i];

        if ( i + 1 < N )
            m = max( m, LCP[i + 1] );

        if ( m < lgSuffix )
        {
            if ( best > m + 1 )
            {
                best = m + 1;
                p = i;
            }
        }
    }

    for ( int k = 0; k < best; ++k )
        out << ( str + SA[p] )[k];

    out << "\n";

    return 0;
}
