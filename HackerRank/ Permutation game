#include <bits/stdc++.h>

using namespace std;

const int Nmax = 15;
const int NN = 1 << Nmax;

bool good[NN];
char dp[NN];
int P[Nmax];
int N;

void precompute()
{
    good[0] = 0;

    for ( int i = 1; i < ( 1 << N ); ++i )
    {
        int last = -1;
        int valid = 1;

        for ( int j = 0; j < N; ++j )
        {
            if ( i & ( 1 << j ) )
            {
                if ( last > P[j] )
                    valid = 0;
                else
                    last = P[j];
            }
        }

        good[i] = valid;
    }
}

int min_max( int state )
{
    if ( dp[state] != '2' )
        return dp[state];

    for ( int j = 0; j < N; ++j )
    {
        if ( state & ( 1 << j ) )
        {
            int auxState = state ^ ( 1 << j );

            if ( good[auxState] )
                return dp[state] = '1';
        }
    }

    dp[state] = '0';

    for ( int j = 0; j < N; ++j )
    {
        if ( state & ( 1 << j ) )
        {
            int auxState = state ^ ( 1 << j );

            if ( min_max( auxState ) == '0' )
                dp[state] = '1';
        }
    }

    return dp[state];
}

int main()
{
   /// ifstream cin("data.in");

    int T;

    cin >> T;

    while ( T-- )
    {
        cin >> N;

        for ( int i = 0; i < N; ++i )
            cin >> P[i];

        precompute();

        for ( int i = 0; i < ( 1 << N ); ++i )
            dp[i] = '2';

        if ( min_max( ( 1 << N ) - 1 ) == '1' )
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }

    return 0;
}
