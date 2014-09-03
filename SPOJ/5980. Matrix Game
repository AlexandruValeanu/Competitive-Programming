#include <bits/stdc++.h>

using namespace std;

const int Nmax = 50 + 3;

int A[Nmax][Nmax];
int grundy[Nmax][Nmax];
int T, N, M;

int main()
{
    ///ifstream cin("data.in");

    cin >> T;

    while ( T-- )
    {
        cin >> N >> M;

        for ( int i = 1; i <= N; ++i )
            for ( int j = 1; j <= M; ++j )
                cin >> A[i][j];

        for ( int i = 1; i <= N; ++i )
        {
            grundy[i][M + 1] = 0;

            for ( int j = M; j >= 1; j-- )
            {
                if ( A[i][j] <= grundy[i][j + 1] )
                    grundy[i][j] = A[i][j] - 1;
                else
                    grundy[i][j] = A[i][j];
            }
        }

        int xorsum = 0;

        for ( int i = 1; i <= N; ++i )
            xorsum ^= grundy[i][1];

        if ( xorsum )
            cout << "FIRST\n";
        else
            cout << "SECOND\n";
    }

    return 0;
}
