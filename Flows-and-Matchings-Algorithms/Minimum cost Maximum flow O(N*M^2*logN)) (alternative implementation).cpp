#include <bits/stdc++.h>

using namespace std;

const int Nmax = 350 + 1;
const int Mmax = 12500 + 1;
const int INF = numeric_limits<int>::max();

struct Node
{
    int nod;
    int dist;

    bool operator < (const Node& A) const
    {
        return dist > A.dist;
    }
};

vector<int> G[Nmax];

int Capacity[Nmax][Nmax];
int Flow[Nmax][Nmax];
int Cost[Nmax][Nmax];

queue<int> Q;
int dist[Nmax];
bool in_queue[Nmax];

priority_queue<Node> MinHeap;

int tata[Nmax];

int N, M;

void addEdge(int x, int y, int cap, int c)
{
    G[x].push_back(y);
    G[y].push_back(x);

    Capacity[x][y] = cap;
    Capacity[y][x] = 0;

    Cost[x][y] = c;
    Cost[y][x] = -c;
}

bool Bellman_Ford(int S, int T)
{
    for (int i = 1; i <= N; ++i)
    {
        dist[i] = INF;
        in_queue[i] = false;
        tata[i] = 0;
    }

    Q.push(S);
    in_queue[S] = true;
    dist[S] = 0;
    tata[S] = S;

    while (Q.empty() == false)
    {
        int nod = Q.front();
        in_queue[nod] = false;
        Q.pop();

        for (int& son: G[nod])
        {
            if ((Capacity[nod][son] > Flow[nod][son]) && dist[son] > dist[nod] + Cost[nod][son])
            {
                dist[son] = dist[nod] + Cost[nod][son];
                tata[son] = nod;

                if (!in_queue[son])
                {
                    in_queue[son] = true;
                    Q.push(son);
                }
            }
        }
    }

    return (dist[T] != INF);
}

void updateCosts()
{
    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] != INF)
        {
            for (int& son: G[i])
            {
                if (dist[son] != INF)
                    Cost[i][son] += dist[i] - dist[son];
            }
        }
    }
}

int Dijkstra(int S, int T)
{
    updateCosts();

    for (int i = 1; i <= N; ++i)
    {
        dist[i] = INF;
        in_queue[i] = false;
        tata[i] = 0;
    }

    MinHeap.push({S, 0});
    dist[S] = 0;
    tata[S] = S;

    while (MinHeap.empty() == false)
    {
        int nod = MinHeap.top().nod;
        int auxD = MinHeap.top().dist;
        MinHeap.pop();

        if (auxD != dist[nod])
            continue;

        for (int& son: G[nod])
        {
            if ((Capacity[nod][son] > Flow[nod][son]) && dist[son] > dist[nod] + Cost[nod][son])
            {
                dist[son] = dist[nod] + Cost[nod][son];
                tata[son] = nod;

                MinHeap.push({son, dist[son]});
            }
        }
    }

    return (dist[T] != INF);
}

pair<int, long long> minCostMaxFlow(int S, int T)
{
    int flow = 0;
    long long costFlow = 0;
    long long totalDist = 0;

    Bellman_Ford(S, T);
    totalDist = dist[T];

    while (Dijkstra(S, T))
    {
        int fmin = INF;
        int nod = T;

        while (nod != S)
        {
            fmin = min(fmin, Capacity[ tata[nod] ][nod] - Flow[ tata[nod] ][nod]);
            nod = tata[nod];
        }

        nod = T;

        while (nod != S)
        {
            Flow[ tata[nod] ][nod] += fmin;
            Flow[nod][ tata[nod] ] -= fmin;
            nod = tata[nod];
        }

        flow += fmin;
        totalDist += dist[T];
        costFlow += (long long)fmin * totalDist;
    }

    return make_pair(flow, costFlow);
}

int main()
{
    freopen("fmcm.in", "r", stdin);
    freopen("fmcm.out", "w", stdout);

    int S, T;
    scanf("%d %d %d %d", &N, &M, &S, &T);

    for (int i = 0; i < M; ++i)
    {
        int x, y, cap, cost;
        scanf("%d %d %d %d", &x, &y, &cap, &cost);

        addEdge(x, y, cap, cost);
    }

    printf("%lld\n", minCostMaxFlow(S, T).second);

    return 0;
}
