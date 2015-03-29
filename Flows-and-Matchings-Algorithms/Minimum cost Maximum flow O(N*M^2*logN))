#include <bits/stdc++.h>
 
using namespace std;
 
const int Nmax = 350 + 1;
const int Mmax = 12500 + 1;
const int NIL = -1;
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
 
struct Edge
{
    int vecin;
 
    int capacity;
    int flow;
    int cost;
 
    int urm;
};
 
Edge Graph[2 * Mmax];
int head[Nmax];
 
int dist[Nmax];
queue<int> Q;
bool in_queue[Nmax];
 
priority_queue<Node> MinHeap;
 
int tata[Nmax];
int pointer[Nmax];
 
int N, M;
int countEdges;
 
void addEdge(int x, int y, int cap, int cost)
{
    Graph[countEdges] = {y, cap, 0, cost, head[x]};
    head[x] = countEdges++;
 
    Graph[countEdges] = {x, 0, 0, -cost, head[y]};
    head[y] = countEdges++;
}
 
bool Bellman_Ford(int S, int T)
{
    for (int i = 1; i <= N; ++i)
    {
        dist[i] = INF;
        in_queue[i] = false;
        tata[i] = 0;
        pointer[i] = NIL;
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
 
        for (int p = head[nod]; p != NIL; p = Graph[p].urm)
        {
            int son = Graph[p].vecin;
 
            if ((Graph[p].capacity > Graph[p].flow) && dist[son] > dist[nod] + Graph[p].cost)
            {
                dist[son] = dist[nod] + Graph[p].cost;
                tata[son] = nod;
                pointer[son] = p;
 
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
            for (int p = head[i]; p != NIL; p = Graph[p].urm)
            {
                int son = Graph[p].vecin;
 
                if (dist[son] != INF)
                    Graph[p].cost += dist[i] - dist[son];
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
        pointer[i] = NIL;
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
 
        for (int p = head[nod]; p != NIL; p = Graph[p].urm)
        {
            int son = Graph[p].vecin;
 
            if ((Graph[p].capacity > Graph[p].flow) && dist[son] > dist[nod] + Graph[p].cost)
            {
                dist[son] = dist[nod] + Graph[p].cost;
                tata[son] = nod;
                pointer[son] = p;
 
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
            fmin = min(fmin, Graph[ pointer[nod] ].capacity - Graph[ pointer[nod] ].flow);
            nod = tata[nod];
        }
 
        nod = T;
 
        while (nod != S)
        {
            Graph[ pointer[nod] ].flow += fmin;
            Graph[ pointer[nod] ^ 1 ].flow -= fmin;
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
 
    for (int i = 1; i <= N; ++i)
        head[i] = NIL;
 
    for (int i = 0; i < M; ++i)
    {
        int x, y, cap, cost;
        scanf("%d %d %d %d", &x, &y, &cap, &cost);
 
        addEdge(x, y, cap, cost);
    }
 
    printf("%lld\n", minCostMaxFlow(S, T).second);
 
    return 0;
}
