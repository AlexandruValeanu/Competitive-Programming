#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

struct Edge
{
    int nod;
    int urm;
};

Edge G[2 * Nmax];
int contor;
int head[Nmax];

int N, M;

int visited[Nmax];
int colour[Nmax];
int father[Nmax];
pair<int,int> cycleEdge;

void addEdge(int a, int b)
{
    contor++;
    G[contor].nod = b;
    G[contor].urm = head[a];
    head[a] = contor;
}

void dfs(int nod, int tata)
{
    visited[nod] = 1;

    for ( int p = head[nod]; p; p = G[p].urm )
    {
        int fiu = G[p].nod;

        if ( fiu != tata )
        {
            if ( visited[fiu] == 0 )
            {
                father[fiu] = nod;
                dfs(fiu, nod);
            }
            else
            {
                if ( cycleEdge.first == 0 )
                    cycleEdge = {fiu, nod};

                return;
            }
        }
    }
}

void markNodes(int nod, int c)
{
    visited[nod] = 1;

    for ( int p = head[nod]; p; p = G[p].urm )
    {
        int fiu = G[p].nod;

        if ( colour[fiu] == 0 )
        {
            colour[fiu] = c;
            markNodes(fiu, c);
        }
    }
}

int main()
{
    ifstream in("something.in");
    ofstream out("something.out");

    ios_base::sync_with_stdio(false);

    in >> N >> M;

    if ( M == N - 1 || N < 3 )
        out << "-1\n";
    else
    {
        for ( int i = 1; i <= M; ++i )
        {
            int a, b;
            in >> a >> b;

            addEdge(a, b);
            addEdge(b, a);
        }

        dfs(1, 0);

        int nod = cycleEdge.second;
        colour[nod] = 3;
        nod = father[nod];

        while ( nod != cycleEdge.first )
        {
            colour[nod] = 2;
            nod = father[nod];
        }

        colour[nod] = 1;

        for ( int i = 1; i <= N; ++i )
            visited[i] = 0;

        for ( int i = 1; i <= N; ++i )
            if ( !visited[i] && colour[i] )
                markNodes(i, colour[i]);

        for ( int i = 1; i <= N; ++i )
            out << colour[i] << " ";

        out << "\n";
    }

    return 0;
}
