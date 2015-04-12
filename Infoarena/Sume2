#include <bits/stdc++.h>

using namespace std;

const int Nmax = 50000 + 1;

int A[Nmax];
int N;
long long K;

long long nrSume(int S)
{
    long long sol = 0;

    int j = N;

    for (int i = 1; i <= N; ++i)
    {
        while (j >= i && A[i] + A[j] > S) j--;

        if (i <= j)
        {
            sol += j - i + 1;
            sol += j - i;
        }
    }

    return sol;
}

int main()
{
    ifstream in("sume2.in");
    ofstream out("sume2.out");

    in >> N >> K;

    for (int i = 1; i <= N; ++i)
        in >> A[i];

    sort(A + 1, A + N + 1);

    int st = 0, dr = (1 << 21), gasit = -1;

    while (st <= dr)
    {
        int m = (st + dr) / 2;

        if (nrSume(m) >= K)
        {
            gasit = m;
            dr = m - 1;
        }
        else
            st = m + 1;
    }

    assert(gasit != -1);

    out << gasit << "\n";

    return 0;
}
