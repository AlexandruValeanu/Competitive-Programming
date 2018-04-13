#include <bits/stdc++.h>

using namespace std;

void stooge_sort(int A[], int lo, int hi) /// O(n^2.7095...)
{
    if (A[lo] > A[hi])
        swap(A[lo], A[hi]);

    int length = hi - lo + 1;

    if (length >= 3)
    {
        stooge_sort(A, lo, hi - length / 3);
        stooge_sort(A, lo + length / 3, hi);
        stooge_sort(A, lo, hi - length / 3);
    }
}

int main()
{
    return 0;
}
