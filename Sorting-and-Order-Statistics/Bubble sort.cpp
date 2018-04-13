#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int A[], int l, int r)
{
    bool change;

    do
    {
        change = false;

        for (int i = l; i < r; ++i)
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
                change = true;
            }

    } while (change == true);
}

int main()
{
    return 0;
}
