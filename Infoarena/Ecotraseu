#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

struct Edge
{
    int nod;
    int cost;
};

vector<Edge> G[Nmax];

int lengthPath[Nmax];
int subtreeSize[Nmax];
bool used[Nmax];

int countNodes;
int nodesSubtree[Nmax];

int T, N;
int A, B;
int stopped;

void computeSubtreeSize(int node, int father)
{
    subtreeSize[node] = 0;

    for (Edge &e: G[node])
    {
        int son = e.nod;

        if (used[son] == false && father != son)
        {
            computeSubtreeSize(son, node);

            subtreeSize[node] += subtreeSize[son] + 1;
        }
    }
}

int findCentroid(int node, int father, int nrNodes)
{
    for (Edge &e: G[node])
    {
        int son = e.nod;

        if (used[son] == false && father != son)
        {
            if (nrNodes < subtreeSize[son] + 1)
                return findCentroid(son, node, nrNodes);
        }
    }

    return node;
}

void computeLengths(int node, int father, int length, int size)
{
    nodesSubtree[ countNodes++ ] = node;

    lengthPath[node] = length;
    subtreeSize[node] = size;

    for (Edge &e: G[node])
    {
        int son = e.nod;

        if (used[son] == false && son != father)
            computeLengths(son, node, length + e.cost, size + 1);
    }
}

void computePaths(int node)
{
    unordered_map<int, int> HashTable;

    lengthPath[node] = 0;
    subtreeSize[node] = 0;

    for (Edge &e: G[node])
    {
        if (stopped) return;

        int son = e.nod;

        if (used[son]) continue;

        countNodes = 0;
        computeLengths(son, node, e.cost, 1);

        for (int i = 0; i < countNodes; ++i)
        {
            int v = nodesSubtree[i];

            if (G[v].size() > 1) continue;

            if (G[node].size() == 1 && lengthPath[v] == 0)
            {
                A = node;
                B = v;
                stopped = 1;
                return;
            }

            auto it = HashTable.find(-lengthPath[v]);

            if (it != HashTable.end())
            {
                A = v;
                B = it->second;
                stopped = 1;
                return;
            }
        }

        for (int i = 0; i < countNodes; ++i)
        {
            int v = nodesSubtree[i];

            if (G[v].size() > 1) continue;

            HashTable[ lengthPath[v] ] = v;
        }
    }
}

void divide_conquer(int node, int nrNodes)
{
    if (stopped) return;

    if (nrNodes == 1) return;

    computeSubtreeSize(node, -1);

    int center = findCentroid(node, -1, nrNodes);
    used[center] = true;

    computePaths(center);

    if (stopped) return;

    int upNode = -1;
    int sumKids = 0;

    for (Edge &e: G[center])
    {
        int son = e.nod;

        if (used[son] == false)
        {
            if (subtreeSize[son] < subtreeSize[center])
            {
                divide_conquer(son, subtreeSize[son] + 1);
                sumKids += subtreeSize[son] + 1;
            }
            else
                upNode = son;
        }
    }

    if (upNode != -1)
        divide_conquer(upNode, nrNodes - sumKids - 1);
}

int main()
{
    ifstream in("ecotraseu.in");
    ofstream out("ecotraseu.out");

    ios_base::sync_with_stdio(false);

    in >> T;

    while (T--)
    {
        in >> N;

        for (int i = 1; i <= N; ++i)
        {
            subtreeSize[i] = 0;
            used[i] = false;
            G[i].clear();
        }

        for (int i = 1; i < N; ++i)
        {
            int a, b, c;
            in >> a >> b >> c;

            G[a].push_back({b, c});
            G[b].push_back({a, c});
        }

        stopped = 0;
        A = -1; B = -1;
        divide_conquer(1, N);

        out << A << " " << B << "\n";
    }

    return 0;
}
