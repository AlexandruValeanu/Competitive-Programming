#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 256 + 1;

int A[Nmax][Nmax];
int Euler[Nmax];
int N;

int main()
{
    ifstream in("culori.in");
    ofstream out("culori.out");

    in.sync_with_stdio( false );

    in >> N;

    N = 2 * N - 1;

    for ( int i = 1; i <= N; ++i )
        in >> Euler[i];

    for ( int i = N; i >= 1; i-- )
    {
        A[i][i] = 1;

        for ( int j = i + 1; j <= N; ++j )
        {
            if ( ( ( i + j ) % 2 == 0 ) && Euler[i] == Euler[j] )
            {
                for ( int k = i + 1; k <= j - 1; ++k )
                    A[i][j] = ( A[i][j] + A[i + 1][k] * A[k + 1][j] ) % 9901;
            }
        }
    }

    out << A[1][N];

    return 0;
}
