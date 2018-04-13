#include <bits/stdc++.h>

using namespace std;

///---------------------------------------------------
const int BUFFER_SIZE = (1 << 16);
char buffer[BUFFER_SIZE];
int position = BUFFER_SIZE;

inline char getChar()
{
    if ( position == BUFFER_SIZE )
    {
        position = 0;
        fread(buffer, BUFFER_SIZE, 1, stdin);
    }

    return buffer[position++];
}

inline int getNr()
{
    register int a = 0;
    char ch;
    int sgn = 1;

    do
    {
        ch = getChar();

    } while ( !isdigit(ch) && ch != '-' );

    if ( ch == '-' )
    {
        sgn = -1;
        ch = getChar();
    }

    do
    {
        a = (a << 3) + (a << 1) + ch - '0';
        ch = getChar();

    } while ( isdigit(ch) );

    return a * sgn;
}
///---------------------------------------------------

const int Nmax = 3 * 1e5 + 1;

vector<int> G[Nmax];

int parent[Nmax];
int diameter[Nmax];

int dist[Nmax];

int N, M, Q;
int contor;

int Find(int x)
{
    if (x != parent[x])
        parent[x] = Find(parent[x]);

    return parent[x];
}

int deepest;
void dfs(int nod, int tata)
{
    if (deepest == 0 || dist[nod] > dist[deepest])
        deepest = nod;

    for (auto& son: G[nod])
    {
        if (son != tata)
        {
            dist[son] = dist[nod] + 1;
            dfs(son, nod);
        }
    }
}

int diametru(int nod)
{
    deepest = 0;
    dist[nod] = 1;
    dfs(nod, 0);

    int aux = deepest;
    dist[deepest] = 1;
    deepest = 0;

    dfs(aux, 0);

    return dist[deepest];
}

int Union(int a, int b)
{
    if (rand() & 1)
    {
        parent[a] = b;
        return b;
    }
    else
    {
        parent[b] = a;
        return a;
    }
}

int main()
{
    ///ifstream cin("data.in");

    srand(time(NULL));

    N = getNr(); M = getNr(); Q = getNr();

    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    while (M--)
    {
        int a, b;
        a = getNr(); b = getNr();

        G[a].push_back(b);
        G[b].push_back(a);

        Union(Find(a), Find(b));
    }

    for (int i = 1; i <= N; ++i)
        if (Find(i) == i)
        {
            diameter[i] = diametru(i) - 1;
        }

    for (int i = 1; i <= Q; ++i)
    {
        int tip, a, b;

        tip = getNr();

        if (tip == 1)
        {
            a = getNr();
            cout << diameter[ Find(a) ] << "\n";
        }
        else
        {
            a = getNr(); b = getNr();

            a = Find(a);
            b = Find(b);

            if (a == b)
                continue;

            int d = max(max(diameter[a], diameter[b]), (diameter[a] + 1) / 2 + (diameter[b] + 1) / 2 + 1);

            diameter[ Union(a, b) ] = d;
        }
    }

    return 0;
}
