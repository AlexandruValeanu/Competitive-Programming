#include <bits/stdc++.h>

using namespace std;

/**
    Area of union of rectangles
    -sweep line technique
    -implicit segment tree

    Time: O(N*logMAX_C)
    Memory: O(N*logMAX_C)
**/

const int MAX_COORD = 30000;
const int Nmax = 10000;

struct Event
{
    int x;
    int y1, y2;
    bool type; /// 0/1 for insert/erase

    bool operator < (const Event& E) const
    {
        return x < E.x;
    }
};

Event events[2 * Nmax + 1];

int N;
int nrEvents;

struct Node
{
    int Length;
    int Count;

    explicit Node() : Length(0), Count(0), l(NULL), r(NULL) {
    }

    Node *l, *r;
};

Node *T;

void modifyInterval(Node *&node, int y1, int y2, int minY, int maxY, int delta)
{
    if (node == NULL)
        node = new Node();

    if (y1 <= minY && maxY <= y2)
    {
        node->Count += delta;
    }
    else
    {
        int m = (minY + maxY) / 2;

        if (y1 <= m)
            modifyInterval(node->l, y1, y2, minY, m, delta);

        if (m < y2)
            modifyInterval(node->r, y1, y2, m + 1, maxY, delta);
    }

    if (node->Count > 0)
        node->Length = maxY - minY + 1;
    else
    {
        node->Length = 0;

        if (minY < maxY)
        {
            if (node->l)
                node->Length += node->l->Length;

            if (node->r)
                node->Length += node->r->Length;
        }
    }
}

void insertEvent(int y1, int y2)
{
    modifyInterval(T, y1, y2, 0, MAX_COORD, +1);
}

void eraseEvent(int y1, int y2)
{
    modifyInterval(T, y1, y2, 0, MAX_COORD, -1);
}

int getHeight()
{
    if (!T)
        return 0;
    else
        return T->Length;
}

int main()
{
    ///freopen("data.in", "r", stdin);

    scanf("%d ", &N);

    for (int i = 0; i < N; ++i)
    {
        int x1, y1, x2, y2;
        /// A rectangle is defined by it's bottom left and top right coordinates
        scanf("%d %d %d %d ", &x1, &y1, &x2, &y2);

        events[++nrEvents] = {x1, y1, y2, 0};
        events[++nrEvents] = {x2, y1, y2, 1};
    }

    sort(events + 1, events + nrEvents + 1);

    int totalArea = 0;

    for (int i = 1; i <= nrEvents; ++i)
    {
        totalArea += (events[i].x - events[i - 1].x) * getHeight();

        if (events[i].type == 0)
            insertEvent(events[i].y1, events[i].y2 - 1);

        if (events[i].type == 1)
            eraseEvent(events[i].y1, events[i].y2 - 1);
    }

    cout << totalArea << "\n";

    return 0;
}
