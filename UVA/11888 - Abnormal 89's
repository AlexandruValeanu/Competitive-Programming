#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_map>

using namespace std;

const int Lmax = 200000 + 2;

unordered_map <int, int> MAP;

char S[Lmax];
char SS[2 * Lmax];
int P[2 * Lmax];
int T, N;

int Manacher()
{
    int NN = 0;

    SS[ ++NN ] = '$';

    for ( int i = 1; i <= N; ++i )
    {
        SS[ ++NN ] = S[i];
        SS[ ++NN ] = '$';
    }

    int idx = 0, mx = 0;

    for ( int i = 1; i <= NN; ++i )
    {
        if ( mx >= i )
                P[i] = min( mx - i, P[2 * idx - i] );

        while ( i - P[i] - 1 >= 0 && i + P[i] + 1 <= NN && SS[i - P[i] - 1] == SS[i + P[i] + 1] ) P[i]++;

        if ( i + P[i] >= mx )
        {
            mx = i + P[i];
            idx = i;
        }

        MAP[ P[i] ]++;
    }

    int valid = 0;

    for ( int i = 1; i <= NN; ++i )
    {
        if ( P[i] && N - P[i] )
        {
            MAP[ P[i] ]--;

            if ( MAP[ N - P[i] ] )
            {
                valid = 1;
            }

            MAP[ P[i] ]++;
        }
    }

    MAP.clear();

    return valid;
}

int valid_pal( int i, int j )
{
    while ( i < j )
    {
        if ( S[i] != S[j] )
                return 0;

        i++;
        j--;
    }

    return 1;
}

int brute()
{
    for ( int i = 1; i <= N; ++i )
    {
        if ( S[1] == S[i] && S[i + 1] == S[N] )
            if ( valid_pal( 1, i ) && valid_pal( i + 1, N ) )
                return 1;
    }

    return 0;
}

int main()
{
   /// freopen("data.in", "r", stdin);

    scanf("%d\n", &T);

    while ( T-- )
    {
        scanf("%s\n", S + 1);

        N = strlen( S + 1 );

        int m = brute();

        if ( m )
        {
            cout << "alindrome\n";
            continue;
        }

        if ( valid_pal( 1, N ) )
        {
            cout << "palindrome\n";
            continue;
        }

        cout << "simple\n";
    }

    return 0;
}
