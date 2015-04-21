#include <bits/stdc++.h>

using namespace std;

const int Nmax = 200000;

int X[Nmax], Y[Nmax];
int T, N, A, B;

long long solve(int v[])
{
    sort(v, v + N);

    long long sol = 0;
    long long sum_prev = 0;

    for (int i = 0; i < N; ++i)
    {
        sol += 1LL * v[i] * i - sum_prev;
        sum_prev += (long long)v[i];
    }

    return sol;
}

int main()
{
    ///freopen("data.in", "r", stdin);

    scanf("%d ", &T);

    while (T--)
    {
        scanf("%d %d %d ", &N, &A, &B);

        for (int i = 0; i < N; ++i)
        {
            scanf("%d ", &X[i]);
            scanf("%d ", &Y[i]);

            int new_x = A * X[i] + B * Y[i];
            int new_y = A * X[i] - B * Y[i];

            X[i] = new_x;
            Y[i] = new_y;
        }

        printf("%lld\n", (solve(X) + solve(Y)) / 2);
    }

    return 0;
}
