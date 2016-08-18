#include <bits/stdc++.h>

using namespace std;

class PushRelabel
{
private:

    static const int NIL;

    class Edge
    {
    public:

        int flow;
        int capacity;

        int node;
        int next;

        Edge(int _flow, int _capacity, int _node, int _next) : flow(_flow),
            capacity(_capacity), node(_node), next(_next){
        }
    };

    vector<Edge> graph;
    vector<int> head;

    vector<int> excess, height, pointer;
    vector<bool> active;

    vector<int> countHeights;

    queue<int> Q;

    int N;

    void enqueue(int v)
    {
        if (!active[v] && excess[v])
        {
            active[v] = true;
            Q.push(v);
        }
    }

    void push(int u, int p)
    {
        int v = graph[p].node;
        int delta = min(excess[u], graph[p].capacity - graph[p].flow);

        if (height[u] <= height[v] || delta == 0)
            return;

        graph[p].flow += delta;
        graph[p ^ 1].flow -= delta;

        excess[u] -= delta;
        excess[v] += delta;

        enqueue(v);
    }

    void relabel(int u)
    {
        countHeights[height[u]]--;
        height[u] = 2 * N;

        for (int p = head[u]; p != NIL; p = graph[p].next)
        {
            if (graph[p].capacity > graph[p].flow)
                height[u] = min(height[u], height[graph[p].node] + 1);
        }

        countHeights[height[u]]++;
        enqueue(u);
    }

    void discharge(int u)
    {
        bool doneGap = false;

        while (excess[u] > 0)
        {
            if (countHeights[height[u]] == 1 && !doneGap)
            {
                gap(height[u]);
                doneGap = true;
                pointer[u] = NIL;
            }

            if (pointer[u] == NIL)
            {
                relabel(u);
                pointer[u] = head[u];
            }
            else
            {
                int p = pointer[u];
                int v = graph[p].node;

                if (height[u] >= height[v] + 1 && graph[p].capacity > graph[p].flow)
                    push(u, p);
                else
                    pointer[u] = graph[pointer[u]].next;
            }
        }
    }

    void gap(int H)
    {
        for (int i = 0; i < N; ++i)
        {
            if (height[i] >= H)
            {
                countHeights[height[i]]--;
                height[i] = max(height[i], N + 1);
                countHeights[height[i]]++;

                enqueue(i);
            }
        }
    }

    void initPreflow(int S, int T)
    {
        fill(countHeights.begin(), countHeights.end(), 0);
        fill(excess.begin(), excess.end(), 0);
        fill(active.begin(), active.end(), false);
        copy(head.begin(), head.end(), pointer.begin());

        height[S] = N;
        active[S] = active[T] = true;

        countHeights[N] = 1;
        countHeights[0] = N - 1;

        for (int p = head[S]; p != NIL; p = graph[p].next)
        {
            excess[S] += graph[p].capacity;
            push(S, p);
        }
    }

public:

    PushRelabel(int _N) : graph(), head(_N, NIL), excess(_N), height(_N),
        pointer(_N), active(_N), countHeights(2 * _N + 1), Q(), N(_N) {
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

        initPreflow(S, T);

        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();

            active[node] = false;
            discharge(node);
        }

        int flow = 0;

        for (int p = head[S]; p != NIL; p = graph[p].next)
            flow += graph[p].flow;

        return flow;
    }

    vector<int> getSaturated(int node)
    {
        node--;
        vector<int> nodes;

        for (int p = head[node]; p != NIL; p = graph[p].next)
            if (graph[p].flow == graph[p].capacity && graph[p].capacity > 0)
                nodes.push_back(graph[p].node + 1);

        return nodes;
    }
};

const int PushRelabel::NIL = -1;

int main()
{
    return 0;
}
