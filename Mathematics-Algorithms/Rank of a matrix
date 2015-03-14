#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100;
const double EPS = 1e-10;

double A[Nmax][Nmax];
int N, M;

void gaussian()
{
    int i = 1, j = 1;

    while (i <= N && j <= M)
    {
        int x = 0;

        for (int k = i; k <= N; ++k)
            if ( A[k][j] > EPS || A[k][j] < -EPS )
            {
                x = k;
                break;
            }

        if (!x)
        {
            j++;
            continue;
        }

        swap(A[i], A[x]);

        for (int k = j + 1; k <= M; ++k)
            A[i][k] /= A[i][j];

        A[i][j] = 1;

        for (int l = i + 1; l <= N; ++l)
        {
            for (int c = j + 1; c <= M; ++c)
                A[l][c] -= A[i][c] * A[l][j];

            A[l][j] = 0;
        }

        i++; j++;
    }
}

int Rank()
{
    for ( int i = N; i >= 1; i-- )
        if (A[i][i] > EPS || A[i][i] < -EPS)
            return i;

    return 0;
}

int main()
{
    ifstream in("data.in");

    in >> N >> M;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            in >> A[i][j];

    gaussian();

    cout << Rank() << "\n";

    return 0;
}
