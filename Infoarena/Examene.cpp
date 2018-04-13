#include <bits/stdc++.h>

using namespace std;

const int Nmax = 300 + 1;

vector<int> G[Nmax], GT[Nmax];
int postordine[Nmax];
int scc[Nmax];
int util[Nmax];
int vis[Nmax];
int dim[Nmax];
int inutil[Nmax];
int folos[Nmax];
int special[Nmax];

int N, M, P, p, NrSCC;

void dfs( int nod )
{
    folos[nod] = 1;

    for ( auto x: GT[nod] )
        if ( !folos[x] )
            dfs( x );
}

void DFS( int nod )
{
    vis[nod] = 1;

    for ( auto x: G[nod] )
        if ( !vis[x] )
            DFS( x );

    postordine[ ++p ] = nod;
}

void DFST( int nod )
{
    vis[nod] = 0;


    for ( auto x: GT[nod] )
        if ( vis[x] )
            DFST( x );

    scc[nod] = NrSCC;
    dim[NrSCC]++;
}

void SCC()
{
    for ( int i = 1; i <= N; ++i )
        if ( !vis[i] )
            DFS( i );

    for ( int i = N; i >= 1; i-- )
    {
        int nod = postordine[i];

        if ( vis[nod] )
        {
            NrSCC++;
            DFST( nod );
        }
    }
}

int main()
{
    ifstream in("examene.in");
    ofstream out("examene.out");

    ios_base::sync_with_stdio( false );

    in >> N >> M >> P;

    for ( int i = 1; i <= M; ++i )
    {
        int a, b;
        in >> a >> b;

        assert( 1 <= a && a <= N );
        assert( 1 <= b && b <= N );

        if ( a == b )
        {
            special[a] = 1;
            continue;
        }

        G[a].push_back( b );
        GT[b].push_back( a );
    }

    SCC();

    for ( int i = 1; i <= P; ++i )
    {
        int a;
        in >> a;
        util[a] = 1;
    }

    for ( int i = 1; i <= NrSCC; ++i )
    {
        if ( dim[i] > 1 )
        {
            for ( int j = 1; j <= N; ++j )
                if ( scc[j] == i )
                    inutil[j] = 1;
        }
    }

    for ( int i = 1; i <= N; ++i )
        if ( !folos[i] && util[i] )
            dfs( i );

    int ceva = 0;

    for ( int i = 1; i <= N; ++i )
        if ( !folos[i] )
        {
            out << i << " ";
            ceva = 1;
        }

    if ( !ceva )
        out << "0\n";
    else
        out << "\n";

    for ( int i = 1; i <= N; ++i )
        if ( inutil[i] || special[i] )
            out << i << " ";

    out << "\n";

    return 0;
}
