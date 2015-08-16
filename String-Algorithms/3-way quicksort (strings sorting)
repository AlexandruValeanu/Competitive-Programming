#include <bits/stdc++.h>

using namespace std;

void quicksort(char **S, int lo, int hi, int kth)
{
    if (lo >= hi)
        return;

    int p = lo;
    int st = lo;
    int dr = hi;

    char midChar = (S[lo][kth] + S[hi][kth]) / 2;

    while (p <= dr)
    {
        char c = S[p][kth];

        if (c < midChar)
        {
            swap(S[p], S[st]);
            st++;
            p++;
        }
        else if (c > midChar)
        {
            swap(S[p], S[dr]);
            dr--;
        }
        else
            p++;
    }

    quicksort(S, lo, st - 1, kth);

    if (S[st][kth] != '\0')
        quicksort(S, st, dr, kth + 1);

    quicksort(S, dr + 1, hi, kth);
}

int main()
{
    FILE *in = fopen("stringsort.in", "r");
    FILE *out = fopen("stringsort.out", "w");

    int N;
    fscanf(in, "%d\n", &N);

    char **S = new char*[N];

    for (int i = 0; i < N; ++i)
    {
        int l;
        fscanf(in, "%d ", &l);

        S[i] = new char[l + 1];

        fscanf(in, "%s\n", S[i]);
    }

    quicksort(S, 0, N - 1, 0);

    for (int i = 0; i < N; ++i)
        fprintf(out, "%s\n", S[i]);

    return 0;
}
