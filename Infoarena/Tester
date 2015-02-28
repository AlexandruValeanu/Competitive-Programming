#include <bits/stdc++.h>

using namespace std;

///-------------------------------------------------
const int BS = (1 << 16);
char buffer[BS];
int position = BS;

inline char getChar()
{
    if ( position == BS )
    {
        position = 0;
        fread(buffer, BS, 1, stdin);
    }

    return buffer[position++];
}

inline int getNr()
{
    int a = 0;
    char ch;

    do
    {
        ch = getChar();

    } while ( !isdigit(ch) );

    do
    {
        a = (a << 3) + (a << 1) + ch - '0';
        ch = getChar();

    } while( isdigit(ch) );

    return a;
}
///-------------------------------------------------

const int Mmax = 5000 + 1;

struct Edge
{
    short x;
    short y;
};

Edge E[Mmax];
vector<short> G[Mmax];
vector<short> eulerPath;
short grad_in[Mmax], grad_out[Mmax];
vector<short> ST;

int N, M;

void euler(short nod)
{
    while ( G[nod].size() )
    {
        short w = G[nod].back();
        G[nod].pop_back();

        ST.push_back(nod);
        nod = w;
    }
}


void Euler_Path(short nod)
{
    ST.push_back(nod);

    do
    {
        nod = ST.back();
        ST.pop_back();
        euler(nod);

        eulerPath.push_back(nod);

    } while ( ST.empty() == false );
}

int main()
{
    freopen("tester.in", "r", stdin);
    freopen("tester.out", "w", stdout);

    N = getNr(); M = getNr();

    for ( int i = 1; i <= M; ++i )
    {
        E[i].x = getNr();
        E[i].y = getNr();
    }

    for ( int i = 1; i <= M; ++i )
        for ( int j = 1; j <= M; ++j )
            if ( i != j && E[i].y == E[j].x )
            {
                G[i].push_back(j);
                grad_in[j]++;
                grad_out[i]++;
            }

    for (int i = 1; i <= M; ++i )
    {
        if ( grad_in[i] < grad_out[i] )
        {
            int d = grad_out[i] - grad_in[i];

            for ( int k = 1; k <= d; ++k )
                G[0].push_back(i);
        }

        if ( grad_out[i] < grad_in[i] )
        {
            int d = grad_in[i] - grad_out[i];

            for ( int k = 1; k <= d; ++k )
                G[i].push_back(0);
        }
    }

    Euler_Path(0);
    reverse(eulerPath.begin(), eulerPath.end());
    int dim = (int)eulerPath.size();

    for ( int i = 0; i < dim; ++i )
    {
        if ( eulerPath[i] == 0 )
        {
            if ( i != 0 && i != dim - 1 )
                printf("R ");
        }
        else
        {
            short x = E[ eulerPath[i] ].x;
            short y = E[ eulerPath[i] ].y;

            if ( x != E[ eulerPath[i - 1] ].y )
                printf("%d ", x);

            printf("%d ", y);
        }
    }

    puts("");

    return 0;
}
