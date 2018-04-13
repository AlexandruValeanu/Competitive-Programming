#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

using namespace std;

const int Lmax = 2e6 + 3;

map <string, int> MAP;

char S[Lmax];
char SS[2 * Lmax];
int pi[2 * Lmax];
int d[2 * Lmax];
int T, N;

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

void KMP()
{
    int lgprefix = 0;

    for ( int i = 1; i <= 2 * N; ++i )
    {
        while ( lgprefix > 0 && SS[i] != S[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( SS[i] == S[lgprefix + 1] )
            lgprefix++;

        d[i] = lgprefix;
    }
}

int valid_pal()
{
    int i = 1, j = 2 * N;

    while ( i < j )
    {
        if ( SS[i] != SS[j] )
                return 0;

        i++;
        j--;
    }

    return 1;
}

int main()
{
   /// ifstream in("data.in");

    cin >> T;

    int sol = 0;

    for ( int t = 1; t <= T; ++t )
    {
        cin >> N >> ( S + 1 );

        for ( int i = 1; i <= N; ++i )
        {
            SS[i] = SS[i + N] = S[i];
        }

        sol += valid_pal();

        build_prefix();
        KMP();

        int count = 0;

        for ( int i = 1; i <= 2 * N; ++i )
        {
            if ( d[i] == N )
                    count++;

            if ( count == 2 )
            {
                string s;

                for ( int j = 1; j <= i - N; ++j )
                {
                    s.push_back( S[j] );
                }

                MAP[s]++;

                break;
            }
        }
    }

    for ( map <string, int>::iterator it = MAP.begin(); it != MAP.end(); ++it )
    {
        sol += (*it).second * ( (*it).second - 1 );
    }

    cout << sol << "\n";

    return 0;
}
