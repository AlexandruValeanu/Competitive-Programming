#include <bits/stdc++.h>

using namespace std;

const int NUMBER_OF_PATTERNS = 64;
const int MAX_LENGTH_PATTERN = 2000;

const int MAX_STATES = MAX_LENGTH_PATTERN * NUMBER_OF_PATTERNS;
const int SIGMA = 26;
const int NIL = -1;

int go[MAX_STATES][SIGMA];  /// goto function
int fail[MAX_STATES];         /// fail function
long long output[MAX_STATES]; ///  out function

string Text, Pattern;
int dimPatterns[NUMBER_OF_PATTERNS], sol[NUMBER_OF_PATTERNS];
int N; /// number of patterns

int states;

void initAutomaton()
{
    states = 1; /// Initially, we have 1 state

    memset( go, NIL, sizeof( go ) );
    memset( fail, NIL, sizeof( fail ) );
    memset( output, 0, sizeof( output ) );
}

void addString( const string &str, int i )
{
    int currentState = 0;

    for ( auto x: str )
    {
        if ( go[currentState][x - 'a'] == NIL ) /// Allocate a new node
            go[currentState][x - 'a'] = states++;

        currentState = go[currentState][x - 'a'];
    }

    output[currentState] |= ( 1LL << i );
}

int findNextState( int state, int c )
{
    while ( go[state][c] == -1 ) state = fail[state];

    return go[state][c];
}

void buildAutomaton()
{
    for ( int c = 0; c < SIGMA; ++c )
        if ( go[0][c] == -1 )
            go[0][c] = 0;

    queue <int> Q;

    for ( int c = 0; c < SIGMA; ++c )
        if ( go[0][c] != NIL && go[0][c] != 0 )
        {
            fail[ go[0][c] ] = 0;
            Q.push( go[0][c] );
        }

    while ( Q.empty() == false )
    {
        int state = Q.front();
        Q.pop();

        for ( int c = 0; c < SIGMA; ++c )
            if ( go[state][c] != NIL )
            {
                int fail_state = fail[state];

                fail_state = findNextState( fail_state, c );

                fail[ go[state][c] ] = fail_state;
                output[ go[state][c] ] |= output[fail_state];

                Q.push( go[state][c] );
            }
    }
}

void match( const string &str )
{
    int currentState = 0;

    for ( int i = 0; i < str.size(); ++i )
    {
        currentState = findNextState( currentState, str[i] - 'a' );

        if ( output[currentState] == 0 )
            continue;

        for ( int j = 0; j < N; ++j )
            if ( output[currentState] & ( 1LL << j ) )
                sol[j]++;
    }
}

int main()
{

    return 0;
}
