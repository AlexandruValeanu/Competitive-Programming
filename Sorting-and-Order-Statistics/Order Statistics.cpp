#include <bits/stdc++.h>

using namespace std;

void kth_element(int A[], int l, int r, int k)
{
    if (l >= r)
        return;

    int i = l, j = r;
    int p = A[l + rand() % (r - l + 1)];

    do
    {
        while (A[i] < p) i++;
        while (A[j] > p) j--;

        if (i <= j)
        {
            swap(A[i], A[j]);

            i++;
            j--;
        }

    } while (i < j);

    if (i <= k && k <= r)
        kth_element(A, i, r, k);

    if (l <= k && k <= j)
        kth_element(A, l, j, k);
}

int main()
{
    srand(time(nullptr));

    return 0;
}
