#include <bits/stdc++.h>

using namespace std;

const int Nmax = 26 * 26 + 1;
const int Mmax = 100000 + 1;
const int NIL = -1;
const int Lmax = 22;

struct Edge
{
    int nod;
    int urm;
    int indice;
};

struct Node
{
    int nod;
    int indice;
};

Edge G[Mmax];
int head[Nmax + 1];

int degree_in[Nmax + 1], degree_out[Nmax + 1];
bool vis[Nmax + 1];

Node stiva[Mmax + 2];
int top;

int sizeCycle;
int eulerPath[Mmax + 2];

char str[Mmax][Lmax];

int N, contor;

int getNode(char a, char b)
{
    int id = a - 'a';

    return id * 26 + (b - 'a');
}

void addEdge(int x, int y, int ind)
{
    G[contor].nod = y;
    G[contor].urm = head[x];
    G[contor].indice = ind;
    head[x] = contor;

    degree_out[x]++;
    degree_in[y]++;

    contor++;
}

void dfs(int nod)
{
    vis[nod] = 1;

    for (int p = head[nod]; p != NIL; p = G[p].urm)
    {
        int son = G[p].nod;

        if ( !vis[son] )
            dfs(son);
    }
}

int modul(int a)
{
    if ( a > 0 )
        return a;
    else
        return -a;
}

int findRoot()
{
    for ( int i = 0; i < Nmax; ++i )
        if ( degree_out[i] > degree_in[i] )
            return i;

    for ( int i = 0; i < Nmax; ++i )
        if ( degree_in[i] )
            return i;

    return -1;
}

bool isEulerian()
{
    int A = 0, B = 0;

    for ( int i = 0; i < Nmax; ++i )
    {
        if ( modul( degree_in[i] - degree_out[i] ) > 1 )
            return false;

        if ( degree_in[i] == degree_out[i] + 1 )
            A++;

        if ( degree_out[i] == degree_in[i] + 1 )
            B++;
    }

    if ( !( (A == 0 && B == 0) || (A == 1 && B == 1) ) )
        return false;

    int R = findRoot();

    dfs(R);

    for ( int i = 0; i < Nmax; ++i )
        if ( degree_out[i] && !vis[i] )
            return false;

    return true;
}

void euler(int nod)
{
    top = 1;
    stiva[1].nod = nod;
    stiva[1].indice = -1;

    while (top)
    {
        nod = stiva[top].nod;

        while ( head[nod] != NIL && G[ head[nod] ].nod == NIL )
            head[nod] = G[ head[nod] ].urm;

        if ( head[nod] == NIL )
        {
            sizeCycle++;
            eulerPath[sizeCycle] = stiva[top].indice;

            top--;
        }
        else
        {
            top++;
            stiva[top].nod = G[ head[nod] ].nod;
            stiva[top].indice = G[ head[nod] ].indice;

            head[nod] = G[ head[nod] ].urm;
        }
    }
}

/**
void gen_teste()
{
    srand(time(NULL));

    static char sir[Lmax];
    const int N = 100000;
    int l;

    l = 2 + rand() % 15;

    deque<char> Deck;
    vector<string> Words;

    for ( int i = 1; i <= N; ++i )
    {
        l = 2 + rand() % 15;
        int start = 1;

        string cuvant;

        if ( Deck.size() )
        {
            cuvant.push_back(Deck.front());
            cuvant.push_back(Deck.back());

            start = 3;
        }

        for ( int j = start; j <= l; ++j )
        {
            char ch = char( 'a' + rand() % 25 );
            cuvant.push_back(ch);

            Deck.push_back(ch);
            if ( Deck.size() > 2 )
                Deck.pop_front();
        }

        Words.push_back(cuvant);
    }

    random_shuffle(Words.begin(), Words.end());
    random_shuffle(Words.begin(), Words.end());
    random_shuffle(Words.begin(), Words.end());
    random_shuffle(Words.begin(), Words.end());

    ofstream out("fazan.in");

        out << Words.size() << "\n";

    for(auto& x: Words)
        out << x << "\n";

    out.close();
}

void validareRaspuns()
{
    char a, b;

    assert(sizeCycle - 1 == N);

    for ( int i = sizeCycle - 1; i >= 1; i-- )
    {
        assert( 0 <= eulerPath[i] && eulerPath[i] < N );

        if ( i != sizeCycle - 1 )
        {
            assert( str[ eulerPath[i] ][0] == a );
            assert( str[ eulerPath[i] ][1] == b );
        }

        int l = strlen( str[ eulerPath[i] ] );

        a = str[ eulerPath[i] ][l - 2];
        b = str[ eulerPath[i] ][l - 1];
    }
}
**/

int main()
{
    FILE *in = fopen("fazan.in", "r");
    FILE *out = fopen("fazan.out", "w");

    fscanf(in, "%d\n", &N);

    ///assert( 1 <= N && N <= 100000 );

    for ( int i = 0; i < Nmax; ++i )
        head[i] = NIL;

    for ( int i = 0; i < N; ++i )
    {
        fscanf(in, "%s\n", str[i]);

        int a, b, l = strlen(str[i]);

        ///assert( 2 <= l && l <= 20 );

        a = getNode(str[i][0], str[i][1]);
        b = getNode(str[i][l - 2], str[i][l - 1]);

        addEdge(a, b, i);
    }

    if ( isEulerian() == false )
        fprintf(out, "imposibil\n");
    else
    {
        euler(findRoot());

        for ( int i = sizeCycle - 1; i >= 1; i-- )
            fprintf(out, "%s\n", str[ eulerPath[i] ]);
    }

    return 0;
}
