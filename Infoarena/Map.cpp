#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int Lmax = 2000 + 2;

char S[Lmax];
int pi[Lmax];
int N, M;

void build_prefix()
{
    int lgprefix = 0;

    pi[1] = 0;

    for ( int i = 2; i <= M; ++i )
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
    ifstream in("map.in");
    ofstream out("map.out");

    in >> N >> M;

    int sol = 0;

    for ( int i = 1; i <= N; ++i )
    {
        in >> ( S + 1 );

        build_prefix();

        int best = M;

        while ( pi[best] > M / 2 )
                    best = pi[best];

        sol = max( sol, best );
    }

    if ( sol )
    {
        out << sol << "\n";
    }
    else
    {
        out << M << "\n";
    }

    return 0;
}
