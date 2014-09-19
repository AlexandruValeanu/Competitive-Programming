#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e7 + 5;

char dp[Nmax];
char A[Nmax];

string v[] = { "input", "output", "one", "puton", "in", "out" };
int T, N;

int sePoate( int j, int pos )
{
    if ( j + v[pos].size() - 1 > N )
        return false;

    for ( int i = 0; i < v[pos].size(); ++i )
        if ( A[i + j] != v[pos][i] )
            return false;

    return true;
}

int main()
{
    scanf("%d\n", &T);

    while ( T-- )
    {
        scanf("%s", A + 1);

        N = strlen( A + 1 );

        memset( dp, 0, sizeof( char ) * ( N + 3 ) );

        dp[0] = 1;

        for ( int i = 0; i < N; ++i )
        {
            if ( dp[i] )
            {
                for ( int j = 0; j < 6; ++j )
                {
                    if ( sePoate( i + 1, j ) )
                            dp[i + v[j].size()] = 1;
                }
            }
        }

        if ( dp[N] )
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
