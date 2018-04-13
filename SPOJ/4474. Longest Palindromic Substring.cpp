#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int Lmax = 1e5 + 2;

char S[Lmax];
char SS[2 * Lmax];
int P[2 * Lmax];
int N, NN;

void transform()
{
    NN = 0;

    SS[0] = '!';

    SS[ ++NN ] = '#';

    for ( int i = 1; i <= N; ++i )
    {
        SS[ ++NN ] = S[i];
        SS[ ++NN ] = '#';
    }

    SS[NN + 1] = '@';
}

void Manacher()
{
    int indexOfPalindrome = 0, rightEndOfPalindrome = 0;
    int maximLength = 0;

    for ( int i = 1; i <= NN; ++i )
    {
        if ( rightEndOfPalindrome > i )
            P[i] = min( rightEndOfPalindrome - i, P[2 * indexOfPalindrome - i] );

        while ( SS[i + P[i] + 1] == SS[i - P[i] - 1] ) P[i]++;

        if ( P[i] + i > rightEndOfPalindrome )
        {
            rightEndOfPalindrome = P[i] + i;
            indexOfPalindrome = i;
        }

        maximLength = max( maximLength, P[i] );
    }

    cout << maximLength << "\n";
}

int main()
{
   /// ifstream cin("data.in");

    cin >> N;
    cin >> ( S + 1 );

    transform();
    Manacher();

    return 0;
}
