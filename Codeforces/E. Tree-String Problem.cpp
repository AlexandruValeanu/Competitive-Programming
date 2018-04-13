#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

const int Nmax = 1e5 + 2;
const int Lmax = 3e5 + 2;

vector <int> G[Nmax];
string S[Nmax], Pattern;
int N, P, solution;
int pi[Lmax];

void build_prefix()
{
    int lgprefix = 0;

    pi[1] = 0;

    for ( int i = 2; i <= P; ++i )
    {
        while ( lgprefix && Pattern[i] != Pattern[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( Pattern[i] == Pattern[lgprefix + 1] )
            lgprefix++;

        pi[i] = lgprefix;
    }
}

void DFS( int node, int lgprefix )
{
    for ( int i = 1; i < S[node].size(); ++i )
    {
        while ( lgprefix && S[node][i] != Pattern[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( S[node][i] == Pattern[lgprefix + 1] )
            lgprefix++;

        if ( lgprefix == P )
        {
            solution++;
            lgprefix = pi[lgprefix];
        }
    }

    for ( auto vec: G[node] )
        DFS( vec, lgprefix );
}

int main()
{
    ///ifstream cin("data.in");

    cin.sync_with_stdio( false );

    cin >> N;

    for ( int i = 2, a; i <= N; ++i )
    {
        cin >> a >> S[i];
        S[i] = " " + S[i];
        G[a].push_back( i );
    }

    cin >> Pattern;
    Pattern = " " + Pattern;

    P = Pattern.size() - 1;

    int lgprefix = 0;

    build_prefix();
    DFS( 1, lgprefix );

    cout << solution << "\n";

    return 0;
}
