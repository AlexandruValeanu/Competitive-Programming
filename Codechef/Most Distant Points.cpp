#include <bits/stdc++.h>

using namespace std;

const int Nmax = 500000 + 1;

struct Point
{
    int x, y;
    int ind;
};

int f1(const Point &P)
{
    return P.x + P.y;
}

int f2(const Point &P)
{
    return P.x - P.y;
}

int f3(const Point &P)
{
    return -P.x + P.y;
}

int f4(const Point &P)
{
    return -P.x - P.y;
}

struct Node
{
    int val;
    int ind;

    bool operator < (const Node &A) const
    {
        return val > A.val;
    }
};

priority_queue<Node> Heap1, Heap2, Heap3, Heap4;
bool erased[Nmax];
int N;

void lazy_del(priority_queue<Node> &Heap)
{
    while (Heap.size())
    {
        if (erased[Heap.top().ind])
            Heap.pop();
        else
            break;
    }
}

int main()
{
    ///freopen("data.in", "r", stdin);

    scanf("%d ", &N);
    int cnt = 0;
    int ANSWER = 0;

    while (N--)
    {
        char ch;

        scanf("%c ", &ch);

        if (ch == '+')
        {
            cnt++;
            Point P;
            scanf("%d %d ", &P.x, &P.y);

            P.x ^= ANSWER;
            P.y ^= ANSWER;

            Heap1.push({f1(P), cnt});
            Heap2.push({f2(P), cnt});
            Heap3.push({f3(P), cnt});
            Heap4.push({f4(P), cnt});
        }
        else if (ch == '-')
        {
            int ind;
            scanf("%d ", &ind);

            ind ^= ANSWER;

            erased[ind] = 1;
        }
        else
        {
            Point P;
            scanf("%d %d ", &P.x, &P.y);

            P.x ^= ANSWER;
            P.y ^= ANSWER;

            lazy_del(Heap1);
            lazy_del(Heap2);
            lazy_del(Heap3);
            lazy_del(Heap4);

            ANSWER = 0;
            ANSWER = max(ANSWER, f1(P) - Heap1.top().val);
            ANSWER = max(ANSWER, f2(P) - Heap2.top().val);
            ANSWER = max(ANSWER, f3(P) - Heap3.top().val);
            ANSWER = max(ANSWER, f4(P) - Heap4.top().val);

            printf("%d\n", ANSWER);
        }
    }

    return 0;
}
