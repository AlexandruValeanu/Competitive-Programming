#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int A[], int l, int r)
{
    for (int i = l + 1; i <= r; ++i)
    {
        int j = i;

        while (j > l && A[j - 1] > A[j])
        {
            swap(A[j - 1], A[j]);
            j--;
        }
    }
}

int main()
{
    return 0;
}
