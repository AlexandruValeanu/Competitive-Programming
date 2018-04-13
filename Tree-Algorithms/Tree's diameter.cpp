#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int Nmax = 1e5;

vector <int> G[Nmax + 1];
queue <int> Q;
int dist[Nmax + 1];

int N;

int BFS( int nod )
{
    fill( dist + 1, dist + N + 1, 0 );

    dist[nod] = 1;
    Q.push( nod );

    while ( !Q.empty() )
    {
        nod = Q.front();
        Q.pop();

        for ( auto x: G[nod] )
                if ( !dist[x] )
                {
                    dist[x] = dist[nod] + 1;
                    Q.push( x );
                }
    }

    return *max_element( dist + 1, dist + N + 1 );
}

int diameter()
{
    int d = BFS( 1 );
    int v = find( dist + 1, dist + N + 1, d ) - dist;

    return BFS( v );
}

int main()
{
    cin >> N;

    for ( int i = 1, a, b; i < N; ++i )
    {
        cin >> a >> b;

        G[a].push_back( b );
        G[b].push_back( a );
    }

    cout << diameter() << "\n";

    return 0;
}
