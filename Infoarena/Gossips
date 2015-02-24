#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

set<int> SetDown[8 * Nmax], SetUp[8 * Nmax];
vector<int> G[Nmax];
int start[Nmax], finish[Nmax], timer;
bool isRoot[Nmax];

int N, M, Q;

void DFS(int nod)
{
    start[nod] = ++timer;

    for ( unsigned i = 0; i < G[nod].size(); ++i )
        DFS(G[nod][i]);

    finish[nod] = ++timer;
}

void update(int nod, int st, int dr, int st_X, int dr_X, int st_Y, int dr_Y)
{
    SetUp[nod].insert(st_Y);

    if ( st_X <= st && dr <= dr_X )
    {
        SetDown[nod].insert(st_Y);
    }
    else
    {
        int m = (st + dr) / 2;

        if ( st_X <= m )
            update(2 * nod, st, m, st_X, dr_X, st_Y, dr_Y);

        if ( m < dr_X )
            update(2 * nod + 1, m + 1, dr, st_X, dr_X, st_Y, dr_Y);
    }
}

bool query(int nod, int st, int dr, int st_X, int dr_X, int st_Y, int dr_Y)
{
    auto it1 = SetDown[nod].lower_bound(st_Y);

    if ( it1 != SetDown[nod].end() && *it1 <= dr_Y )
        return 1;

    auto it2 = SetUp[nod].lower_bound(st_Y);

    if ( it2 == SetUp[nod].end() || *it2 > dr_Y )
        return 0;

    if ( st == dr )
        return 0;
    else
    {
        int m = (st + dr) / 2;
        bool sol = false;

        if ( st_X <= m )
            sol |= query(2 * nod, st, m, st_X, dr_X, st_Y, dr_Y);

        if ( m < dr_X )
            sol |= query(2 * nod + 1, m + 1, dr, st_X, dr_X, st_Y, dr_Y);

        return sol;
    }
}

int main()
{
    ifstream in("gossips.in");
    ofstream out("gossips.out");

    ios_base::sync_with_stdio(false);

    in >> N >> M >> Q;

    for ( int i = 1; i <= M; ++i )
    {
        int a, b;
        in >> a >> b;

        G[a].push_back(b);
        isRoot[b] = true;
    }

    for ( int i = 1; i <= N; ++i )
        if ( isRoot[i] == false )
            DFS(i);

    while ( Q-- )
    {
        int tip, x, y;

        in >> tip >> x >> y;

        if ( tip == 2 )
        {
            update(1, 1, timer, start[x], finish[x], start[y], finish[y]);
        }
        else
        {
            bool value = query(1, 1, timer, start[x], finish[x], start[y], finish[y]);

            if (value)
                out << "YES\n";
            else
                out << "NO\n";
        }
    }

    return 0;
}
