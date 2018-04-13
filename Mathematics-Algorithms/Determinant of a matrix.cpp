#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100 + 1;
const double EPS = 1e-10;

double A[Nmax][Nmax];
int N;

double gaussian()
{
    int i = 1, j = 1;
    double det = 1;

    while (i <= N && j <= N)
    {
        int x = 0;

        for ( int k = i; k <= N; ++k )
            if ( A[k][j] > EPS || A[k][j] < -EPS )
            {
                x = k;
                break;
            }

        if ( !x )
        {
            j++;
            continue;
        }

        swap(A[i], A[x]);

        det *= A[i][j];

        for ( int k = j + 1; k <= N; ++k )
            A[i][k] /= A[i][j];

        A[i][j] = 1;

        for ( int l = i + 1; l <= N; ++l )
        {
            for ( int c = j + 1; c <= N; ++c )
                A[l][c] -= A[i][c] * A[l][j];

            A[l][j] = 0;
        }

        i++; j++;
    }

    return det;
}

int main()
{
    cin >> N;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
            in >> A[i][j];

    cout << gaussian() << "\n";

    return 0;
}
