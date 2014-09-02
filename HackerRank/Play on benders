#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;

vector <int> G[Nmax];
int postorder[Nmax];
int grundy[Nmax];
int vis[Nmax];
int N, M, P, Q, K;

void DFS( int nod )
{
    vis[nod] = 1;

    for ( auto x: G[nod] )
    {
        if ( !vis[x] )
        {
            DFS( x );
        }
    }

    postorder[ ++P ] = nod;
}

int mex( int nod )
{
    if ( grundy[nod] != -1 )
        return grundy[nod];

    unordered_set <int> Set;

    for ( auto x: G[nod] )
        Set.insert( mex( x ) );

    grundy[nod] = 0;

    while ( Set.count( grundy[nod] ) )
        grundy[nod]++;

    return grundy[nod];
}

int main()
{
    ///ifstream cin("data.in");

    scanf("%d %d", &N, &M);

    for ( int i = 1, a, b; i <= M; ++i )
    {
        scanf("%d %d", &a, &b);
        G[a].push_back( b );
    }

    memset( grundy, -1, sizeof( grundy ) );

    for ( int i = 1; i <= N; ++i )
        if ( !vis[i] )
            DFS( i );

    for ( int i = P; i >= 1; i-- )
        grundy[ postorder[i] ] = mex( postorder[i] );

    scanf("%d", &Q);

    while ( Q-- )
    {
        scanf("%d", &K);

        int xorsum = 0;

        for ( int i = 1, nod; i <= K; ++i )
        {
            scanf("%d", &nod);
            xorsum ^= grundy[nod];
        }

        if ( xorsum )
            cout << "Bumi\n";
        else
            cout << "Iroh\n";
    }

    return 0;
}
