#include <bits/stdc++.h>

using namespace std;

void quicksort(int A[], int l, int r)
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

    quicksort(A, i, r);
    quicksort(A, l, j);
}

int main()
{
    srand(time(nullptr));

    return 0;
}
