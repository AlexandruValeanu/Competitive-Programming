#include <bits/stdc++.h>

using namespace std;

const int Nmax = 200 + 2;
const int Mmax = Nmax * Nmax + 1;
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
int head[Nmax];

int dist[Nmax];
bool in_queue[Nmax];
int tata[Nmax];
int pointer[Nmax];
queue<int> Q;

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
    for (int i = 0; i < Nmax; ++i)
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
    freopen("cc.in", "r", stdin);
    freopen("cc.out", "w", stdout);

    scanf("%d", &N);

    int S = 0;
    int D = 2 * N + 1;

    for (int i = S; i <= D; ++i)
        head[i] = NIL;

    for (int i = 1; i <= N; ++i)
        addEdge(S, i, 1, 0);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            int cost;
            scanf("%d", &cost);
            addEdge(i, j + N, 1, cost);
        }

    for (int i = 1; i <= N; ++i)
        addEdge(i + N, D, 1, 0);

    pair<int, long long> sol = minCostMaxFlow(0, 2 * N + 1);

    cout << sol.second << "\n";

    return 0;
}
