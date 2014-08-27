#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e6 + 2;

vector <int> moves;

int grundy[Nmax];

int mex( int state )
{
    if ( grundy[state] != -1 )
        return grundy[state];

    if ( grundy[state] == 0 )
        return grundy[state] = 0;

    char use[20] = {};

    for ( int i = 0; i < moves.size(); ++i )
        if ( state >= moves[i] )
            use[ mex( state - moves[i] ) ] = 1;

    grundy[state] = 0;

    while ( use[ grundy[state] ] )
        grundy[state]++;

    return grundy[state];
}

int main()
{
    int K, L, N;

    cin >> K >> L >> N;

    moves.push_back( 1 );
    moves.push_back( K );
    moves.push_back( L );

    memset( grundy, -1, sizeof( grundy ) );

    for ( int i = 0; i < Nmax; ++i )
        grundy[i] = mex( i );

    while ( N-- )
    {
        int a;

        cin >> a;

        if ( grundy[a] )
            cout << "A";
        else
            cout << "B";
    }

    return 0;
}
