#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Nmax = 3;
const int Lmax = 1e5 + 2;
const int inf = 0x3f3f3f3f;

/// Cost[i][j] = cel mai lung sufix al lui sir[i] care este prefix al lui sir[i]

char S[Nmax][Lmax];
int Cost[Nmax][Nmax];
int pi[Lmax];
int P[Nmax];
int N;

void build_prefix( char s[] )
{
    int lgprefix = 0;
    int n = strlen( s + 1 );

    pi[1] = 0;

    for ( int i = 2; i <= n; ++i )
    {
        while ( lgprefix && s[i] != s[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( s[i] == s[lgprefix + 1] )
                lgprefix++;

        pi[i] = lgprefix;
    }
}

int KMP_cost( char patt[], char text[] )
{
    int n = strlen( patt + 1 );
    int m = strlen( text + 1 );

    int lgprefix = 0;

    for ( int i = 1; i <= m; ++i )
    {
        while ( lgprefix && text[i] != patt[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( text[i] == patt[lgprefix + 1] )
                lgprefix++;

        if ( lgprefix == n )
                return n;
    }

    return lgprefix;
}

int permutation()
{
    for ( int i = 0; i < N; ++i )
            P[i] = i;

    int maxim = 0;

    do
    {
        int sum = 0;

        for ( int i = 0; i < N - 1; ++i )
                sum += Cost[ P[i] ][ P[i + 1] ];

        if ( sum > maxim )
        {
            maxim = sum;
        }

    } while( next_permutation( P, P + N ) );

    int sum = 0;

    for ( int i = 0; i < N; ++i )
            sum += strlen( S[i] + 1 );

    return sum - maxim;
}

int main()
{
    ///ifstream cin("data.in");

    while ( cin >> ( S[0] + 1 ) )
    {
        N = 3;

        for ( int i = 1; i < N; ++i )
        {
            cin >> ( S[i] + 1 );
        }

        for ( int i = 0; i < N; ++i )
        {
            build_prefix( S[i] );

            for ( int j = 0; j < N; ++j )
            {
                if ( i != j )
                {
                    int kmp = KMP_cost( S[i], S[j] );

                    if ( kmp == strlen( S[i] + 1 ) )
                    {
                        memcpy( S[i], S[N - 1], sizeof( S[N - 1] ) );
                        memset( S[N - 1], 0, sizeof( S[N - 1] ) );

                        N--;
                        i--;
                        break;
                    }
                }
            }
        }

        for ( int i = 0; i < N; ++i )
        {
            build_prefix( S[i] );

            for ( int j = 0; j < N; ++j )
                    if ( i != j )
                        Cost[j][i] = KMP_cost( S[i], S[j] );
        }

        cout << permutation() << "\n";
    }

    return 0;
}
