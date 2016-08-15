#include <bits/stdc++.h>

using namespace std;

class WeightedGraph
{
private:

    class Edge
    {
    public:

        int node;
        int cost;
        size_t next;

        Edge(int _node, int _cost, size_t _next) : node(_node), cost(_cost), next(_next){
        }
    };

    vector<Edge> graph;
    vector<int> head;
    int N;

public:

    static const int NIL = -1;

    WeightedGraph(int _N) : graph(), head(), N(_N){
        head.resize(N, NIL);
    }

    void addEdge(int x, int y, int w)
    {
        assert(1 <= x && x <= N);
        x--;

        graph.push_back(Edge(y, w, head[x]));
        head[x] = graph.size() - 1;
    }

    void addDoubleEdge(int x, int y, int w)
    {
        addEdge(x, y, w);
        addEdge(y, x, w);
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

    int getCost(size_t p) const
    {
        assert(p < graph.size());
        return graph[p].cost;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
