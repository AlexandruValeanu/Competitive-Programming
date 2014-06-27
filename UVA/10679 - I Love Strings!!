#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Nmax = 1e5 + 2;

int T, N, gap, Q;
char text[Nmax], temp[Nmax], patt[Nmax];
int SA[Nmax];
int Rank[Nmax], tmpRank[Nmax];

inline int sufComp( int i, int j )
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
    N = strlen ( text );

    for ( int i = 0; i < N; ++i )
    {
        SA[i] = i;
        Rank[i] = text[i];
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

inline char cauta( char *pattern )
{
    int st = 0, dr = N - 1, m;
    int sz = strlen( pattern );

    while ( st <= dr )
    {
        m = ( st + dr ) / 2;

        char *tmpRank = new char[sz + 1];
        strncpy( tmpRank, text + SA[m], sz );

        int comp = strcmp( tmpRank, pattern );

        delete [] tmpRank;

        if ( comp == 0 )
                return 'y';

        if ( comp > 0 )
            st = m + 1;
        else
            dr = m - 1;
    }

    return 'n';
}

int main()
{
    cin.sync_with_stdio( false );

    cin >> T;

    for ( ; T; T-- )
    {
        cin >> text;

        SuffixArray();

        for ( cin >> Q; Q; Q-- )
        {
            cin >> patt;
            cout << cauta( patt) << "\n";
        }
    }

    return 0;
}
