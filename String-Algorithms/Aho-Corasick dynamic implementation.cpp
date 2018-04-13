#include <bits/stdc++.h>

using namespace std;

const int NUMBER_OF_PATTERNS = 1000;
const int SIGMA = 26;

string Text, Pattern;
int dimPatterns[NUMBER_OF_PATTERNS], sol[NUMBER_OF_PATTERNS];
int N;

struct Automaton
{

struct Node
{
    Node *go[SIGMA];
    Node *fail;
    vector <int> output;

    Node()
    {
        fail = NULL;

        for ( int i = 0; i < SIGMA; ++i )
            go[i] = 0;

        output.clear();
    }
};

    Node *root;

    Automaton()
    {
        root = new Node();
    }

    void addString( const string &str, const int ind )
    {
        Node *currentState = root;

        for ( auto x: str )
        {
            if ( currentState->go[x - 'a'] == NULL )
                currentState->go[x - 'a'] = new Node();

            currentState = currentState->go[x - 'a'];
        }

        currentState->output.push_back( ind );
    }

    Node* findNextState( Node *state, int c )
    {
        Node *aux = state;

        while ( aux->go[c] == NULL )
        {
            assert( aux != root );
            aux = aux->fail;
        }

        return aux->go[c];
    }

    void make_output( Node *&state, Node *&aux_state )
    {
        vector <int> v( state->output.size() + aux_state->output.size() );

        merge( state->output.begin(), state->output.end(), aux_state->output.begin(),
               aux_state->output.end(), v.begin() );

        state->output = v;
    }

    void buildAutomaton()
    {
        for ( int c = 0; c < SIGMA; ++c )
        {
            if ( root->go[c] == NULL )
                root->go[c] = root;
        }

        queue <Node*> Q;

        for ( int c = 0; c < SIGMA; ++c )
            if ( root->go[c] != NULL && root->go[c] != root )
            {
                root->go[c]->fail = root;
                Q.push( root->go[c] );
            }

        while ( Q.empty() == false )
        {
            Node *state = Q.front();
            Q.pop();

            for ( int c = 0; c < SIGMA; ++c )
                if ( state->go[c] != NULL )
                {
                    Node *fail_state = state->fail;

                    fail_state = findNextState( fail_state, c );

                    state->go[c]->fail = fail_state;
                    make_output( state->go[c], fail_state );

                    Q.push( state->go[c] );
                }
        }
    }

    void match( const string &str )
    {
        Node *currentState = root;

        for ( auto x: str )
        {
            currentState = findNextState( currentState, x - 'a' );

            for ( auto y: currentState->output )
                sol[y]++;
        }
    }
};

int main()
{
    return 0;
}
