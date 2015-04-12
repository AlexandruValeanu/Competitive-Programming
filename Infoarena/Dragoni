#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

const int Nmax = 800 + 1;
const int Mmax = 6000 + 1;
const int INF = numeric_limits<int>::max();

struct Edge
{
    int nod;
    int cost;

    Edge(const int n = 0, const int c = 0) : nod(n), cost(c) {
    }
};

vector<Edge> G[Nmax];
queue<Edge> Q;
bool in_q[Nmax][Nmax];
int D[Nmax][Nmax];
int Dmax[Nmax];
int visited[Nmax];

int N, M;

void dfs(int nod)
{
    visited[nod] = 1;

    for ( unsigned i = 0; i < G[nod].size(); ++i )
    {
        int son = G[nod][i].nod;
        int cost = G[nod][i].cost;

        if ( !visited[son] && Dmax[1] >= cost )
            dfs(son);
    }
}

int solveDFS()
{
    dfs(1);

    int maxim = 0;

    for ( int i = 1; i <= N; ++i )
        if ( visited[i] )
            maxim = max(maxim, Dmax[i]);

    return maxim;
}

int Dijkstra()
{
    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
            D[i][j] = INF;

    D[1][1] = 0;
    Q.push( Edge(1, 1) );
    in_q[1][1] = true;

    int sol = INF;

    while ( Q.size() )
    {
        Edge p = Q.front();
        Q.pop();

        int nod = p.nod;
        int dragon = p.cost;

        in_q[nod][dragon] = false;

        if ( nod == N )
        {
            sol = min(sol, D[nod][dragon]);
            continue;
        }

        for ( unsigned i = 0; i < G[nod].size(); ++i )
        {
            int son = G[nod][i].nod;
            int cost = G[nod][i].cost;

            if ( Dmax[dragon] >= cost )
            {
                int aux_drg = dragon;

                if ( Dmax[son] > Dmax[dragon] )
                    aux_drg = son;

                if ( D[son][aux_drg] > D[nod][dragon] + cost )
                {
                    D[son][aux_drg] = D[nod][dragon] + cost;

                    if ( !in_q[son][aux_drg] )
                    {
                        in_q[son][aux_drg] = true;
                        Q.push( Edge( son, aux_drg ) );
                    }
                }
            }
        }
    }

    return sol;
}

int main()
{
    freopen("dragoni.in", "r", stdin);
    freopen("dragoni.out", "w", stdout);

    int p;
    scanf("%d", &p);
    scanf("%d %d", &N, &M);

    for ( int i = 1; i <= N; ++i )
        scanf("%d", &Dmax[i]);

    for ( int i = 1; i <= M; ++i )
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        G[a].push_back( Edge(b, c) );
        G[b].push_back( Edge(a, c) );
    }

    if (p == 1)
        printf("%d\n", solveDFS());
    else
        printf("%d\n", Dijkstra());

    return 0;
}
