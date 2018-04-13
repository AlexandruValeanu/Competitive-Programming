#include <bits/stdc++.h>

using namespace std;

void selection_sort(int A[], int l, int r)
{
    for (int i = l; i < r; ++i)
    {
        int p = i;

        for (int j = i + 1; j <= r; ++j)
            if (A[j] < A[p])
                p = j;

        swap(A[i], A[p]);
    }
}

int main()
{
    return 0;
}
