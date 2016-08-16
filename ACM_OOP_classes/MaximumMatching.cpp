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

class MaximumMatching
{
private:

    Graph graph;
    int V1, V2;

    vector<int> matched;
    vector<bool> used, visited;

    bool pairUp(int node)
    {
        assert (0 <= node && node < V1);

        if (used[node])
            return false;

        used[node] = true;

        for (int p = graph.getHead(node + 1); p != graph.NIL; p = graph.getNext(p))
        {
            int son = graph.getNeighbour(p) - 1;

            if (matched[son] == -1){
                matched[son] = node;
                matched[node] = son;
                return true;
            }
        }

        for (int p = graph.getHead(node + 1); p != graph.NIL; p = graph.getNext(p))
        {
            int son = graph.getNeighbour(p) - 1;

            if (pairUp(matched[son])){
                matched[son] = node;
                matched[node] = son;
                return true;
            }
        }

        return false;
    }

    void mark(int node, int side)
    {
        if (side == 0){
            visited[node] = true;

            for (int p = graph.getHead(node + 1); p != graph.NIL; p = graph.getNext(p))
            {
                int son = graph.getNeighbour(p) - 1;

                if (!visited[son] && matched[node] != son) //not an edge from the matching
                    mark(son, side ^ 1);
            }
        }
        else{
            visited[node] = true;

            for (int p = graph.getHead(node + 1); p != graph.NIL; p = graph.getNext(p))
            {
                int son = graph.getNeighbour(p) - 1;

                if (!visited[son] && matched[node] == son) //edge from the matching
                    mark(son, side ^ 1);
            }
        }
    }

public:

    MaximumMatching(int _V1, int _V2) : graph(_V1 + _V2), V1(_V1), V2(_V2) {
        matched.resize(V1 + V2);
        used.resize(V1);
        visited.resize(V1 + V2);
    }

    void addEdge(int from, int to){
        graph.addEdge(from, V1 + to);
        graph.addEdge(V1 + to, from);
    }

    void MVC_MIS(){
        fill(visited.begin(), visited.end(), false);

        for (int i = 0; i < V1; i++) {
            if (matched[i] == -1)
                mark(i, 0);
        }
    }

    vector<bool> minimumVertexCover()
    {
        vector<bool> mvc(V1 + V2, false);

        for (int i = 0; i < V1; i++)
            if (!visited[i])
                mvc[i] = true;

        for (int i = 0; i < V2; i++)
            if (visited[i + V1])
                mvc[i + V1] = true;

        return mvc;
    }

    vector<bool> maximumIndependentSet()
    {
        vector<bool> mis(V1 + V2, false);

        for (int i = 0; i < V1; i++)
            if (visited[i])
                mis[i] = true;

        for (int i = 0; i < V2; i++)
            if (!visited[i + V1])
                mis[i + V1] = true;

        return mis;
    }

    int maximumMatching()
    {
        fill(matched.begin(), matched.end(), -1);
        bool changed;

        do
        {
            changed = false;
            fill(used.begin(), used.end(), false);

            for (int i = 0; i < V1; i++)
                if (matched[i] == -1)
                    changed |= pairUp(i);

        } while (changed);

        int matching = 0;

        for (int i = 0; i < V1; i++)
            if (matched[i] != -1)
                matching++;

        return matching;
    }

    vector<int> getMatched()
    {
        vector<int> matching(V1);

        for (int i = 0; i < V1; ++i)
            matching[i] = matched[i];

        for (int i = 0; i < V1; i++) {
            if (matching[i] != -1)
                matching[i] = matching[i] - V1 + 1;
        }

        return matching;
    }
};

int main()
{
    return 0;
}
