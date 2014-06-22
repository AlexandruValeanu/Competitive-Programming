#include <iostream>
#include <cstring>

using namespace std;

const int Lmax = 100;

/// SHORTEST PERIOD OF A STRING

/**
    Definitions:

        ^(k) - concatenate k times
        ^ - concatenate
        S - initial string
        P - period
        N - length of S

        Period = shortest substring for which P^k = S;
    ex:
        S: abababab
        P: ab

    Solution:

        We concatenate S to itself. Let's call it SS.

        The period has an important property if we cut its first appearance in S
        and add it to the end we get the original string.

        So, finding a period is equal to finding a number k so S[k...N] ^ S[1, k] == S.
        Because of the way we built SS any substring of length N will be equal to S[k...N] ^ S[1...k]. ( k - position )
        So, in order to find the period we need to find the SECOND appearance of S in SS( the first one is the string itself ).

        The length of the period is the position of the second appearance.

    ex:
        S: abab
        SS: abababab
        P: ab
        N = 4

        pos  = 1 2 3 4 5 6 7 8
        pi[] = 0 0 1 2
         d[] = 1 2 3 4 3 4 3 4

        The matches are at 4, 6, 8.
        The length of the period is 6 - 4 = 2.
**/

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
                    lgprefix = pi[ lgprefix ];

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
    cin >> ( S + 1 );

    N = strlen( S + 1 );

    for ( int i = 1; i <= N; ++i )
    {
        SS[i] = S[i];
        SS[i + N] = S[i];
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
            cout << i - N << " ";
            break;
        }
    }

    return 0;
}
