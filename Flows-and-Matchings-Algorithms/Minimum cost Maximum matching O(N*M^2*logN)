#include <bits/stdc++.h>

using namespace std;

const int Nmax = 300 + 2;
const int Mmax = 2 * Nmax + 50000 + 1;
const int NIL = -1;
const int INF = numeric_limits<int>::max() / 2;

struct Edge
{
    int vecin;

    int capacity;
    int flow;
    int cost;

    int urm;
};

Edge Graph[2 * Mmax];
int head[2 * Nmax];

int dist[2 * Nmax];
bool in_queue[2 * Nmax];
int tata[2 * Nmax];
int pointer[2 * Nmax];
queue<int> Q;

int N;
int V1, V2, E;
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
    for (int i = 0; i <= N; ++i)
    {
        dist[i] = INF;
        tata[i] = 0;
        in_queue[i] = false;
        pointer[i] = NIL;
    }

    dist[S] = 0;
    tata[S] = S;
    in_queue[S] = true;
    Q.push(S);

    while (Q.empty() == false)
    {
        int nod = Q.front();
        Q.pop();
        in_queue[nod] = false;

        for (int p = head[nod]; p != NIL; p = Graph[p].urm)
        {
            int son = Graph[p].vecin;

            if ((Graph[p].capacity > Graph[p].flow) && (dist[son] > dist[nod] + Graph[p].cost))
            {
                dist[son] = dist[nod] + Graph[p].cost;
                pointer[son] = p;
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

pair<int, long long> minCostMaxFlow(int S, int T)
{
    int flow = 0;
    long long costFlow = 0;

    while (Bellman_Ford(S, T))
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
        costFlow += (long long)fmin * dist[T];
    }

    return make_pair(flow, costFlow);
}

int main()
{
    scanf("%d %d %d", &V1, &V2, &E);

    N = V1 + V2 + 1;

    for (int i = 0; i <= N; ++i)
        head[i] = NIL;

    for (int i = 1; i <= V1; ++i)
        addEdge(0, i, 1, 0);

    for (int i = 0; i < E; ++i)
    {
        int x, y, cost;
        scanf("%d %d %d", &x, &y, &cost);

        addEdge(x, V1 + y, 1, cost);
    }

    for (int i = 1; i <= V2; ++i)
        addEdge(V1 + i, N, 1, 0);

    pair<int, long long> sol = minCostMaxFlow(0, N);

    cout << sol.first << " " << sol.second << "\n";

    for (int i = 1; i <= V1; ++i)
    {
        for (int p = head[i]; p != NIL; p = Graph[p].urm)
            if (Graph[p].flow == 1)
                cout << i << " " << Graph[p].vecin - V1 << "\n";
    }

    return 0;
}
