#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100 + 1;

int A[Nmax][Nmax];
int N, K;

int verif(int culoare)
{
    int m = +1e9;
    int M = -1e9;

    for ( int i = 1; i <= N; ++i )
    {
        int c = 0;

        for ( int j = 1; j <= A[i][0]; ++j )
            c += (A[i][j] == culoare);

        m = min(m, c);
        M = max(M, c);
    }

    return abs(M - m) <= 1;
}

int main()
{
    cin >> N >> K;

    for ( int i = 1; i <= N; ++i )
        cin >> A[i][0];

    for ( int i = 1; i <= N; ++i )
    {
        int culoare = 1;

        for ( int j = 1; j <= A[i][0]; ++j )
        {
            A[i][j] = culoare;

            if ( ++culoare > K ) culoare = 1;
        }
    }

    for ( int i = 1; i <= K; ++i )
        if ( verif(i) == 0 )
        {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";

    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = 1; j <= A[i][0]; ++j )
            cout << A[i][j] << " ";

        cout << "\n";
    }

    return 0;
}
