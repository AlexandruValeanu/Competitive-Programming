#include <bits/stdc++.h>

using namespace std;

const int dl[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

const int Nmax = 500 + 1;

int A[Nmax][Nmax];
int D[Nmax][Nmax];
bool isFood[Nmax][Nmax];

int N, M, T;
int L, C, K, S;

int valid(int i, int j)
{
    if (i < 1 || i > N || j < 1 || j > M)
        return 0;

    if (((A[i][j] ^ K) & ((1 << S) - 1)) == ((1 << S) - 1))
        return 1;

    return 0;
}

int main()
{
    ifstream in("panda.in");
    ofstream out("panda.out");

    int p;
    in >> p;

    in >> N >> M >> T;
    in >> L >> C >> K >> S;

    for (int i = 1; i <= T; ++i)
    {
        int x, y;
        in >> x >> y;

        isFood[x][y] = true;
    }

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            in >> A[i][j];

    if (p == 1)
    {
        int sol = 0;

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (i != L || j != C)
                    if (((A[i][j] ^ K) & ((1 << S) - 1)) == ((1 << S) - 1))
                        sol++;

        out << sol << "\n";
    }
    else
    {
        queue< pair<int,int> > Q;
        Q.push({L, C});
        D[L][C] = 1;

        while (Q.empty() == false)
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();

            for (int k = 0; k < 4; ++k)
            {
                int a = x + dl[k];
                int b = y + dc[k];

                if (valid(a, b) && D[a][b] == 0)
                {
                    D[a][b] = D[x][y] + 1;
                    Q.push({a, b});
                }
            }
        }

        int best = numeric_limits<int>::max();

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (isFood[i][j] && D[i][j] > 0)
                    best = min(best, D[i][j]);

        int cont = 0;

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (isFood[i][j] && D[i][j] == best)
                    cont++;

        out << best - 1 << " " << cont << "\n";
    }

    return 0;
}
