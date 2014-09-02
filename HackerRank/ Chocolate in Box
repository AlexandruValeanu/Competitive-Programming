#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e6 + 2;

int N;
int A[Nmax];

int main()
{
    cin >> N;

    for ( int i = 1; i <= N; ++i )
        cin >> A[i];

    int xorsum = 0;

    for ( int i = 1; i <= N; ++i )
        xorsum ^= A[i];

    if ( xorsum == 0 )
        cout << "0\n";
    else
    {
        int nrMoves = 0;

        for ( int i = 1; i <= N; ++i )
        {
            int size = A[i] - ( xorsum ^ A[i] );

            if ( 1 <= size && size <= A[i] )
                nrMoves++;
        }

        cout << nrMoves << "\n";
    }

    return 0;
}
