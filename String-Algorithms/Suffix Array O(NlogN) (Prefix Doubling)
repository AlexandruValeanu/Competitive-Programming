#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 1;
const int SIGMA = 256;

char str[Nmax];

int bucket[Nmax];
int group[Nmax], auxGroup[Nmax];
int SA[Nmax], auxSA[Nmax];

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

int main()
{
    ios_base::sync_with_stdio( false );

    cin >> str;
    N = strlen( str );

    str[ N++ ] = '#';

    init();
    SuffixArray();

    for ( int i = 0; i < N - 1; ++i )
        SA[i] = SA[i + 1];

    N--;
    str[N] = '\0';

    for ( int i = 0; i < N; ++i )
        cout << SA[i] << "\n";

    return 0;
}
