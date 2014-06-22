#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

const int Lmax = 1e7 + 2;

char S[Lmax];
int pi[Lmax];
int N;

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
    cin >> N;
    cin >> ( S + 1 );

    build_prefix();

    int lgprefix = pi[N];
    int sol = 0;

    while ( lgprefix )
    {
        if ( N % ( N - lgprefix ) == 0 )
                sol++;

        lgprefix = pi[lgprefix];
    }

    cout << sol << "\n";

    return 0;
}
