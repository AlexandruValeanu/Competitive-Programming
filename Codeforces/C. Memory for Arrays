#include <bits/stdc++.h>

using namespace std;

inline int readNumber()
{
    register int a = 0;
    char ch;

    do
    {
        ch = getchar();

    } while ( !isdigit(ch) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar();

    } while ( isdigit(ch) );

    return a;
}

const int Nmax = 1e6 + 1;

int a[31], b[Nmax];
int N, M;

int main()
{
    ///freopen("data.in", "r", stdin);

    N = readNumber(); M = readNumber();

    for ( int i = 1; i <= N; ++i )
    {
        int val = readNumber();

        for ( int j = 0; j < 30; ++j )
            if ( val & ( 1 << j ) )
                a[j]++;
    }

    for ( int i = 1; i <= M; ++i )
        b[i] = readNumber();

    sort( b + 1, b + M + 1 );

    int sol = 0;

    for ( int i = 1; i <= M; ++i )
    {
        int j = b[i];

        while ( j < 30 && !a[j] ) ++j;

        if ( j < 30 )
        {
            if ( j == b[i] )
                a[ b[i] ]--;
            else
            {
                for ( int k = b[i]; k < j; ++k )
                    a[k]++;

                a[j]--;
            }

            sol++;
        }
    }

    cout << sol << "\n";

    return 0;
}
