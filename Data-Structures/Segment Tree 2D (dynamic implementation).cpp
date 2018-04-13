#include <bits/stdc++.h>

using namespace std;

template <class dataType, dataType(*join)(const dataType&, const dataType&)>
class SegmentTree2D
{
private:

    static const int MAX_N = numeric_limits<int>::max() / 2;

    class Node
    {
    public:

        dataType data;
        Node *sons[4];

        Node() : data(dataType()) {

            sons[0] = nullptr;
            sons[1] = nullptr;
            sons[2] = nullptr;
            sons[3] = nullptr;
        }
    };

    void update(Node *&node, int a1, int b1, int a2, int b2, int x, int y, const dataType &newKey)
    {
        if (a1 > a2 || b1 > b2)
            return; ///out of bounds

        if (x > a2 || y > b2 || x < a1 || y < b1)
            return; ///out of bounds

        ///create new node ?
        if (node == nullptr)
            node = new Node();

        if (a1 == a2 && b1 == b2)
        {
            node->data = newKey;
        }
        else
        {
            int ma = (a1 + a2) / 2;
            int mb = (b1 + b2) / 2;

            ///split the interval
            update(node->sons[0], a1, b1, ma, mb, x, y, newKey);
            update(node->sons[1], ma + 1, b1, a2, mb, x, y, newKey);
            update(node->sons[2], a1, mb + 1, ma, b2, x, y, newKey);
            update(node->sons[3], ma + 1, mb + 1, a2, b2, x, y, newKey);

            node->data = dataType();

            ///update node->data
            if (node->sons[0] != nullptr) node->data = join(node->data, node->sons[0]->data);
            if (node->sons[1] != nullptr) node->data = join(node->data, node->sons[1]->data);
            if (node->sons[2] != nullptr) node->data = join(node->data, node->sons[2]->data);
            if (node->sons[3] != nullptr) node->data = join(node->data, node->sons[3]->data);
        }
    }

    dataType query(Node *&node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2)
    {
        if (node == nullptr)
            return dataType(); ///node does not exist

        if (x1 > a2 || y1 > b2 || x2 < a1 || y2 < b1 || a1 > a2 || b1 > b2)
            return dataType(); ///out of bounds

        if (x1 <= a1 && y1 <= b1 && a2 <= x2 && b2 <= y2)
            return node->data;
        else
        {
            int ma = (a1 + a2) / 2;
            int mb = (b1 + b2) / 2;

            dataType X = dataType();

            ///split the interval and update solution
            X = join(X, query(node->sons[0], a1, b1, ma, mb, x1, y1, x2, y2));
            X = join(X, query(node->sons[1], ma + 1, b1, a2, mb, x1, y1, x2, y2));
            X = join(X, query(node->sons[2], a1, mb + 1, ma, b2, x1, y1, x2, y2));
            X = join(X, query(node->sons[3], ma + 1, mb + 1, a2, b2, x1, y1, x2, y2));

            return X;
        }
    }

public:

    Node *root;

    SegmentTree2D() : root(nullptr) {
    }

    void update(const int x, const int y, const dataType newKey)
    {
        update(root, -MAX_N, -MAX_N, MAX_N, MAX_N, x, y, newKey);
    }

    dataType query(const int x1, const int y1, const int x2, const int y2)
    {
        return query(root, -MAX_N, -MAX_N, MAX_N, MAX_N, x1, y1, x2, y2);
    }
};

class Node
{
public:

    int valueMin, valueMax;

    Node() : valueMin(numeric_limits<int>::max()), valueMax(numeric_limits<int>::min()) {
    }

    Node(const int k) : valueMin(k), valueMax(k) {
    }
};

Node join(const Node &A, const Node &B)
{
    Node sol;

    sol.valueMin = min(A.valueMin, B.valueMin);
    sol.valueMax = max(A.valueMax, B.valueMax);

    return sol;
}

SegmentTree2D<Node, join> ST;

int main()
{
    return 0;
}
