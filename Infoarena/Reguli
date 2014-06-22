#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/// cea mai scurta perioada pe sirul diferentelor dintre 2 termeni consecutivi

const int Lmax = 5e5 + 2;

long long Text[Lmax];
int pi[Lmax];
int N;

void build_prefix()
{
    int lgprefix = 0;

    pi[1] = 0;

    for ( int i = 2; i <= N; ++i )
    {
        while ( lgprefix > 0 && Text[i] != Text[ lgprefix + 1 ] )
                    lgprefix = pi[ lgprefix ];

        if ( Text[i] == Text[ lgprefix + 1 ] )
                lgprefix++;

        pi[i] = lgprefix;
    }
}

int main()
{
    ifstream in("reguli.in");
    ofstream out("reguli.out");

    in >> N;

    for ( long long i = 1, last = 0, x; i <= 1LL * N; ++i )
    {
        in >> x;

        if ( i != 1 ) Text[i - 1] = x - last;
        last = x;
    }

    N--;

    build_prefix();

    out << N - pi[N] << "\n";

    for ( int i = 1; i <= N - pi[N]; ++i )
            out << Text[i] << "\n";

    out << "\n";

    in.close();
    out.close();

    return 0;
}
