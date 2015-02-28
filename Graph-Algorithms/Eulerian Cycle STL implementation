#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

vector<int> G[Nmax];
vector<int> eulerPath;
bool vis[Nmax];

int N, M;

void eraseSon(int nod, int son)
{
    for (vector<int>::iterator it = G[nod].begin(); it != G[nod].end(); ++it)
        if ( *it == son )
        {
            G[nod].erase(it);
            break;
        }
}

void euler(int nod)
{
    while ( G[nod].size() )
    {
        int w = G[nod].back();
        G[nod].pop_back();
        eraseSon(w, nod);
        euler(w);
    }

    eulerPath.push_back(nod);
}

void dfs(int nod)
{
    vis[nod] = 1;

    for(int son: G[nod])
        if ( !vis[son] )
            dfs(son);
}

bool checkIfEuler()
{
    int nrComp = 0;

    for ( int i = 1; i <= N; ++i )
        if ( !vis[i] )
        {
            nrComp++;
            dfs(i);
        }

    int nrOdd = 0;

    for ( int i = 1; i <= N; ++i )
        if ( G[i].size() % 2 == 1 )
            nrOdd++;

    if ( nrComp > 1 || nrOdd > 0 )
        return false;
    else
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for ( int i = 1; i <= M; ++i )
    {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    if ( checkIfEuler() == false )
        cout << "-1\n";
    else
    {
        euler(1);
        eulerPath.pop_back();

        for (int x: eulerPath)
            cout << x << " ";

        cout << "\n";
    }

    return 0;
}
