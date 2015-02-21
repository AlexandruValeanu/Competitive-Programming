#include <bits/stdc++.h>

using namespace std;

const int Nmax = 3e5 + 10;
const int Mmax = 5e5 + 10;
const int INF = 2000000000;

struct Node
{
    int x, y, z;
};

Node Nave[Mmax];
vector<int> A[4 * Nmax];
int N, M;

void sterge(int nod, int st, int dr, int st_q, int dr_q, int val)
{
    if ( st_q <= st && dr <= dr_q )
    {
        if ( A[nod].size() && val == A[nod].back() )
            A[nod].pop_back();
    }
    else
    {
        int m = (st + dr) / 2;

        if ( st_q <= m )
            sterge(2 * nod, st, m, st_q, dr_q, val);

        if ( m < dr_q )
            sterge(2 * nod + 1, m + 1, dr, st_q, dr_q, val);
    }
}

void adauga(int nod, int st, int dr, int st_q, int dr_q, int val)
{
    if ( st_q <= st && dr <= dr_q )
    {
        if ( !A[nod].size() || val < A[nod].back() )
            A[nod].push_back(val);
    }
    else
    {
        int m = (st + dr) / 2;

        if ( st_q <= m )
            adauga(2 * nod, st, m, st_q, dr_q, val);

        if ( m < dr_q )
            adauga(2 * nod + 1, m + 1, dr, st_q, dr_q, val);
    }
}

void query(int nod, int st, int dr, int pos, int& sol)
{
    if ( A[nod].size() )
        sol = min(sol, A[nod].back());

    if ( st == dr )
        return;
    else
    {
        int m = (st + dr) / 2;

        if ( pos <= m )
            query(2 * nod, st, m, pos, sol);
        else
            query(2 * nod + 1, m + 1, dr, pos, sol);
    }
}

int main()
{
    freopen("invazia.in", "r", stdin);
    freopen("invazia.out", "w", stdout);

    scanf("%d %d ", &N, &M);

    int contor = 0;

    while ( M-- )
    {
        char ch;
        int x, y, z;

        scanf("%c ", &ch);

        if ( ch == 'I' )
        {
            scanf("%d %d %d ", &x, &y, &z);

            contor++;
            Nave[contor] = {x, y, z};

            adauga(1, 1, N, x, y, z);
        }

        if ( ch == 'E' )
        {
            sterge(1, 1, N, Nave[contor].x, Nave[contor].y, Nave[contor].z);
            contor--;
        }

        if ( ch == 'R' )
        {
            scanf("%d ", &x);
            int sol = INF;

            query( 1, 1, N, x, sol );

            if ( sol == INF)
                puts("GUITZZZ!");
            else
                printf("%d\n", sol);
        }
    }
    return 0;
}
