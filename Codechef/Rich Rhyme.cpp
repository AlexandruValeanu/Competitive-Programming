#include <iostream>
#include <cstring>

using namespace std;

const int Lmax = 4e6 + 2;

char S[Lmax];
int pi[Lmax];
int N;

void build_prefix()
{
    pi[1] = 0;

    int lgprefix = 0;

    for ( int i = 2; i <= N; ++i )
    {
        while ( lgprefix && S[i] != S[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( S[i] == S[lgprefix + 1] )
            lgprefix++;

        pi[i] = lgprefix;
    }
}

int main()
{
    while ( cin >> ( S + 1 ) )
    {
        N = strlen( S + 1 );

        if ( N == 3 && S[1] == 'E' ) break;

        build_prefix();

        for ( int i = 1; i <= N; ++i )
                cout << pi[i] << " ";

        cout << "\n";
    }

    return 0;
}
