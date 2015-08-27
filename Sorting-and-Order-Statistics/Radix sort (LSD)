#include <bits/stdc++.h>

using namespace std;

const int MAX_DIGITS = 32;
const int MAX_D = 4;
const int SIZE_RADIX = 1 << (MAX_DIGITS / MAX_D);
const int mask = SIZE_RADIX - 1;

void radix_sort(int A[], int N, int B[], int C[])
{
    for (int d = 0, shift = 0; d < MAX_D; d++, shift += (MAX_DIGITS / MAX_D))
    {
        for (int i = 0; i < SIZE_RADIX; ++i)
            C[i] = 0;

        for (int i = 0; i < N; ++i)
            C[ (A[i] >> shift) & mask ]++;

        for (int i = 1; i < SIZE_RADIX; ++i)
            C[i] += C[i - 1];

        for (int i = N - 1; i >= 0; i--)
            B[ --C[ (A[i] >> shift) & mask ] ] = A[i];

        for (int i = 0; i < N; ++i)
            A[i] = B[i];
    }
}

int main()
{
    return 0;
}
