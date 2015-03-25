#include <bits/stdc++.h>

using namespace std;

const int Nmax = 5000 + 1;
const int Mmax = Nmax * Nmax;
const int NIL = -1;

struct Edge
{
    int v;
    int capacity;
    int flow;

    int urm;
};

Edge Graph[Mmax];
int head[Nmax];

int excess[Nmax];
int height[Nmax];
bool active[Nmax];
int pointer[Nmax];

queue<int> Q;

int N, M, countEdges;

void addEdge(int u, int v, int cap1, int cap2)
{
    Graph[countEdges] = {v, cap1, 0, head[u]};
    head[u] = countEdges++;

    Graph[countEdges] = {u, cap2, 0, head[v]};
    head[v] = countEdges++;
}

void enqueue(int v)
{
    if (!active[v] && excess[v] > 0)
    {
        active[v] = true;
        Q.push(v);
    }
}

void push(int u, int p)
{
    int v = Graph[p].v;
    int delta = min(excess[u], Graph[p].capacity - Graph[p].flow);

    if (height[u] <= height[v] || delta == 0) return;

    Graph[p].flow += delta;
    Graph[p ^ 1].flow -= delta;

    excess[u] -= delta;
    excess[v] += delta;

    enqueue(v);
}

void relabel(int v)
{
    height[v] = 2 * N;

    for (int p = head[v]; p != NIL; p = Graph[p].urm)
    {
        if (Graph[p].capacity - Graph[p].flow > 0)
            height[v] = min(height[v], height[ Graph[p].v ] + 1);
    }

    enqueue(v);
}

void discharge(int u)
{
    while (excess[u] > 0)
    {
        if (pointer[u] == NIL)
        {
            relabel(u);
            pointer[u] = head[u];
        }
        else
        {
            int p = pointer[u];
            int v = Graph[p].v;

            if (height[u] >= height[v] + 1 && Graph[p].capacity > Graph[p].flow)
                push(u, p);
            else
                pointer[u] = Graph[ pointer[u] ].urm;
        }
    }
}

void initPreflow(int S, int T)
{
    for (int i = 1; i <= N; ++i)
    {
        excess[i] = 0;
        height[i] = 0;
        pointer[i] = head[i];
    }

    height[S] = N;
    active[S] = active[T] = true;

    for (int p = head[S]; p != NIL; p = Graph[p].urm)
    {
        excess[S] += Graph[p].capacity;
        push(S, p);
    }
}

int push_relabel(int S, int T)
{
    initPreflow(S, T);

    while (Q.empty() == false)
    {
        int v = Q.front();
        Q.pop();
        active[v] = false;
        discharge(v);
    }

    int flow = 0;

    for (int p = head[S]; p != NIL; p = Graph[p].urm)
        flow += Graph[p].flow;

    return flow;
}

int main()
{
    scanf("%d %d", &N, &M);
    countEdges = 0;

    for (int i = 1; i <= N; ++i)
        head[i] = NIL;

    int x, y, c;

    while (M--)
    {
        scanf("%d %d %d", &x, &y, &c);
        addEdge(x, y, c, c);
    }

    printf("%d\n", push_relabel(1, N));

    return 0;
}
