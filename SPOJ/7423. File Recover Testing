#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int Lmax = 1e6 + 2;

char S[Lmax];
int pi[Lmax];
int N, K;

void build_prefix()
{
    int lgprefix = 0;

    pi[1] = 0;

    for ( int i = 2; i <= N; ++i )
    {
        while ( lgprefix > 0 && S[i] != S[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( S[i] == S[lgprefix + 1] )
            lgprefix++;

        pi[i] = lgprefix;
    }
}

int main()
{
    ///ifstream cin("data.in");

    while ( 1 )
    {
        cin >> K >> ( S + 1 );

        if ( K == -1 ) break;

        N = strlen( S + 1 );

        build_prefix();

        int period = N - pi[N];

        if ( K == N )
        {
            cout << "1\n";
            continue;
        }

        if ( K < N )
        {
            cout << "0\n";
            continue;
        }

        cout << 1 + ( K - N ) / ( N - pi[N] ) << "\n";
    }

    return 0;
}
