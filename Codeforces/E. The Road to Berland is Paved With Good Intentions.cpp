#include <bits/stdc++.h>

using namespace std;

class SAT2
{
public:

    SAT2(const int n = 0) : N(n), p(0), G(vector<vector<int>>(2 * n + 1)), GT(vector<vector<int>>(2 * n + 1)),
                            solution(vector<bool>(2 * n + 1, false)), postorder(vector<int>(2 * n + 1, 0)),
                            visited(vector<bool>(2 * n + 1, false)) {
    }

    int Not(const int x) const
    {
        if (x > N)
            return x - N;
        else
            return x + N;
    }

    void addEdge(int x, int y)
    {
        if (x < 0) x = -x + N;
        if (y < 0) y = -y + N;

        G[x].push_back(y);
        GT[y].push_back(x);
    }

    void dfs(int nod)
    {
        visited[nod] = true;

        for (auto it: G[nod])
            if (!visited[it])
                dfs(it);

        postorder[ ++p ] = nod;
    }

    void dfsT(int nod)
    {
        visited[nod] = false;
        solution[Not(nod)] = true;

        for (auto it: GT[nod])
            if (visited[it])
                dfsT(it);
    }

    void solve()
    {
        for (int i = 1; i <= 2 * N; ++i)
            if (!visited[i])
                dfs(i);

        for (int i = 2 * N; i >= 1; --i)
        {
            int nod = postorder[i];

            if (visited[nod] && visited[Not(nod)])
                dfsT(nod);
        }
    }

    bool isSolution() const
    {
        for (int i = 1; i <= N; ++i)
            if (solution[i] && solution[Not(i)])
                return false;

        return true;
    }

    int N, p;
    vector<vector<int>> G, GT;
    vector<bool> solution;

    vector<int> postorder;
    vector<bool> visited;
};

int main()
{
    ///ifstream cin("data.in");

    int N, M;
    cin >> N >> M;

    SAT2 S(N);

    while (M--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 1)
        {
            S.addEdge(x, y);
            S.addEdge(y, x);

            S.addEdge(-x, -y);
            S.addEdge(-y, -x);
        }
        else
        {
            S.addEdge(x, -y);
            S.addEdge(-y, x);

            S.addEdge(-x, y);
            S.addEdge(y, -x);
        }
    }

    S.solve();

    if (S.isSolution())
    {
        int nr = 0;

        for (int i = 1; i <= S.N; ++i)
            if (S.solution[i])
                nr++;

        cout << nr << "\n";

         for (int i = 1; i <= S.N; ++i)
            if (S.solution[i])
                cout << i << " ";

        cout << "\n";
    }
    else
        cout << "Impossible\n";

    return 0;
}
