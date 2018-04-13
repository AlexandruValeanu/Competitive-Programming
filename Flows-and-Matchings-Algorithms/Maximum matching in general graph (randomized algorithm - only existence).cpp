#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int Nmax = 100 + 1;

int tutte[Nmax][Nmax];
int G[Nmax][Nmax];
int T, N, M;

int pw(int a, int p)
{
    int res = 1;

    while (p)
    {
        if (p & 1)
            res = (1LL * a * res) % MOD;

        a = (1LL * a * a) % MOD;
        p >>= 1;
    }

    return res;
}

int determinant()
{
    int i = 1, j = 1;
    int det = 1;

    while (i <= N && j <= N)
    {
        int x = 0;

        for (int k = i; k <= N; ++k)
            if ( tutte[k][j] != 0 )
            {
                x = k;
                break;
            }

        if (!x)
        {
            j++;
            return 0;
        }

        swap(tutte[i], tutte[x]);
        det = (1LL * det * tutte[i][i]) % MOD;

        int inv = pw(tutte[i][j], MOD - 2);

        for (int k = j + 1; k <= N; ++k)
            tutte[i][k] = (1LL * tutte[i][k] * inv) % MOD;

        tutte[i][j] = 1;

        for (int l = i + 1; l <= N; ++l)
        {
            for (int c = j + 1; c <= N; ++c)
                tutte[l][c] = (tutte[l][c] - (1LL * tutte[l][j] * tutte[i][c]) % MOD + MOD) % MOD;

            tutte[l][j] = 0;
        }

        i++; j++;
    }

    return det;
}

int main()
{
    srand(time(NULL));

    cin >> N >> M;

    memset(G, 0, sizeof(G));
    memset(tutte, 0, sizeof(tutte));

    for (int i = 1; i <= M; ++i)
    {
        int a, b;

        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }

    for (int i = 1; i <= N; ++i)
        for ( int j = 1; j < i; ++j)
            if ( G[i][j] )
            {
                int r = 1 + rand() % (MOD - 1);

                tutte[i][j] = r;
                tutte[j][i] = MOD - r;
            }

    if ( determinant() )
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
