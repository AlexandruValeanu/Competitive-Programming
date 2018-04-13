#include <bits/stdc++.h>

using namespace std;

void comb_sort(int A[], int N)
{
    int gap = N;
    float shrink = 1.3;
    bool swapped = true;

    while (gap > 1 || swapped == true)
    {
        gap = int(1.0 * gap / shrink);

        if (gap < 1)
            gap = 1;

        int i = 0;
        swapped = false;

        while (i + gap < N)
        {
            if (A[i] > A[i + gap])
            {
                swap(A[i], A[i + gap]);
                swapped = true;
            }

            i++;
        }
    }
}

int main()
{
    return 0;
}
