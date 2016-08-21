#include <bits/stdc++.h>

using namespace std;

class MaximumFlow
{
private:

    class Edge
    {
    public:

        int flow;
        int capacity;

        int node;
        int next;

        Edge(int f, int c, int _node, int _next) : flow(f), capacity(c),
            node(_node), next(_next){
        }
    };

    vector<int> head, father, pointer;
    vector<Edge> graph;
    int N;

    bool bfs(int S, int T)
    {
        fill(father.begin(), father.end(), NIL);
        queue<int> Q;

        Q.push(S);
        father[S] = S;

        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();

            for (int p = head[node]; p != NIL; p = graph[p].next)
            {
                int son = graph[p].node;

                if (graph[p].capacity > graph[p].flow && father[son] == NIL)
                {
                    father[son] = node;
                    pointer[son] = p;

                    if (son == T)
                        return true;

                    Q.push(son);
                }
            }
        }

        return false;
    }

public:

    static const int NIL;

    MaximumFlow(int N) : head(N, NIL), father(N), pointer(N), graph(), N(N){
    }

    void addEdge(int from, int to, int capacity)
    {
        from--; to--;

        graph.push_back(Edge(0, capacity, to, head[from]));
        head[from] = graph.size() - 1;
    }

    void addDoubleEdge(int from, int to, int capacity)
    {
        addEdge(from, to, capacity);
        addEdge(to, from, 0);
    }

    int maximumFlow(int S, int T)
    {
        S--; T--;

        int flow = 0;

        while (bfs(S, T))
        {
            for (int p = head[T]; p != NIL; p = graph[p].next)
            {
                int son = graph[p].node;

                if (father[son] != NIL && graph[p ^ 1].capacity > graph[p ^ 1].flow)
                {
                    father[T] = son;
                    pointer[T] = p ^ 1;

                    int node = T;
                    int fmin = numeric_limits<int>::max();

                    while (node != S)
                    {
                        fmin = min(fmin, graph[pointer[node]].capacity - graph[pointer[node]].flow);
                        node = father[node];
                    }

                    node = T;

                    while (node != S)
                    {
                        graph[pointer[node]].flow += fmin;
                        graph[pointer[node] ^ 1].flow -= fmin;
                        node = father[node];
                    }

                    flow += fmin;
                }
            }
        }

        return flow;
    }
};

const int MaximumFlow::NIL = -1;

int main()
{
    return 0;
}
