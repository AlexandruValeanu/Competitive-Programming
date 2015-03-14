#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100 + 1;
const double EPS = 1e-10;

double A[Nmax][2 * Nmax];
int N;

void make_matrix()
{
    for ( int i = 1; i <= N; ++i )
        A[i][N + i] = 1;
}

void gaussian()
{
    int i = 1, j = 1;

    while (i <= N && j <= 2 * N)
    {
        int x = 0;

        for ( int k = i; k <= N; ++k )
        {
            if ( A[k][j] > EPS || A[k][j] < -EPS )
            {
                x = k;
                break;
            }
        }

        if ( !x )
        {
            j++;
            continue;
        }

        swap(A[i], A[x]);

        for ( int k = j + 1; k <= 2 * N; ++k )
            A[i][k] /= A[i][j];

        A[i][j] = 1;

        for ( int l = i + 1; l <= N; ++l )
        {
            for ( int c = j + 1; c <= 2 * N; ++c )
                A[l][c] -= A[i][c] * A[l][j];

            A[l][j] = 0;
        }

        i++; j++;
    }
}

void reduce_row()
{
    for ( int i = N; i >= 1; i-- )
        for ( int j = i; j <= N; ++j )
            if ( i != j && (A[i][j] > EPS || A[i][j] < -EPS) )
            {
                double z = A[i][j];

                for ( int k = 1; k <= 2 * N; ++k )
                    A[i][k] -= z * A[j][k];
            }
}

bool checkIfInvertible()
{
    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
            if ( (A[i][j] > EPS || A[i][j] < -EPS) && i != j )
                return false;

    return true;
}

int main()
{
    cin >> N;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
            cin >> A[i][j];

    make_matrix();
    gaussian();
    reduce_row();

    if ( checkIfInvertible() == true )
    {
        for ( int i = 1; i <= N; ++i, cout << endl )
            for ( int j = N + 1; j <= 2 * N; ++j )
            {
                cout << fixed << setprecision(2);
                cout << A[i][j] << " \t";
            }
    }
    else
        cout << "Not invertible\n";

    return 0;
}
