#include <bits/stdc++.h>

using namespace std;

const int Nmax = 300 + 2;

char A[Nmax];
int D[Nmax][Nmax];
int P[Nmax];
int N;

int main()
{
    ios_base::sync_with_stdio( false );

    cin >> N;

    for ( int i = 1; i <= N; ++i )
        cin >> P[i];

    for ( int i = 1; i <= N; ++i )
    {
        cin >> ( A + 1 );

        for ( int j = 1; j <= N; ++j )
            D[i][j] = A[j] - '0';
    }

    for ( int k = 1; k <= N; ++k )
        for ( int i = 1; i <= N; ++i )
            for ( int j = 1; j <= N; ++j )
                D[i][j] |= ( D[i][k] & D[k][j] );

    for ( int k = 1; k <= N; ++k )
        for ( int i = 1; i <= N; ++i )
            for ( int j = i + 1; j <= N; ++j )
                if ( D[i][j] && P[i] > P[j] )
                    swap( P[i], P[j] );

    for ( int i = 1; i <= N; ++i )
        cout << P[i] << " ";

    return 0;
}
