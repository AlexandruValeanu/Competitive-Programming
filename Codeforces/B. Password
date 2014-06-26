#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int Lmax = 1e6 + 2;
const int BASE = 137;

char S[Lmax];
int H[Lmax], Hpow[Lmax];
int N;

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= N; ++i )
        Hpow[i] = Hpow[i - 1] * BASE;

    for ( int i = 1; i <= N; ++i )
        H[i] = H[i - 1] * BASE + S[i];
}

int getHash( int i, int j )
{
    return H[j] - H[i - 1] * Hpow[j - i + 1];
}

int bsearch( int pos )
{
    int l = 1, r = N - pos, sol = 0;

    while ( l <= r )
    {
        int m = ( l + r ) / 2;

        if ( getHash( 1, m ) == getHash( pos, pos + m - 1 ) )
        {
            sol = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return sol;
}

int main()
{
    ///ifstream cin("data.in");

    cin >> ( S + 1 );

    N = strlen( S + 1 );

    pregen();

    int dim = 0;

    for ( int i = 2; i <= N; ++i )
        dim = max( dim, bsearch( i ) );

    for ( int i = dim; i >= 1; --i )
    {
        if ( getHash( 1, i ) == getHash( N - i + 1, N ) )
        {
            for ( int j = 1; j <= i; ++j )
                    cout << S[j];

            return 0;
        }
    }

    cout << "Just a legend\n";

    return 0;
}
