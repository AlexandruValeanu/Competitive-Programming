#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
const ull BASE = 666013;

const int Lmax = 5e3 + 2;

char S[Lmax];
int N, Q;

int D[Lmax][Lmax];

ull H1[Lmax];
ull H2[Lmax];
ull Hpow[Lmax];

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= N; ++i )
        Hpow[i] = Hpow[i - 1] * BASE;

    for ( int i = 1; i <= N; ++i )
    {
        H1[i] = H1[i - 1] * BASE + S[i];
        H2[i] = H2[i - 1] * BASE + S[N - i + 1];
    }
}

ull getHash( ull H[], int i, int j )
{
    return H[j] - H[i - 1] * Hpow[j - i + 1];
}

int isPal( int i, int j )
{
    return getHash( H1, i, j ) == getHash( H2, N - j + 1, N - i + 1 );
}

void compute_dp()
{
    for ( int i = N; i >= 1; i-- )
    {
        D[i][i] = 1;

        for ( int j = i + 1; j <= N; ++j )
        {
            D[i][j] = D[i + 1][j] + D[i][j - 1] - D[i + 1][j - 1] + isPal( i, j );
        }
    }
}

int main()
{
    ///ifstream cin("data.in");

    cin.sync_with_stdio( false );

    cin >> ( S + 1 );
    N = strlen( S + 1 );

    pregen();
    compute_dp();

    cin >> Q;

    while ( Q-- )
    {
        int x, y;

        cin >> x >> y;
        cout << D[x][y] << "\n";
    }

    return 0;
}
