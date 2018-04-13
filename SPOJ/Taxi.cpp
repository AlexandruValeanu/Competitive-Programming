#include <iostream>

using namespace std;

const int Nmax = 400 + 1;
const int Mmax = Nmax * Nmax + 1;
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

int X[Nmax], Y[Nmax];

int V1, V2;
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
    for (int i = 0; i < 2 * Nmax; ++i)
        match[i] = 0;

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

int modul(int a)
{
    if (a > 0)
        return a;
    else
        return -a;
}

int main()
{
    ///freopen("data.in", "r", stdin);

    int tests, speed, timp;
    scanf("%d ", &tests);

    while (tests--)
    {
        scanf("%d %d %d %d ", &V1, &V2, &speed, &timp);

        countEdges = 0;

        for (int i = 1; i <= V1; ++i)
            head[i] = NIL;

        for (int i = 1; i <= V1; ++i)
            scanf("%d %d", &X[i], &Y[i]);

        for (int i = 1; i <= V2; ++i)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            for (int j = 1; j <= V1; ++j)
            {
                int d = modul(x - X[j]) + modul(y - Y[j]);

                if (d * 200 <= timp * speed)
                    addEdge(j, V1 + i);
            }
        }

        printf("%d\n", Hopcroft_Karp());
    }

    return 0;
}
