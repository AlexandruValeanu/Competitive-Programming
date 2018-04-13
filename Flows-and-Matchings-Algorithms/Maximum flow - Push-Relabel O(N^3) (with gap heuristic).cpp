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

int countHeight[2 * Nmax];

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

void gap(int k)
{
    for (int i = 1; i <= N; ++i)
    {
        if (height[i] >= k)
        {
            countHeight[ height[i] ]--;
            height[i] = max(height[i], N + 1);
            countHeight[ height[i] ]++;

            enqueue(i);
        }
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
    countHeight[ height[v] ]--;

    height[v] = 2 * N;

    for (int p = head[v]; p != NIL; p = Graph[p].urm)
    {
        if (Graph[p].capacity - Graph[p].flow > 0)
            height[v] = min(height[v], height[ Graph[p].v ] + 1);
    }

    countHeight[ height[v] ]++;

    enqueue(v);
}

void discharge(int u)
{
    bool doneGap = 0;

    while (excess[u] > 0)
    {
        if (countHeight[ height[u] ] == 1 && (doneGap == false))
        {
            gap(height[u]);

            doneGap = true;
            pointer[u] = NIL;
        }

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
    for (int i = 0; i <= 2 * N; ++i)
        countHeight[i] = 0;

    for (int i = 1; i <= N; ++i)
    {
        excess[i] = 0;
        height[i] = 0;
        pointer[i] = head[i];
        active[i] = false;
    }

    height[S] = N;
    active[S] = active[T] = true;

    countHeight[N] = 1;
    countHeight[0] = N - 1;

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
        addEdge(x, y, c, 0);
    }

    printf("%d\n", push_relabel(1, N));

    return 0;
}
