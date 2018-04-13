#include <bits/stdc++.h>

using namespace std;

void shell_sort(int A[], int n)
{
    const int gaps[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750}; ///Marcin Ciura's gap sequence

    for (int p = 8; p >= 0; p--)
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
