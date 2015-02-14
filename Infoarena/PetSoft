#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000 + 1;

struct Edge
{
    int nod;
    int urm;
};

Edge G[Nmax];
int contor;
int head[Nmax];

int dp[Nmax][2];
int sons[Nmax], aux[Nmax];
int C[Nmax][Nmax];
/// 0 il cuplez
/// 1 nu-l cuplez

int N;

void addEdge(int x, int y)
{
    contor++;
    G[contor].nod = y;
    G[contor].urm = head[x];
    head[x] = contor;
}

int computeAuxDP(int sons[], int limit)
{
    for ( int i = limit; i >= 1; i-- )
    {
        for ( int j = i; j <= limit; ++j )
        {
            int best = 0;

            int c1 = max(dp[ sons[i] ][0], dp[ sons[i] ][1]);

            if ( i + 1 <= j )
                c1 += C[i + 1][j];

            int c2 = max(dp[ sons[j] ][0], dp[ sons[j] ][1]);

            if ( i <= j - 1 )
                c2 += C[i][j - 1];

            int c3 = abs(sons[j] - sons[i]) + dp[ sons[i] ][1] + dp[ sons[j] ][1];

            if ( i + 1 <= j - 1 )
                c3 += C[i + 1][j - 1];

            if ( i == j )
                c3 = 0;

            best = max(best, c1);
            best = max(best, c2);
            best = max(best, c3);

            C[i][j] = best;
        }
    }

    return C[1][limit];
}

void DFS(int nod)
{
    for ( int p = head[nod]; p != 0; p = G[p].urm )
    {
        int fiu = G[p].nod;
        DFS(fiu);
    }

    int cnt = 0;

    for ( int p = head[nod]; p != 0; p = G[p].urm )
    {
        int fiu = G[p].nod;
        sons[ ++cnt ] = fiu;
    }

    if ( cnt > 0 )
    {
        sort(sons + 1, sons + cnt + 1);
        dp[nod][1] = computeAuxDP(sons, cnt);

        int aux = dp[nod][1];
        dp[nod][1] = 0;

        sons[ ++cnt ] = nod;
        sort(sons + 1, sons + cnt + 1);

        dp[nod][0] = computeAuxDP(sons, cnt);
        dp[nod][1] = aux;
    }
}

int main()
{
    ifstream in("petsoft.in");
    ofstream out("petsoft.out");

    ios_base::sync_with_stdio(false);

    in >> N;

    for ( int i = 2; i <= N; ++i )
    {
        int dad;
        in >> dad;

        addEdge(dad, i);
    }

    DFS(1);

    out << dp[1][1] << "\n";

    return 0;
}
