#include <bits/stdc++.h>

using namespace std;

const int Nmax = 200000;

int st[Nmax], dr[Nmax];
int N;

void inorder( int node, int &last, int &prim )
{
    if ( st[node] != -1 )
        inorder( st[node], last, prim );

    if ( last == -1 )
        prim = node;
    else
        dr[last] = node;

    st[node] = last;
    last = node;

    if ( dr[node] != -1 )
        inorder( dr[node], last, prim );
}

int main()
{
    FILE *f = fopen("pointeri.in", "r");
    FILE *g = fopen("pointeri.out", "w");

    int root, prim = -1, last = -1;

    fscanf(f, "%d %d\n", &N, &root);

    for ( int i = 0; i < N; ++i )
        fscanf(f, "%d", &st[i]);

    for ( int i = 0; i < N; ++i )
        fscanf(f, "%d", &dr[i]);

    inorder( root, last, prim );

    fprintf(g, "%d\n", prim);

    for ( int i = 0; i < N; ++i )
        fprintf(g, "%d ", st[i]);

    fprintf(g, "\n");

    for ( int i = 0; i < N; ++i )
        fprintf(g, "%d ", dr[i]);

    fprintf(g, "\n");

    return 0;
}
