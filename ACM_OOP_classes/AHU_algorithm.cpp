#include <bits/stdc++.h>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

using Graph = vector<vector<int>>;

int bfs(const Graph &tree, int root, vector<int> &father)
{
    const int N = tree.size();

    vector<int> dist(N, INF);
    fill(father.begin(), father.end(), -1);
    queue<int> Q;

    dist[root] = 0;
    Q.push(root);

    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop();

        for (int v : tree[node])
            if (dist[v] == INF)
            {
                father[v] = node;
                dist[v] = dist[node] + 1;
                Q.push(v);
            }
    }

    int maximum = 0;
    int node = -1;

    for (int i = 0; i < N; ++i)
        if (dist[i] > maximum)
        {
            maximum = dist[i];
            node = i;
        }

    assert(node != -1);
    return node;
}

vector<int> getCenters(const Graph &tree)
{
    const int N = tree.size();
    vector<int> father(N);

    int node = bfs(tree, 0, father);
    node = bfs(tree, node, father);

    vector<int> path;

    do
    {
        path.push_back(node);
        node = father[node];

    } while (node != -1);

    const int diameter = path.size();

    if (diameter & 1)
        return {path[diameter / 2]};
    else
        return {path[diameter / 2], path[(diameter / 2) - 1]};
}

string dfs(const Graph &graph, int root, int dad)
{
    vector<string> children;

    for (int v : graph[root])
    {
        if (v != dad)
            children.push_back(dfs(graph, v, root));
    }

    if (children.size() == 0)
        return "10";

    sort(children.begin(), children.end());

    string tmp;

    for (auto x : children)
        tmp += x;

    return "1" + tmp + "0";
}

string getName(const Graph &graph, int root)
{
    return dfs(graph, root, -1);
}

bool AHU_algorithm(const Graph &tree1, const Graph &tree2)
{
    if (tree1.size() <= 1)
        return true;

    vector<int> centers1 = getCenters(tree1);
    vector<int> centers2 = getCenters(tree2);

    if (centers1.size() != centers2.size())
        return false;

    if (centers1.size() == 1)
        return getName(tree1, centers1[0]) == getName(tree2, centers2[0]);
    else
    {
        bool value = getName(tree1, centers1[0]) == getName(tree2, centers2[0]);

        if (!value)
            return getName(tree1, centers1[1]) == getName(tree2, centers2[0]);
        else
            return true;
    }

    return false;
}

int main()
{
    ///freopen("data.in", "r", stdin);

    int T;
    scanf("%d", &T);

    while (T --> 0)
    {
        int N;
        scanf("%d", &N);

        Graph tree1(N);

        for (int i = 1; i <= N - 1; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);

            a--; b--;
            tree1[a].push_back(b);
            tree1[b].push_back(a);
        }

        Graph tree2(N);

        for (int i = 1; i <= N - 1; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);

            a--; b--;
            tree2[a].push_back(b);
            tree2[b].push_back(a);
        }

        if (AHU_algorithm(tree1, tree2))
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
