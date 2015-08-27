#include <bits/stdc++.h>

using namespace std;

void counting_sort(int A[], int N, int B[], int C[], const int MAX_V)
{
    for (int i = 0; i <= MAX_V; ++i)
        C[i] = 0;

    for (int i = 0; i < N; ++i)
        C[ A[i] ]++;

    for (int i = 1; i <= MAX_V; ++i)
        C[i] += C[i - 1];

    for (int i = N - 1; i >= 0; i--)
        B[ --C[ A[i] ] ] = A[i];

    for (int i = 0; i < N; ++i)
        A[i] = B[i];
}

int main()
{
    return 0;
}
