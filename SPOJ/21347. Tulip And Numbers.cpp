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

const int Nmax = 100000 + 1;

int process[Nmax];
int tests, N, M;

int main()
{
    tests = readNumber();

    for ( int k = 1; k <= tests; ++k )
    {
        N = readNumber(); M = readNumber();

        int last = 0;

        for ( int i = 1; i <= N; ++i )
        {
            int val = readNumber();

            if ( last == val )
                process[i] = process[i - 1];
            else
                process[i] = process[i - 1] + 1;

            last = val;
        }

        printf("Case %d:\n", k);

        while ( M-- )
        {
            int a, b, c = 0;
            a = readNumber(); b = readNumber();

            if ( process[a] == process[a - 1] )
                c++;

            printf("%d\n", process[b] - process[a - 1] + c );
        }
    }


    return 0;
}
