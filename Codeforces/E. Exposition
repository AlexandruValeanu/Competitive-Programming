#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 1;
const int LgMax = 18;

int rmqMin[LgMax][Nmax], rmqMax[LgMax][Nmax];
int LOG[Nmax];
int sol[Nmax];
int N, K;

void build()
{
    for (int i = 1; (1 << i) <= N; ++i)
    {
        for (int j = 1; j + (1 << i) - 1 <= N; ++j)
        {
            int p = 1 << (i - 1);

            rmqMin[i][j] = min(rmqMin[i - 1][j], rmqMin[i - 1][j + p]);
            rmqMax[i][j] = max(rmqMax[i - 1][j], rmqMax[i - 1][j + p]);
        }
    }

    for (int i = 2; i <= N; ++i)
        LOG[i] = LOG[i >> 1] + 1;
}

int getMax(int x, int y)
{
    int k = LOG[y - x + 1];
    int p = (1 << k);
    int sh = (y - x + 1) - p;

    return max(rmqMax[k][x], rmqMax[k][y - (1 << k) + 1]);
}

int getMin(int x, int y)
{
    int k = LOG[y - x + 1];

    return min(rmqMin[k][x], rmqMin[k][y - (1 << k) + 1]);
}

int main()
{
    //ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        cin >> rmqMin[0][i];
        rmqMax[0][i] = rmqMin[0][i];
    }

    build();

    int dMax = 0, cnt = 0;

    for (int i = 1; i <= N; ++i)
    {
        int st = i, dr = N, gasit = 0, mij;

        while (st <= dr)
        {
            mij = (st + dr) / 2;

            int m = getMin(i, mij);
            int M = getMax(i, mij);

            if (M - m <= K)
            {
                gasit = mij;
                st = mij + 1;
            }
            else
                dr = mij - 1;
        }

        int s = gasit - i + 1;
        sol[i] = s;

        if (dMax < s)
        {
            dMax = s;
            cnt = 1;
        }
        else if (dMax == s)
            cnt++;
    }

    cout << dMax << " " << cnt << "\n";

    for (int i = 1; i <= N; ++i)
        if (sol[i] == dMax)
            cout << i << " " << i + dMax - 1 << "\n";

    return 0;
}
