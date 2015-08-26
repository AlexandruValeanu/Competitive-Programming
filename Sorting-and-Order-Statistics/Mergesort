#include <bits/stdc++.h>

using namespace std;

void merge_sort(int A[], int B[], int l, int r)
{
    if (l == r)
        return;

    int m = (l + r) / 2;

    merge_sort(A, B, l, m);
    merge_sort(A, B, m + 1, r);

    int i = l, j = m + 1;
    int k = l;

    while (i <= m && j <= r)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= m)
        B[k++] = A[i++];

    while (j <= r)
        B[k++] = A[j++];

    for (int p = l; p <= r; ++p)
        A[p] = B[p];
}

int main()
{
    return 0;
}
