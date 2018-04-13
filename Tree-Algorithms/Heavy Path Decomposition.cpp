#include <bits/stdc++.h>

using namespace std;

class Node
{
public:

    long long sum;
    long long lazySum;
    int length;
    bool lazy;
};

void lazyUpdate(Node &S, Node &L, Node &R);

Node join(Node L, Node R);
void pureJoin(Node &S, Node &L, Node &R);

void updateNode(Node &S, const Node &value);

long long realSum(Node &S)
{
    return S.sum + 1LL * S.lazySum * S.length;
}

class SegmentTree
{
private:

    void update(int node, int l, int r, int st, int dr, const Node& value)
    {
        if (st <= l && r <= dr)
        {
            updateNode(tree[node], value);
        }
        else
        {
            lazyUpdate(tree[node], tree[2 * node], tree[2 * node + 1]);

            int m = (l + r) / 2;

            if (st <= m)
                update(2 * node, l, m, st, dr, value);

            if (m < dr)
                update(2 * node + 1, m + 1, r, st, dr, value);

            pureJoin(tree[node], tree[2 * node], tree[2 * node + 1]);
        }
    }

    void build(int node, int l, int r, const vector<Node> &keys)
    {
        tree[node].length = r - l + 1;

        if (l == r)
        {
            updateNode(tree[node], keys[l]);
        }
        else
        {
            int m = (l + r) / 2;

            build(2 * node, l, m, keys);
            build(2 * node + 1, m + 1, r, keys);

            pureJoin(tree[node], tree[2 * node], tree[2 * node + 1]);
        }
    }

    Node query(int node, int l, int r, int st, int dr)
    {
        if (st <= l && r <= dr)
        {
            Node solution = tree[node];
            solution.sum = realSum(solution);
            solution.lazySum = 0;

            return solution;
        }
        else
        {
            lazyUpdate(tree[node], tree[2 * node], tree[2 * node + 1]);
            Node solution;

            int m = (l + r) / 2;

            if (st <= m && m < dr)
                solution = join(query(2 * node, l, m, st, dr), query(2 * node + 1, m + 1, r, st, dr));
            else
            {
                if (st <= m)
                    solution = query(2 * node, l, m, st, dr);
                else
                    solution = query(2 * node + 1, m + 1, r, st, dr);
            }

            pureJoin(tree[node], tree[2 * node], tree[2 * node + 1]);

            return solution;
        }
    }

public:

    vector<Node> tree;
    int N;

    SegmentTree() : tree(), N() {
    }

    SegmentTree(const vector<Node> &keys) : tree(), N() {

        this->N = keys.size();
        tree.resize(4 * N, Node());

        build(1, 0, N - 1, keys);
    }

    void update(const int x, const int y, const Node &value)
    {
        assert(0 <= x && x <= y && y < N);
        update(1, 0, N - 1, x, y, value);
    }

    Node query(const int x, const int y)
    {
        assert(0 <= x && x <= y && y < N);
        return query(1, 0, N - 1, x, y);
    }
};

const int MAX_N = 100000 + 1;
const int NIL = -1;

namespace HeavyPathDecomposition
{
    struct Edge
    {
        int v;
        int urm;
    };

    int head[MAX_N];
    Edge graph[2 * MAX_N];

    vector<SegmentTree> trees; ///type

    int depth[MAX_N], size[MAX_N], father[MAX_N];
    Node valueNode[MAX_N]; ///type
    int path[MAX_N];

    int posInPath[MAX_N], pathLength[MAX_N], startNode[MAX_N];

    int N, nrPaths, contor;

    void clearHPD()
    {
        N = 0;
        nrPaths = 0;
        contor = 0;
        trees.clear();

        for (int i = 0; i < MAX_N; ++i)
        {
            size[i] = 0;
            father[i] = 0;
            valueNode[i] = Node();
            path[i] = 0;
            posInPath[i] = 0;
            pathLength[i] = 0;
            startNode[i] = 0;
        }
    }

