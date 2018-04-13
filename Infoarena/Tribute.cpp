#include <bits/stdc++.h>

using namespace std;

const int MAX_C = 50000;

int visX[MAX_C + 1];
int visY[MAX_C + 1];

int DX, DY;
int N;

int solve(int vis[], int delta)
{
    int st = 0, dr = delta;
    int sol = 0;

    for (int i = 0; i <= MAX_C; ++i)
    {
        if (vis[i] && (i < st || dr < i))
            sol += vis[i] * min(abs(i - st), abs(i - dr));
    }

    int nrStanga = 0;
    int nrDreapta = 0;
    int sumStanga = 0;
    int sumDreapta = 0;

    for (int i = dr + 1; i <= MAX_C; ++i)
    {
        nrDreapta += vis[i];
        sumDreapta += vis[i] * abs(i - dr);
    }

    while (dr + 1 <= MAX_C)
    {
        sumStanga += nrStanga * 1;
        sumStanga += vis[st];
        nrStanga += vis[st];
        st++;

        sumDreapta -= nrDreapta;
        nrDreapta -= vis[dr + 1];
        dr++;

        sol = min(sol, sumStanga + sumDreapta);
    }

    return sol;
}

int main()
{
    ifstream in("tribute.in");
    ofstream out("tribute.out");

    in >> N >> DX >> DY;

    for (int i = 1; i <= N; ++i)
    {
        int x, y;
        in >> x >> y;
        visX[x]++;
        visY[y]++;
    }

    out << solve(visX, DX) + solve(visY, DY) << "\n";

    return 0;
}
