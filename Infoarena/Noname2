#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

int v[Nmax];
long long sum[Nmax];

int N;
long long K;

long long suma(int i, int j)
{
    if ( i > j )
        return 0;
    else
        return sum[j] - sum[i - 1];
}

int valid(int lg)
{
    int st = 1, dr = lg, median = (lg + 1) / 2;

    while ( dr <= N )
    {
        long long s1 = suma(st, median - 1);
        long long s2 = suma(median + 1, dr);

        int dim1 = (median - 1) - st + 1;
        int dim2 = dr - (median + 1) + 1;

        long long cost = 1LL * dim1 * v[median] - s1 + s2 - 1LL * dim2 * v[median];

        if ( cost <= K )
            return 1;

        st++;
        dr++;
        median++;
    }

    return 0;
}

int main()
{
    ifstream in("noname2.in");
    ofstream out("noname2.out");

    in >> N >> K;

    for ( int i = 1; i <= N; ++i )
        in >> v[i];

    sort(v + 1, v + N + 1);

    for ( int i = 1; i <= N; ++i )
        sum[i] = sum[i - 1] + v[i];

    int st = 1, dr = N, gasit = 0;

    while (st <= dr)
    {
        int m = (st + dr) / 2;

        if ( valid(m) )
        {
            gasit = m;
            st = m + 1;
        }
        else
            dr = m - 1;
    }

    out << gasit << "\n";

    return 0;
}
