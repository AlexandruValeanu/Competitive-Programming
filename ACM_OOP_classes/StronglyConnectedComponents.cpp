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

    static const int NIL;

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

const int Graph::NIL = -1;

class StronglyConnectedComponents
{
private:

    Graph G, GT;
    vector<bool> visisted;
    int N;

    vector< vector<int> > sccs;

public:

    StronglyConnectedComponents(int _N) : G(_N), GT(_N), visisted(_N), N(_N), sccs() {
    }

    void addEdge(int from, int to)
    {
        G.addEdge(from, to);
        GT.addEdge(to, from);
    }

    void dfs(int node, vector<int> &topsort)
    {
        visisted[node] = true;

        for (int p = G.getHead(node + 1); p != Graph::NIL; p = G.getNext(p))
        {
            int son = G.getNeighbour(p) - 1;

            if (!visisted[son])
                dfs(son, topsort);
        }

        topsort.push_back(node + 1);
    }

    void dfsT(int node)
    {
        sccs.back().push_back(node + 1);
        visisted[node] = false;

        for (int p = GT.getHead(node + 1); p != Graph::NIL; p = GT.getNext(p))
        {
            int son = GT.getNeighbour(p) - 1;

            if (visisted[son])
                dfsT(son);
        }
    }

    vector<int> topologicalSorting()
    {
        vector<int> topsort;
        fill(visisted.begin(), visisted.end(), false);

        for (int i = 0; i < N; ++i)
            if (!visisted[i])
                dfs(i, topsort);

        reverse(topsort.begin(), topsort.end());

        return topsort;
    }

    vector< vector<int> > computeSCCs()
    {
        vector<int> _topsort = topologicalSorting();

        for (size_t i = 0; i < _topsort.size(); i++)
        {
            int v = _topsort[i] - 1;

            if (visisted[v])
            {
                sccs.push_back({});
                dfsT(v);
            }
        }

        return sccs;
    }
};

int main()
{
    return 0;
}
