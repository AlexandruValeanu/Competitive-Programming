#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    short a, b;
    int c;

    Edge(){}

    bool operator < ( const Edge &E ) const
    {
        return c < E.c;
    }
};

const int Nmax = 5100 + 1;
const int Mmax = 100000 + 1;

Edge edge[Mmax];
bool vis[Mmax];
short tata[Nmax];
short rang[Nmax];

int N, M, K;

void init()
{
    for ( int i = 1; i <= N; ++i )
    {
        tata[i] = i;
        rang[i] = 1;
    }
}

int Find( int x )
{
    int y, R;

    for ( R = x; tata[R] != R; R = tata[R] );

    while ( x != y )
    {
        y = tata[x];
        tata[x] = R;
        x = y;
    }

    return R;
}

bool Unite( int x, int y )
{
    if ( x == y )
        return false;

    if ( rang[x] > rang[y] )
        tata[y] = x;
    else
        tata[x] = y;

    if ( rang[x] == rang[y] )
        rang[y]++;

    return true;
}

void restrange( int &m )
{
    int c = 0;

    for ( int i = 1; i <= m; ++i )
    {
        if ( vis[i] )
            edge[ ++c ] = edge[i];
    }

    m = c;
}

int Kruskal( int m )
{
    for ( int i = 1; i <= m; ++i )
        vis[i] = 0;

    int selected = 0;
    int cost = 0;

    for ( int i = 1; i <= m && selected != N - 1; ++i )
    {
        int a = edge[i].a;
        int b = edge[i].b;

        if ( Unite( Find( a ), Find( b ) ) )
        {
            cost += edge[i].c;
            vis[i] = 1;
            selected++;
        }
    }

    return cost;
}

int main()
{
    ifstream in("cotoroanta.in");
    ofstream out("cotoroanta.out");

    in >> N >> M >> K;

    for ( int i = 1; i <= M; ++i )
        in >> edge[i].a >> edge[i].b >> edge[i].c;

    init();

    sort( edge + 1, edge + M + 1 );

    out << Kruskal( M ) << "\n";

    restrange( M );

    for ( int i = 1; i <= K; ++i )
    {
        N++;
        init();

        for ( int j = 1, c; j < N; ++j )
        {
            Edge E;
            in >> E.c;
            E.a = N;
            E.b = j;
            edge[ ++M ] = E;
        }

        sort( edge + 1, edge + M + 1 );

        out << Kruskal( M ) << "\n";

        restrange( M );
    }

    return 0;
}
