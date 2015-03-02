#include <bits/stdc++.h>

using namespace std;

const int Nmax = 200000 + 1;
const int Mmax = 400000 + 1;
const int INF = numeric_limits<int>::max();

struct Pair
{
    int nod;
    int val;

    bool operator < (const Pair& A) const
    {
        return val > A.val;
    }
};

vector<Pair> G[Nmax];
priority_queue<Pair> Mvisited;

int dist[Nmax];
int dad[Nmax];
bool visited[Nmax];

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for ( int i = 1; i <= M; ++i )
    {
        int a, b, c;
        cin >> a >> b >> c;

        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    for ( int i = 1; i <= N; ++i )
        dist[i] = INF;

    dist[1] = 0;
    Mvisited.push({1, 0});

    int costAPM = 0;

    for ( int i = 1; i <= N; ++i )
    {
        while ( Mvisited.size() && dist[Mvisited.top().nod] != Mvisited.top().val )
            Mvisited.pop();

        int nod = Mvisited.top().nod;
        Mvisited.pop();

        costAPM += dist[nod];
        visited[nod] = true;

        for (auto& it: G[nod])
        {
            int son = it.nod;
            int cost = it.val;

            if ( dist[son] > cost && visited[son] == false )
            {
                dad[son] = nod;
                dist[son] = cost;
                Mvisited.push({son, dist[son]});
            }
        }
    }

    cout << costAPM << "\n";
    cout << N - 1 << "\n";

    for ( int i = 2; i <= N; ++i )
        cout << i << " " << dad[i] << "\n";

    return 0;
}
