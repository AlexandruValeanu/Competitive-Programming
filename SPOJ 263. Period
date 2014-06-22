#include <iostream>
#include <fstream>

using namespace std;

const int Lmax = 1e6 + 2;

int T, N;
char S[Lmax];
int pi[Lmax];

void build_prefix()
{
    int lgprefix = 0;

    pi[1] = 0;

    for ( int i = 2; i <= N; ++i )
    {
        while ( lgprefix > 0 && S[i] != S[ lgprefix + 1 ] )
                    lgprefix = pi[ lgprefix ];

        if ( S[i] == S[ lgprefix + 1 ] )
                lgprefix++;

        pi[i] = lgprefix;
    }
}

int main()
{
    ///ifstream in("data.in");

    cin >> T;

    for ( int k = 1; k <= T; ++k )
    {
        cin >> N >> ( S + 1 );

        build_prefix();

        cout << "Test case #" << k << "\n";

        for ( int i = 2; i <= N; ++i )
        {
            if ( pi[i] && ( i % ( i - pi[i] ) == 0 ) )
            {
                cout << i << " " << i / ( i - pi[i] ) << "\n";
            }
        }

        if ( k < T ) cout << "\n";
    }

    return 0;
}
