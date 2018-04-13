#include <bits/stdc++.h>

using namespace std;

/// PARSER
///-------------------------------------
const int BS = (1 << 14);
char stringBuffer[BS];
int position = BS;

char getChar(FILE *in)
{
    if (position == BS)
    {
        position = 0;
        fread(stringBuffer, BS, 1, in);
    }

    return stringBuffer[position++];
}

int getNumber(FILE *in)
{
    int a = 0;
    char ch;

    do
    {
        ch = getChar(in);

    } while (!isdigit(ch));

    do
    {
        a = (a << 3) + (a << 1) + (ch - '0');
        ch = getChar(in);

    } while (isdigit(ch));

    return a;
}
/// END PARSER
///-------------------------------------

const int Nmax = 800 + 1;
const int Mmax = 800 * 800;
const int NIL = -1;

struct __attribute__((__packed__)) Edge
{
    int v : 12;
    int capacity : 28;

    int urm : 22;

    Edge() : v(0), capacity(0), urm(0) {
    }

    Edge(int _v, int _c, int _u) : v(_v), capacity(_c), urm(_u) {
    }
};

Edge Graph[Mmax];
int head[Nmax];

int C[Nmax][Nmax];

int excess[Nmax];
int height[Nmax];
bool active[Nmax];
int pointer[Nmax];

int countHeight[2 * Nmax];

queue<int> Q;

int N, M, countEdges;

void addEdge(int u, int v, int cap1, int cap2)
{
    Graph[countEdges] = Edge(v, cap1, head[u]);
    head[u] = countEdges++;

    Graph[countEdges] = Edge(u, cap2, head[v]);
    head[v] = countEdges++;
}

void readGraph()
{
    FILE *in = fopen("push-relabel.in", "r");

    N = getNumber(in);
    countEdges = 0;

    for (int i = 1; i <= N; ++i)
        head[i] = NIL;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            C[i][j] = getNumber(in);

    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
        {
            if (C[i][j] || C[j][i])
            {
                addEdge(i, j, C[i][j], C[j][i]);
            }
        }

    fclose(in);
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

    int delta = min(excess[u], Graph[p].capacity);

    if (height[u] <= height[v] || delta == 0) return;

    Graph[p].capacity -= delta;
    Graph[p ^ 1].capacity += delta;

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
        if (Graph[p].capacity > 0)
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

            if (height[u] >= height[v] + 1 && Graph[p].capacity > 0)
                push(u, p);
            else
                pointer[u] = Graph[ pointer[u] ].urm;
        }
    }
}

int totalSource;

void initPreflow()
{
    for (int i = 1; i <= N; ++i)
    {
        excess[i] = 0;
        height[i] = 0;
        pointer[i] = head[i];
    }

    height[1] = N;
    active[1] = active[N] = true;

    countHeight[N] = 1;
    countHeight[0] = N - 1;

    for (int p = head[1]; p != NIL; p = Graph[p].urm)
    {
        excess[1] += Graph[p].capacity;
        totalSource += Graph[p].capacity;
        push(1, p);
    }
}

int push_relabel()
{
    initPreflow();

    while (Q.empty() == false)
    {
        int v = Q.front();
        Q.pop();
        active[v] = false;
        discharge(v);
    }

    for (int p = head[1]; p != NIL; p = Graph[p].urm)
        totalSource -= Graph[p].capacity;

    return totalSource;
}

int main()
{
    readGraph();
    fprintf(fopen("push-relabel.out", "w"), "%d\n", push_relabel());

    return 0;
}
