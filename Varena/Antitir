#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000000 + 1;

int X[Nmax];
int Y[Nmax];

int N;
long long sol;

int modul(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int main()
{
    freopen("antitir.in", "r", stdin);
    freopen("antitir.out", "w", stdout);

    scanf("%d ", &N);

    for (int i = 1; i <= N; ++i)
        scanf("%d %d ", &X[i], &Y[i]);

    int M = (N + 1) / 2;

    nth_element(X + 1, X + M, X + N + 1);
    nth_element(Y + 1, Y + M, Y + N + 1);

    for (int i = 1; i <= N; ++i)
    {
        sol += modul(X[i] - X[M]);
        sol += modul(Y[i] - Y[M]);
    }

    cout << sol;

    return 0;
}
