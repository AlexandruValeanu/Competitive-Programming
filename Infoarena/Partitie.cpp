#include <bits/stdc++.h>

using namespace std;

const int Nmax = 300000 + 1;

struct Node
{
    int val;
    int mult;

    bool operator < (const Node& A) const
    {
        return val > A.val;
    }
};

pair<int,int> v[Nmax];
priority_queue<Node> MinHeap;
int sol[Nmax];
int N, D, K;

int main()
{
    ifstream in("partitie.in");
    ofstream out("partitie.out");

    in >> N >> D;

    for (int i = 1; i <= N; ++i)
    {
        in >> v[i].first;
        v[i].second = i;
    }

    sort(v + 1, v + N + 1);

    for (int i = 1; i <= N; ++i)
    {
        if (MinHeap.size() && v[i].first - MinHeap.top().val >= D)
        {
            Node a = MinHeap.top();
            MinHeap.pop();

            sol[ v[i].second ] = a.mult;
            MinHeap.push({v[i].first, a.mult});
        }
        else
        {
            MinHeap.push({v[i].first, ++K});
            sol[ v[i].second ] = K;
        }
    }

    out << K << "\n";

    for (int i = 1; i <= N; ++i)
        out << sol[i] << "\n";

    return 0;
}
