#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 1;

struct Edge
{
    int nod;
    int cost;
};

vector<Edge> G[Nmax];

int subtreeSize[Nmax];
bool used[Nmax];

int lengthPath[Nmax];
int sizePath[Nmax];

int countNodes;
int nodesSubtree[Nmax];

int N;

void computeSubtreeSize(int node, int father)
{
    subtreeSize[node] = 0;

    for (Edge &e: G[node])
    {
        int son = e.nod;

        if (son != father && used[son] == false)
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

        if (son != father && used[son] == false)
        {
            if (nrNodes / 2 < subtreeSize[son] + 1)
                return findCentroid(son, node, nrNodes);
        }
    }

    return node;
}

void computeLengths(int node, int father, int cost, int size)
{
    nodesSubtree[ countNodes++ ] = node;

    lengthPath[node] = cost;
    sizePath[node] = size;

    for (Edge &e: G[node])
    {
        int son = e.nod;

        if (son != father && used[son] == false)
        {
            computeLengths(son, node, cost + e.cost, size + 1);
        }
    }
}

void computePaths(int node)
{
    sizePath[node] = 0;
    lengthPath[node] = 0;

    for (Edge &e: G[node])
    {
        int son = e.nod;

        if (used[son]) continue;

        countNodes = 0;
        computeLengths(son, node, e.cost, 1);

        ///query
        for (int i = 0; i < countNodes; ++i)
        {
            int v = nodesSubtree[i];
        }

        ///update
        for (int i = 0; i < countNodes; ++i)
        {
            int v = nodesSubtree[i];
        }
    }
}

void divide_conquer(int node, int nrNodes)
{
    if (nrNodes == 1) return;

    computeSubtreeSize(node, -1);

    int center = findCentroid(node, -1, nrNodes);
    used[center] = true;

    computePaths(center);

    int sumKids = 0;
    int upNode = -1;

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
    return 0;
}
