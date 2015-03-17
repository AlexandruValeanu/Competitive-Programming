#include <bits/stdc++.h>

using namespace std;

ifstream in("invsort.in");
ofstream out("invsort.out");

const int Nmax = 32000 + 1;

int v[Nmax], A[Nmax], B[Nmax], pos[Nmax];
int N;

void Sort01(int st, int dr)
{
    if (st == dr)
        return;

    int m = (st + dr) / 2;
    int i, j;

    Sort01(st, m);
    Sort01(m + 1, dr);

    for (j = m + 1; (j <= dr) && !v[j]; j++);
    for (i = m; (i >= st) && v[i]; i--);

    i++;
    j--;

	if ( !(i < j) ) return;

    out << i << " " << j << "\n";

    while ( i < j )
    {
        swap(v[i], v[j]);
        swap(A[i], A[j]);
        i++;
        j--;
    }
}

void Sort(int st, int dr)
{
    if (st >= dr)
        return;

    int m = (st + dr) / 2;
    int p = A[m];
    int posPivot = 0;

    for (int i = st; i <= dr; ++i)
        if (A[i] < p)
            v[i] = 0;
        else
            v[i] = 1;

    Sort01(st, dr);

    for (int i = st; i <= dr && !posPivot; ++i)
        if (A[i] == p)
            posPivot = i;

    Sort(st, posPivot - 1);
    Sort(posPivot + 1, dr);
}

int cmp(int a, int b)
{
    if (A[a] == A[b])
        return a < b;
    else
        return A[a] < A[b];
}

int main()
{
    in >> N;

    for (int i = 1; i <= N; ++i)
    {
        in >> A[i];
        pos[i] = i;
    }

    sort(pos + 1, pos + N + 1, cmp);

    for (int i = 1; i <= N; ++i)
        A[ pos[i] ] = i;

    Sort(1, N);

    return 0;
}
