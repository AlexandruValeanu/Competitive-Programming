#include <bits/stdc++.h>

using namespace std;

/**
    Name: Kayles

    Description: Kayles is played with a row of tokens, which represent bowling pins.
                 The row may be of any length. The two players alternate;
                 each player, on his or her turn, may remove either any one pin
                 (a ball bowled directly at that pin), or two adjacent pins (a ball bowled to strike both).

    Strategy: Compute the Sprague-Grundy values for the different lengths of the row.
              After 72 the sequence becomes periodic with 12 as period.
**/

const int Nmax = 100;

int grundy[Nmax];
int query[Nmax];
bool visited[Nmax];

int N;

int mex( int n )
{
    unordered_set <int> Set;

    for ( int i = 1; i <= n; ++i )
    {
        /// dobor pionul i
        Set.insert( grundy[i - 1] ^ grundy[n - i] );

        /// dobor pionii i,i+1
        if ( i + 1 <= n )
            Set.insert( grundy[i - 1] ^ grundy[n - i - 1] );
    }

    int sol = 0;

    while ( Set.find( sol ) != Set.end() )
        sol++;

    return sol;
}

int value_grundy( int n )
{
    if ( n <= 72 )
        return grundy[n];
    else
        return grundy[72 + ( n - 72 ) % 12];
}

int sprague_grundy( vector<int>& nimbers )
{
    int sol = 0;

    for ( auto x: nimbers )
    {
        sol ^= value_grundy( x );
    }

    return sol;
}

int main()
{
    grundy[0] = 0;

    for ( int i = 1; i < 84; ++i )
        grundy[i] = mex( i );

    cin >> N;

    for ( int i = 1; i <= N; ++i )
        cin >> query[i];

    vector<int> nimbers;

    int contor = 0;
    query[N + 1] = 0;

    for ( int i = 1; i <= N + 1; ++i )
        if ( query[i] == 0 )
        {
            if ( contor )
            {
                nimbers.push_back( contor );
                contor = 0;
            }
        }
        else
            contor++;

    if ( sprague_grundy( nimbers ) )
        cout << "First wins\n";
    else
        cout << "Second wins\n";

    return 0;
}
