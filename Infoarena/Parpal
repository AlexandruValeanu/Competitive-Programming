#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e6 + 2;

char str[Nmax], S[2 * Nmax];
int P[2 * Nmax];
int T, N, NN;

void manacher()
{
    NN = 0;

    S[0] = '@';
    S[ ++NN ] = '$';

    for ( int i = 1; i <= N; ++i )
    {
        S[ ++NN ] = str[i];
        S[ ++NN ] = '$';
    }

    S[NN + 1] = '#';

    int idx = 0, mx = 0;

    for ( int i = 1; i <= NN; ++i )
    {
        if ( mx > i )
            P[i] = min( mx - i, P[2 * idx - i] );
        else
            P[i] = 0;

        while ( S[ i - P[i] - 1 ] == S[ i + P[i] + 1 ] ) P[i]++;

        if ( i + P[i] > mx )
        {
            idx = i;
            mx = i + P[i];
        }
    }
}

int check( int i, int j )
{
    int m = ( i + j ) / 2;

    return ( j - i + 1 <= P[2 * m + 1] );
}

int main()
{
    ifstream in("parpal.in");
    ofstream out("parpal.out");

    ios_base::sync_with_stdio( false );

    in >> T;

    while ( T-- )
    {
        in >> ( str + 1 );
        N = strlen( str + 1 );

        manacher();

        int nrP = 0;
        int i = 1;
        int valid = 1;

        while ( i < N && valid )
        {
            int j = i + 1;

            while ( j <= N && check( i, j ) == 0 )
                j += 2;

            if ( j > N || check( i, j ) == 0 )
                valid = 0;
            else
            {
                nrP++;
                i = j + 1;
            }
        }

        if ( valid )
            out << "DA\n";
        else
            out << "NU\n";
    }

    return 0;
}
