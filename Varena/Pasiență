#include <bits/stdc++.h>

using namespace std;

FILE *in, *out;

///-------------------------------------
const int BS = (1 << 16);
char buffer[BS];
int position = BS;

char getChar()
{
    if (position == BS)
    {
        position = 0;
        fread(buffer, BS, 1, in);
    }

    return buffer[position++];
}

int getNr()
{
    int a = 0;
    char ch;

    do
    {
        ch = getChar();

    } while (!isdigit(ch));

    do
    {
        a = (a << 3) + (a << 1) + (ch - '0');
        ch = getChar();

    } while (isdigit(ch));

    return a;
}
///-------------------------------------

const int Nmax = 100000 + 1;
const int Mmax = 100000 + 1;

struct Edge
{
    int nod;
    int urm;
};

Edge G[4 * Mmax];
int head[Nmax];

bool used[Nmax];
int st[Nmax], dr[Nmax];

int N, contor;

void addEdge(int x, int y)
{
    contor++;
    G[contor].nod = y;
    G[contor].urm = head[x];
    head[x] = contor;
}

bool dfs(int nod)
{
    if (used[nod])
        return false;

    used[nod] = true;

    for (int p = head[nod]; p; p = G[p].urm)
    {
        int son = G[p].nod;

        if ( !dr[son] )
        {
            st[nod] = son;
            dr[son] = nod;

            return true;
        }
    }

    for (int p = head[nod]; p; p = G[p].urm)
    {
        int son = G[p].nod;

        if ( dfs(dr[son]) )
        {
            st[nod] = son;
            dr[son] = nod;

            return true;
        }
    }

    return false;
}

void Hopcroft_Karp()
{
    bool changed = true;

    do
    {
        changed = false;
        memset(used, 0, sizeof(used));

        for (int i = 1; i <= N; ++i)
            if ( !st[i] )
                changed |= dfs(i);

    } while (changed);

    for (int i = 1; i <= N; ++i)
        fprintf(out, "%d ", st[i]);

    fprintf(out, "\n");
}

int main()
{
    in = fopen("pasienta.in", "r");
    out = fopen("pasienta.out", "w");

    N = getNr();

    for (int k = 1; k <= 4; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            int a = getNr();
            addEdge(i, a);
        }
    }

    Hopcroft_Karp();
}
