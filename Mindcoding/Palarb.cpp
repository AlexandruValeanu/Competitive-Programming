#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

typedef unsigned long long ull;

const ull BASE = 666013;
const int Nmax = 1e5 + 2;

vector <int> G[Nmax];
ull h1[Nmax], h2[Nmax];
char ch[Nmax];
int depth[Nmax];

int N, T;
string str;

void DFS( int nod, int tata, ull B )
{
    h1[nod] = h1[tata] * BASE + ch[nod];
    h2[nod] = h2[tata] + ch[nod] * B;
    depth[nod] = depth[tata] + 1;

    for ( auto vec: G[nod] )
    {
        if ( vec != tata )
            DFS( vec, nod, B * BASE );
    }
}

int main()
{
    ///ifstream cin("data.in");

    cin.sync_with_stdio( false );

    cin >> T;

    while ( T-- )
    {
        cin >> N;
        cin >> str;

        for ( int i = 0; i < N; ++i )
            ch[i + 1] = str[i];

        for ( int i = 1, a, b; i < N; ++i )
        {
            cin >> a >> b;

            G[a].push_back( b );
            G[b].push_back( a );
        }

        DFS( 1, 0, 1 );

        int maxim = 1;

        for ( int i = 1; i <= N; ++i )
        {
            if ( h1[i] == h2[i] )
                maxim = max( maxim, depth[i] );
        }

        cout << maxim << "\n";

        for ( int i = 1; i <= N; ++i )
        {
            depth[i] = h1[i] = h2[i] = 0;
            G[i].clear();
        }
    }

    return 0;
}
