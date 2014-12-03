#include <bits/stdc++.h>

using namespace std;

const int Nmax = 500000;

int Z[Nmax + 1];
char str[Nmax + 1];
int N;

int main()
{
    ifstream in("bart.in");
    ofstream out("bart.out");

    in >> str;

    N = strlen( str );

    int L = 0, R = 0;

    for ( int i = 1; i < N; ++i )
    {
        if ( i <= R )
            Z[i] = min( R - i + 1, Z[i - L] );

        while ( i + Z[i] < N && str[ Z[i] ] == str[ i + Z[i] ] ) Z[i]++;

        if ( i + Z[i] - 1 > R )
        {
            L = i;
            R = i + Z[i] - 1;
        }
    }

    int printed = 0;

    for ( int i = 0; i < N && !printed; ++i )
        if ( i + Z[i] == N )
        {
            for ( int j = 0; j < i; ++j )
                out << str[j];

            printed = 1;
        }

    if ( !printed )
    {
        for ( int j = 0; j < N; ++j )
            out << str[j];
    }

    return 0;
}
