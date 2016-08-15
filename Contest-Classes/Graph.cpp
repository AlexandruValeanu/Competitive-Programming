#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:

    class Edge
    {
    public:

        int node;
        size_t next;

        Edge(int _node, size_t _next) : node(_node), next(_next){
        }
    };

    vector<Edge> graph;
    vector<int> head;
    int N;

public:

    static const int NIL = -1;

    Graph(int _N) : graph(), head(), N(_N){
        head.resize(N, NIL);
    }

    void addEdge(int x, int y)
    {
        assert(1 <= x && x <= N);
        x--;

        graph.push_back(Edge(y, head[x]));
        head[x] = graph.size() - 1;
    }

    void addDoubleEdge(int x, int y)
    {
        addEdge(x, y);
        addEdge(y, x);
    }

    int getHead(int node) const
    {
        assert(1 <= node && node <= N);
        return head[node - 1];
    }

    int getNeighbour(size_t p) const
    {
        assert(p < graph.size());
        return graph[p].node;
    }

    int getNext(size_t p) const
    {
        assert(p < graph.size());
        return graph[p].next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
