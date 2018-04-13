#include <bits/stdc++.h>

using namespace std;

void cocktail_sort(int A[], int N) ///bidirectional bubble sort
{
    int begin = -1;
    int end = N - 2;
    bool swapped;

    do
    {
        swapped = false;
        begin++;

        for (int i = begin; i <= end; ++i)
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
                swapped = true;
            }

        if (swapped == false)
            break;

        swapped = false;
        end--;

        for (int i = end; i >= begin; i--)
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
                swapped = true;
            }

    } while (swapped == true);
}

int main()
{
    return 0;
}
