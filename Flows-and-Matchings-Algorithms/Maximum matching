#include <iostream>

using namespace std;

const int Nmax = 50000 + 1;
const int Mmax = 150000 + 1;
const int NIL = -1;

struct Edge
{
    int nod;
    int urm;
};

Edge Graph[Mmax];
int head[Nmax];

int match[2 * Nmax];
bool use[Nmax];

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

int Hopcroft_Karp()
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

    int matching = 0;

    for (int i = 1; i <= V1; ++i)
        if (match[i])
            matching++;

    return matching;
}

int main()
{
    ///freopen("data.in", "r", stdin);

    scanf("%d %d %d", &V1, &V2, &E);

    for (int i = 1; i <= V1; ++i)
        head[i] = NIL;

    for (int i = 1; i <= E; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        addEdge(x, V1 + y);
    }

    printf("%d\n", Hopcroft_Karp());

    return 0;
}
