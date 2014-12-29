#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;

char str[Nmax];
int Bucket[Nmax], auxBucket[Nmax];
int gap, N;

struct Suffix
{
    int idx;

    bool operator < ( const Suffix& sfx ) const
    {
        int i = idx;
        int j = sfx.idx;

        if ( Bucket[i] != Bucket[j] )
            return Bucket[i] < Bucket[j];

        i += gap;
        j += gap;

        if ( i < N && j < N )
            return Bucket[i] < Bucket[j];
        else
            return i > j;
    }

    bool operator != ( const Suffix& sfx ) const
    {
        return ( *this < sfx ) || ( sfx < *this );
    }

} SA[Nmax];

int updateBuckets()
{
    int start = 0, id = 0, c = 0;

    for ( int i = 0; i < N; ++i )
    {
        if ( i > 0 && SA[i - 1] != SA[i] )
        {
            start = i;
            ++id;
        }

        if ( i != start )
            c = 1;

        auxBucket[ SA[i].idx ] = id;
    }

    memcpy( Bucket, auxBucket, sizeof( Bucket ) );

    return c;
}

void SuffixSort()
{
    for ( int i = 0; i < N; ++i )
    {
        SA[i].idx = i;
        Bucket[i] = str[i];
    }

    sort( SA, SA + N );
    int c = updateBuckets();

    for ( gap = 1; c; gap <<= 1 )
    {
        sort( SA, SA + N );
        c = updateBuckets();
    }
}

int main()
{
    scanf("%s", str);
    N = strlen( str );

    SuffixSort();

    for ( int i = 0; i < N; ++i )
        printf("%d\n", SA[i].idx);

    return 0;
}
