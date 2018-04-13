#include <bits/stdc++.h>

using namespace std;

const int Nmax = 500000 + 1;
const int Mmax = 600000 + 1;
const int NIL = -1;

struct Edge
{
    int nod;
    int cost;

    int urm;
};

struct Node
{
    int nod;
    int value;

    bool operator < (const Node &A) const
    {
        return value > A.value;
    }
};

priority_queue<Node> MinHeap;

Edge G[2 * Mmax + Nmax];
int head[Nmax];

int dist[Nmax];

int N, M, X;
int contor;

void addEdge(int a, int b, int c)
{
    G[contor] = {b, c, head[a]};
    head[a] = contor++;
}

int main()
{
    ifstream in("evacuare.in");
    ofstream out("evacuare.out");

    ios_base::sync_with_stdio(false);

    in >> N >> M >> X;

    for (int i = 1; i <= N; ++i)
        head[i] = NIL;

    for (int i = 1; i <= M; ++i)
    {
        int a, b;
        in >> a >> b;

        addEdge(a, b, 1);
        addEdge(b, a, 1);
    }

    for (int i = 1; i <= N; ++i)
    {
        int p;
        in >> p;

        addEdge(i, p, 0);
    }

    for (int i = 1; i <= N; ++i)
        dist[i] = numeric_limits<int>::max();

    dist[X] = 0;
    MinHeap.push({X, 0});

    while (MinHeap.empty() == false)
    {
        int nod = MinHeap.top().nod;
        int d = MinHeap.top().value;
        MinHeap.pop();

        if (d != dist[nod])
            continue;

        for (int p = head[nod]; p != NIL; p = G[p].urm)
        {
            int v = G[p].nod;
            int cost = G[p].cost;

            if (dist[v] > dist[nod] + cost)
            {
                dist[v] = dist[nod] + cost;
                MinHeap.push({v, dist[v]});
            }
        }
    }

    for (int i = 1; i <= N; ++i)
        out << dist[i] << "\n";

    return 0;
}
