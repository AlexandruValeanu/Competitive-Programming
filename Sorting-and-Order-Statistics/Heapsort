#include <bits/stdc++.h>

using namespace std;

void max_heapify(int H[], int N, int i)
{
    int l, r, largest;
    bool changed;

    do
    {
        changed = false;

        l = 2 * i;
        r = 2 * i + 1;

        if (l <= N && H[l] > H[i])
            largest = l;
        else
            largest = i;

        if (r <= N && H[r] > H[largest])
            largest = r;

        if (i != largest)
        {
            swap(H[i], H[largest]);
            i = largest;
            changed = true;
        }

    } while (changed == true);
}

void build_max_heap(int H[], int N)
{
    for (int i = N / 2; i >= 1; i--)
        max_heapify(H, N, i);
}

void heapsort(int H[], int N) ///1-based
{
    build_max_heap(H, N);

    for (int i = N; i >= 2; i--)
    {
        swap(H[i], H[1]);
        N--;
        max_heapify(H, N, 1);
    }
}

int main()
{
    return 0;
}
