#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5;
const int DIGITS = 32;
const int R = 32 / DIGITS;
const int radix = ( 1 << R );
const int mask = radix - 1;

int A[Nmax], B[Nmax], buckets[radix];
int N;

void RadixSort()
{
    for ( int d = 0, shift = 0; d < DIGITS; ++d, shift += R )
    {
        for ( int i = 0; i < radix; ++i )
                buckets[i] = 0;

        for ( int i = 0; i < N; ++i )
                ++buckets[ ( A[i] >> shift ) & mask ];

        for ( int i = 1; i < radix; ++i )
                buckets[i] += buckets[i - 1];

        for ( int i = N - 1; i >= 0; i-- )
                B[ --buckets[ ( A[i] >> shift ) & mask ] ] = A[i];

        for ( int i = 0; i < N; ++i )
                A[i] = B[i];
    }
}

int main()
{
    return 0;
}
