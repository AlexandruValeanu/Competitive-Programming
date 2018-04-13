#include <bits/stdc++.h>

const int Nmax = 1e6;

using namespace std;

/**
    I = 1;
    E = 0;
**/

char str[Nmax];
int N, K;

const int DIGITS = 4;
const int R = 32 / 4;
const int radix = 1 << R;
const int mask = radix - 1;

int A[Nmax], B[Nmax], buckets[radix], newN;

void RadixSort()
{
    for ( int d = 0, shift = 0; d < DIGITS; d++, shift += R )
    {
        for ( int i = 0; i < radix; ++i )
            buckets[i] = 0;

        for ( int i = 0; i < newN; ++i )
            buckets[ ( A[i] >> shift ) & mask ]++;

        for ( int i = 1; i < radix; ++i )
            buckets[i] += buckets[i - 1];

        for ( int i = newN - 1; i >= 0; i-- )
            B[ --buckets[ ( A[i] >> shift ) & mask ] ] = A[i];

        for ( int i = 0; i < newN; ++i )
            A[i] = B[i];
    }
}

inline bool bit( int n, int i )
{
    return ( n & ( 1 << i ) );
}

int main()
{
    FILE *f = fopen("rocker.in", "r");
    FILE *g = fopen("rocker.out", "w");

    fscanf(f, "%d %d\n", &N, &K);
    fscanf(f, "%s", str);

    int pw = 1 << K;
    int sir = 0;

    for ( int i = 0; i < K; ++i )
    {
        sir = sir * 2 + ( str[i] == 'I' );
    }

    A[ newN++ ] = sir;

    for ( int i = K; i < N; ++i )
    {
        sir = sir * 2 + ( str[i] == 'I' );

        if ( sir & pw )
            sir ^= pw;

        A[ newN++ ] = sir;
    }

   RadixSort();

    for ( int i = 0; i < newN - 1; ++i )
    {
        int sol = 0;

        for ( int j = K - 1; j >= 0; j-- )
        {
            if ( bit( A[i], j ) != bit( A[i + 1], j ) )
                break;
            else
                sol++;
        }

        fprintf(g, "%d\n", sol);
    }

    return 0;
}
