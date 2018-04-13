#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Scanner
{
    private:

        const int BUF_SIZE = 1 << 21;
        char *buffer;
        int position = BUF_SIZE;

        inline char getChar()
        {
            if ( position == BUF_SIZE )
            {
                fread( buffer, 1, BUF_SIZE, stdin );
                position = 0;
            }

            return buffer[ position++ ];
        }

    public:

        Scanner()
        {
            buffer = new char[BUF_SIZE];
        }

        int nextInt()
        {
            int nr = 0;
            char c;

            do
            {
                c = getChar();

            } while ( !isdigit( c ) );

            do
            {
                nr = nr * 10 + c - '0';
                c = getChar();

            } while ( isdigit( c ) );

            return nr;
        }
};

const int Nmax = 2001;
const int Kmax = 17;
const int inf = 1000000000;

vector < pair<int,int> > G[Nmax];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > Heap;
int dist[Nmax], v[Kmax];
int dp[1 << Kmax][Kmax], A[Kmax][Kmax];

int N, M, K;

void Dijkstra()
{
    while ( Heap.size() )
    {
        int nod = Heap.top().second;
        int cost = Heap.top().first;

        Heap.pop();

        if ( dist[nod] != cost ) continue;

        for ( auto x: G[nod] )
        {
            if ( dist[x.first] > dist[nod] + x.second )
            {
                dist[x.first] = dist[nod] + x.second;
                Heap.push( make_pair( dist[x.first], x.first ) );
            }
        }
    }
}

void compute_dist()
{
    for ( int j = 1; j <= N; ++j )
                dist[j] = inf;

    for ( int i = 0; i < K; ++i )
    {
        Heap.push( make_pair( 0, v[i] ) );

        dist[ v[i] ] = 0;

        Dijkstra();

        A[0][i + 1] = A[i + 1][0] = dist[1];

        for ( int j = 0; j < i; ++j )
                A[i + 1][j + 1] = A[j + 1][i + 1] = dist[ v[j] ];

        A[K + 1][i + 1] = A[i + 1][K + 1] = dist[N];

        for ( int j = 1; j <= N; ++j )
                dist[j] = inf;
    }
}

int memo( int state, int nod )
{
    if ( state && !nod )
            return inf;

    if ( dp[state][nod] != inf )
            return dp[state][nod];

    int sol = inf;

    for ( int i = 0, j = 1; j <= state; i++, j <<= 1 )
            if ( state & j )
                    sol = min( sol, memo( state ^ j, i ) + A[nod][i] );

    return dp[state][nod] = sol;
}

int DP()
{
    for ( int i = 0; i < ( 1 << ( K + 1 ) ); ++i )
            for ( int j = 0; j <= K + 1; ++j )
                    dp[i][j] = inf;

    dp[0][0] = 0;

    return memo( ( 1 << ( K + 1 ) ) - 1, K + 1 );
}

int main()
{
    freopen("ubuntzei.in", "r", stdin);
    freopen("ubuntzei.out", "w", stdout);

    Scanner scan;

    N = scan.nextInt(); M = scan.nextInt(); K = scan.nextInt();

    for ( int i = 0; i < K; ++i )
    {
        v[i] = scan.nextInt();
    }

    for ( int i = 1, a, b, c; i <= M; ++i )
    {
        a = scan.nextInt(); b = scan.nextInt(); c = scan.nextInt();

        G[a].push_back( make_pair( b, c ) );
        G[b].push_back( make_pair( a, c ) );
    }

    if ( K == 0 )
    {
        Heap.push( make_pair( 0, 1 ) );

        for ( int j = 1; j <= N; ++j )
                dist[j] = inf;

        dist[1] = 0;
        Dijkstra();

        printf("%d\n", dist[N]);

        return 0;
    }

    compute_dist();
    printf("%d\n", DP());

    return 0;
}
