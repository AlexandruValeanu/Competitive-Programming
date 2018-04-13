#include <bits/stdc++.h>

using namespace std;

class DSU
{
public:

    DSU( const int _N )
    {
        N = _N;

        Father = vector<int>( N + 1, 0 );
        Rank = vector<int> ( N + 1, 0 );

        initialise();
    }

    void initialise()
    {
        for ( int i = 1; i <= N; ++i )
        {
            Father[i] = i;
            Rank[i] = 1;
        }
    }

    int Find( int node )
    {
        int root = node, auxNode;

        while ( Father[ root ] != root )
            root = Father[ root ];

        while ( root != Father[ node ] )
        {
            auxNode = Father[ node ];
            Father[ node ] = root;
            node = auxNode;
        }

        return root;
    }

    int Check( int x, int y )
    {
        return ( Find( x ) == Find( y ) );
    }

    void Union( int x, int y )
    {
        int fx = Find( x );
        int fy = Find( y );

        if ( fx != fy )
        {
            x = fx; y = fy;

            if ( Rank[x] < Rank[y] )
                Father[x] = y;
            else
                Father[y] = x;

            if ( Rank[x] == Rank[y] )
                Rank[y]++;
        }
    }

private:

    vector <int> Father, Rank;
    int N;
};

const int Nmax = 300 + 1;

const int dl[] = { 1, 0 };
const int dc[] = { 0, 1 };

struct edge
{
    int x;
    int y;
    int cost;

    bool operator < ( const edge &E ) const
    {
        return cost > E.cost;
    }

} E[4 * Nmax * Nmax];

vector <int> G[Nmax * Nmax];
int cost[Nmax * Nmax];
int depth[Nmax * Nmax], father[Nmax * Nmax];
int A[Nmax][Nmax];

int N, Q, M;

int query( int x, int y )
{
    int c = 1e9;

    while ( x != y )
    {
        c = min( c, cost[x] );
        c = min( c, cost[y] );

        if ( depth[x] > depth[y] )
            x = father[x];
        else
            y = father[y];
    }

    return c;
}

int valid( int i, int j )
{
    return ( 1 <= i && i <= N && 1 <= j && j <= N );
}

void DFS( int nod, int tata )
{
    for ( auto x: G[nod] )
        if ( x != tata )
        {
            depth[x] = depth[nod] + 1;
            father[x] = nod;
            DFS( x, nod );
        }
}

int main()
{
    ifstream in("matrice2.in");
    ofstream out("matrice2.out");

    in >> N >> Q;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
        {
            in >> A[i][j];
            cost[ N * ( i - 1 ) + j ] = A[i][j];
        }

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
            {
                int nod = N * ( i - 1 ) + j;

                for ( int k = 0; k < 2; ++k )
                {
                    int ii = i + dl[k];
                    int jj = j + dc[k];

                    if ( valid( ii, jj ) )
                    {
                        int aux = N * ( ii - 1 ) + jj;
                        int cost = min( A[i][j], A[ii][jj] );
                        E[ ++M ] = edge{ nod, aux, cost };
                    }
                }
            }

    sort( E + 1, E + M + 1 );

    DSU D( N * N );

    for ( int i = 1; i <= M; ++i )
    {
        int x = E[i].x;
        int y = E[i].y;

        if ( D.Check( x, y ) == false )
        {
            D.Union( x, y );

            G[x].push_back( y );
            G[y].push_back( x );
        }
    }

    srand( time( NULL ) );
    int R = 1 + rand() % ( N * N );

    DFS( R, 0 );

    while ( Q-- )
    {
        int x1, y1, x2, y2;

        in >> x1 >> y1 >> x2 >> y2;
        out << query( N * ( x1 - 1 ) + y1, N * ( x2 - 1 ) + y2 ) << "\n";
    }

    return 0;
}
