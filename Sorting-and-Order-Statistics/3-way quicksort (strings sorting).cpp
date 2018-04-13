#include <bits/stdc++.h>

using namespace std;

void ternary_quicksort(char **S, int lo, int hi, int kth)
{
    if (lo >= hi)
        return;

    int p = lo;
    int st = lo;
    int dr = hi;

    char charMid = (S[lo][kth] + S[hi][kth]) / 2;

    while (p <= dr)
    {
        char c = S[p][kth];

        if (c < charMid)
        {
            swap(S[st], S[p]);
            st++;
            p++;
        }
        else if (c > charMid)
        {
            swap(S[dr], S[p]);
            dr--;
        }
        else
            p++;
    }

    ternary_quicksort(S, lo, st - 1, kth);

    if (S[st][kth] != '\0')
        ternary_quicksort(S, st, dr, kth + 1);

    ternary_quicksort(S, dr + 1, hi, kth);
}

int main()
{
    return 0;
}
