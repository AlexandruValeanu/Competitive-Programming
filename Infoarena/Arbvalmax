#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300000 + 1;
const int NIL = -1;

struct Edge
{
    int nod;
    int urm;
};

Edge G[2 * MAX_N];
int head[MAX_N];

int value[MAX_N];
int valueWithout[MAX_N];
int valuePath[MAX_N];
int tata[MAX_N];

unordered_map<int, int> Hash;
priority_queue<int> Heap;

int N, M;
int contor;

void addEdge(int x, int y)
{
    G[contor] = {y, head[x]};
    head[x] = contor++;
}

void lazy()
{
    while (Heap.size())
    {
        int v = Heap.top();

        if (Hash[v] == 0)
            Heap.pop();
        else
            break;
    }
}

void dfs(int nod, int v)
{
    Hash[ value[nod] ]--;
    lazy();

    valueWithout[nod] = Heap.top();
    valuePath[nod] = v;

    for (int p = head[nod]; p != NIL; p = G[p].urm)
    {
        int son = G[p].nod;

        tata[son] = nod;
        dfs(son, max(v, value[son]));
    }

    Heap.push(value[nod]);
    Hash[ value[nod] ]++;
}

int main()
{
    freopen("arbvalmax.in", "r", stdin);
    freopen("arbvalmax.out", "w", stdout);

    scanf("%d %d ", &N, &M);

    for (int i = 1; i <= N; ++i)
        head[i] = NIL;

    for (int i = 2; i <= N; ++i)
    {
        int p;
        scanf("%d ", &p);
        addEdge(p, i);
    }

    for (int i = 1; i <= N; ++i)
    {
        scanf("%d ", &value[i]);
        Heap.push(value[i]);
        Hash[ value[i] ]++;
    }

    dfs(1, value[1]);

    for (int i = 1; i <= M; ++i)
    {
        int x, y;
        scanf("%d %d ", &x, &y);

        int v = max(valuePath[ tata[x] ], valueWithout[y]);

        printf("%d\n", v);
    }

    return 0;
}
