#include <bits/stdc++.h>

using namespace std;

void bogosort(int A[], int N) ///O((n+1)!)
{
    srand(time(nullptr));
    bool stop;

    do
    {
        random_shuffle(A, A + N);

        stop = true;

        for (int i = 1; i < N && stop == true; ++i)
            if (A[i - 1] > A[i])
                stop = false;

    } while (stop == false);
}

int main()
{
    return 0;
}
