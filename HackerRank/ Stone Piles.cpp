#include <bits/stdc++.h>

using namespace std;

const int Nmax = 50 + 2;

int grundy[Nmax];
int stiva[Nmax];
unordered_set <int> Set;

void bkt( int nr, int k )
{
    if ( nr == 0 )
    {
        if ( k == 2 ) return;

        int value = 0;

        for ( int i = 1; i < k; ++i )
            value ^= grundy[ stiva[i] ];

        Set.insert( value );
    }
    else
    {
        for ( int i = stiva[k - 1] + 1; i <= nr; ++i )
        {
            stiva[k] = i;
            bkt( nr - i, k + 1 );
        }
    }
}

int mex( int state )
{
    if ( grundy[state] != -1 )
        return grundy[state];

    if ( state <= 2 )
        return grundy[state] = 0;

    Set.clear();

    bkt( state, 1 );

    grundy[state] = 0;

    while ( Set.count( grundy[state] ) )
        grundy[state]++;

    return grundy[state];
}

int main()
{
    memset( grundy, -1, sizeof( grundy ) );

    for ( int i = 1; i <= 50; ++i )
        grundy[i] = mex( i );

    int T, N;

    cin >> T;

    while ( T-- )
    {
        cin >> N;

        int xorsum = 0;

        for ( int i = 1, a; i <= N; ++i )
        {
            cin >> a;
            xorsum ^= grundy[a];
        }

        if ( xorsum )
            cout << "ALICE\n";
        else
            cout << "BOB\n";
    }

    return 0;
}
