#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int Lmax = 1e6 + 2;

char S[Lmax];
char SS[2 * Lmax];
int pi[2 * Lmax];
int d[2 * Lmax];
int N;

void build_prefix()
{
    int lgprefix = 0;

    pi[1] = 0;

    for ( int i = 2; i <= N; ++i )
    {
        while ( lgprefix > 0 && S[i] != S[ lgprefix + 1 ] )
                    lgprefix = pi[lgprefix];

        if ( S[i] == S[ lgprefix + 1 ] )
                lgprefix++;

        pi[i] = lgprefix;
    }
}

void KMP()
{
    int lgprefix = 0;

    for ( int i = 1; i <= 2 * N; ++i )
    {
        while ( lgprefix > 0 && SS[i] != S[ lgprefix + 1 ] )
                    lgprefix = pi[lgprefix];

        if ( SS[i] == S[ lgprefix + 1 ] )
                lgprefix++;

        d[i] = lgprefix;
    }
}

int main()
{
    ///ifstream in("data.in");

    while ( 1 )
    {
        cin >> ( S + 1 );

        if ( S[1] == '.' && strlen( S + 1 ) == 1 ) break;

        N = strlen( S + 1 );

        for ( int i = 1; i <= N; ++i )
        {
            SS[i] = SS[i + N] = S[i];
        }

        build_prefix();
        KMP();

        int count = 0;

        for ( int i = 1; i <= 2 * N; ++i )
        {
            if ( d[i] == N )
                    count++;

            if ( count == 2 )
            {
                cout << N / ( i - N ) << "\n";
                break;
            }
        }
    }

    return 0;
}
