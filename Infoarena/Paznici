#include <iostream>

using namespace std;

const int Nmax = 26 + 2;
const int Mmax = Nmax * Nmax + 1;
const int NIL = -1;

struct Edge
{
    int nod;
    int urm;
};

Edge Graph[Mmax];
int head[2 * Nmax];

int match[2 * Nmax];
bool vis[2 * Nmax];
bool use[Nmax];

char A[Nmax][Nmax];

int V1, V2, E;
int countEdges;

void addEdge(int x, int y)
{
    Graph[countEdges] = {y, head[x]};
    head[x] = countEdges;
    countEdges++;
}

bool dfs(int nod)
{
    if (use[nod])
        return false;

    use[nod] = true;

    for (int p = head[nod]; p != NIL; p = Graph[p].urm)
    {
        int son = Graph[p].nod;

        if (!match[son])
        {
            match[nod] = son;
            match[son] = nod;

            return true;
        }
    }

    for (int p = head[nod]; p != NIL; p = Graph[p].urm)
    {
        int son = Graph[p].nod;

        if (dfs(match[son]))
        {
            match[nod] = son;
            match[son] = nod;

            return true;
        }
    }

    return false;
}

void Hopcroft_Karp()
{
    bool valid;

    do
    {
        valid = false;

        for (int i = 1; i <= V1; ++i)
            use[i] = false;

        for (int i = 1; i <= V1; ++i)
            if (!match[i])
                valid |= dfs(i);

    } while (valid);
}

void mark(int nod, int op)
{
    if (op == 0)
    {
        vis[nod] = 1;

        for (int p = head[nod]; p != NIL; p = Graph[p].urm)
        {
            int son = Graph[p].nod;

            if (!vis[son] && match[nod] != son)
                mark(son, op ^ 1);
        }
    }
    else
    {
        vis[nod] = 1;

        for (int p = head[nod]; p != NIL; p = Graph[p].urm)
        {
            int son = Graph[p].nod;

            if (!vis[son] && match[nod] == son)
                mark(son, op ^ 1);
        }
    }
}

int main()
{
    freopen("paznici.in", "r", stdin);
    freopen("paznici.out", "w", stdout);

    scanf("%d %d ", &V1, &V2);

    for (int i = 1; i <= V1; ++i)
        head[i] = NIL;

    for (int i = 1; i <= V1; ++i)
        scanf("%s", A[i] + 1);

    for (int i = 1; i <= V1; ++i)
        for (int j = 1; j <= V2; ++j)
            if (A[i][j] == '1')
            {
                addEdge(i, V1 + j);
                addEdge(V1 + j, i);
            }

    Hopcroft_Karp();

    for (int i = 1; i <= V1; ++i)
        if (!match[i])
            mark(i, 0);

    for (int i = 1; i <= V1; ++i)
        if (!vis[i])
            cout << char ('A' + i - 1);

    for (int i = 1; i <= V2; ++i)
        if (vis[V1 + i])
            cout << char ('a' + i - 1);

    return 0;
}
