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
