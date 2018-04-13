#include <bits/stdc++.h>

using namespace std;

void shell_sort(int A[], int n)
{
    const int gaps[] = {1, 2, 4, 8, 21, 56, 149, 404, 1098, 2982, 8104, 22027, 59875, 162756, 442414}; ///James A. Sellers sequence

    for (int p = 14; p >= 0; p--)
    {
        int gap = gaps[p];

        for (int i = gap; i < n; ++i)
        {
            int temp = A[i];
            int j = i;

            while (j >= gap && A[j - gap] > temp)
            {
                A[j] = A[j - gap];
                j -= gap;
            }

            A[j] = temp;
        }
    }
}

int main()
{
    return 0;
}
