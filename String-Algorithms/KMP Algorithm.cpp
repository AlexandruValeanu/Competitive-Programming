#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

const int Lmax = 2e6 + 2;

char Pattern[Lmax];
char Text[Lmax];
int pi[Lmax], d[Lmax];
int P, T;

/// pi[i] = longest prefix of Pattern[1...i] which is also suffix of Pattern[1...i]
///  d[i] = longest prefix of Pattern[1...P] which is also suffix of Text[1...i]

void build_prefix()
{
    int lgprefix = 0; /// the length of the prefix we already matched

    pi[1] = 0;

    for ( int i = 2; i <= P; ++i )
    {
        while ( lgprefix > 0 && Pattern[i] != Pattern[ lgprefix + 1 ] )
                    lgprefix = pi[ lgprefix ];

        if ( Pattern[i] == Pattern[ lgprefix + 1 ] )
                lgprefix++;

        pi[i] = lgprefix;
    }
}

void KMP_algorithm()
{
    int lgprefix = 0; /// same meaning

    for ( int i = 1; i <= T; ++i )
    {
        while ( lgprefix > 0 && Text[i] != Pattern[ lgprefix + 1] )
                    lgprefix = pi[ lgprefix ];

        if ( Text[i] == Pattern[ lgprefix + 1 ] )
                lgprefix++;

        d[i] = lgprefix;
    }
}

void print_match()
{
    ofstream out("data.out");

    vector <int> v;

    for ( int i = 1; i <= T; ++i )
    {
        if ( d[i] == P ) /// we matched P characters
        {
            v.push_back( i - P );
        }
    }

    out << v.size() << "\n";

    for ( int i = 0; i < v.size(); ++i )
            out << v[i] << " ";

    out << "\n";
}

int main()
{
    ifstream in("data.in");

    in >> ( Pattern + 1 );
    in >> ( Text + 1 );

    P = strlen( Pattern + 1 );
    T = strlen( Text + 1 );

    build_prefix();
    KMP_algorithm();
    print_match();

    return 0;
}