    void initHeavyPaths(const int n, const vector<Node> &keys) ///type
    {
        N = n;
        nrPaths = 0;
        contor = 0;

        for (int i = 1; i <= N; ++i)
        {
            head[i] = NIL;
            valueNode[i] = keys[i - 1];
        }
    }

    void addEdge(const int x, const int y)
    {
        assert(1 <= x && x <= N);
        assert(1 <= y && y <= N);

        assert(x != y);

        graph[contor] = {y, head[x]};
        head[x] = contor++;
    }

    void dfs(int node)
    {
        int heavySon = 0;
        size[node] = 1;

        for (int p = head[node]; p != NIL; p = graph[p].urm)
        {
            int v = graph[p].v;

            if (father[v] == 0)
            {
                depth[v] = depth[node] + 1;
                father[v] = node;

                dfs(v);

                size[node] += size[v];

                if (size[v] > size[heavySon])
                    heavySon = v;
            }
        }

        if (heavySon == 0)
            path[node] = nrPaths++;
        else
            path[node] = path[heavySon];

        posInPath[node] = pathLength[ path[node] ]++;
    }

    void buildHeavyPaths()
    {
        father[1] = 1;
        depth[1] = 0;

        dfs(1);

        for (int i = 1; i <= N; ++i)
        {
            posInPath[i] = pathLength[ path[i] ] - posInPath[i] - 1;

            if (posInPath[i] == 0)
                startNode[ path[i] ] = i;
        }
    }

    void buildSegmentTrees()
    {
        vector<vector<Node>> pathValues(nrPaths);

        for (int i = 0; i < nrPaths; ++i)
            pathValues[i] = vector<Node>(pathLength[i]);

        for (int i = 1; i <= N; ++i)
            pathValues[ path[i] ][ posInPath[i] ] = valueNode[i];

        for (int i = 0; i < nrPaths; ++i)
            trees.push_back(SegmentTree(pathValues[i])); ///type
    }

    void updateChain(int x, int y, const Node &value) ///type
    {
        if (depth[ startNode[ path[x] ] ] < depth[ startNode[ path[y] ] ])
            swap(x, y);

        if (path[x] == path[y])
        {
            trees[ path[x] ].update(min(posInPath[x], posInPath[y]), max(posInPath[x], posInPath[y]), value);
        }
        else
        {
            trees[ path[x] ].update(0, posInPath[x], value);
            updateChain(father[ startNode[ path[x] ] ], y, value);
        }
    }

    Node query(int x, int y)
    {
        if (depth[ startNode[ path[x] ] ] < depth[ startNode[ path[y] ] ])
            swap( x, y );

        if ( path[x] == path[y] )
            return trees[ path[x] ].query(min(posInPath[x], posInPath[y]), max(posInPath[x], posInPath[y]));
        else
            return join(trees[ path[x] ].query(0, posInPath[x]), query(father[ startNode[ path[x] ] ], y));
    }

    int lca(int x, int y)
    {
        while (path[x] != path[y])
        {
            if (depth[ startNode[ path[x] ] ] < depth[ startNode[ path[y] ] ])
                y = father[ startNode[ path[y] ] ];
            else
                x = father[ startNode[ path[x] ] ];
        }

        return posInPath[x] < posInPath[y] ? x : y;
    }
}

void lazyUpdate(Node &S, Node &L, Node &R)
{
    if (S.lazy)
    {
        L.lazy = true;
        R.lazy = true;
        S.lazy = false;

        L.lazySum += S.lazySum;
        R.lazySum += S.lazySum;

        S.lazySum = 0;
    }
}

void pureJoin(Node &S, Node &L, Node &R)
{
    S.sum = realSum(L) + realSum(R);
    S.length = L.length + R.length;
}

Node join(Node L, Node R)
{
    Node solution;

    solution.sum = L.sum + R.sum;
    solution.length = L.length + R.length;

    return solution;
}

void updateNode(Node &S, const Node &value)
{
    S.lazySum += value.lazySum;
    S.lazy = true;
}

int main()
{
    return 0;
}
