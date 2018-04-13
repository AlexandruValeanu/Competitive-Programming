#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2000;

int sol[Nmax];

int T;
unsigned long long N, K;
unsigned long long L;

unsigned long long cateMaiMici(unsigned long long i, unsigned long long k)
{
    if (k - 1 == 0)
        return 0;

    unsigned long long cate = (k - 1);

    for (int j = 1; j <= N - i; ++j)
    {
        if (cate > L / K)
            return (L + 1);

        cate *= K;
    }

    return cate;
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> T;

    while (T--)
    {
        cin >> N >> K >> L;
        L--;

        memset(sol, 0, sizeof(sol));

        for (int i = 1; i <= N; ++i)
        {
            for (int j = K; j >= 1; j--)
            {
                if (cateMaiMici(i, j) <= L)
                {
                    sol[i] = j;
                    L -= cateMaiMici(i, j);
                    break;
                }
            }
        }

        for (int i = 1; i <= N; ++i)
            cout << sol[i] << " ";

        cout << "\n";
    }

    return 0;
}
