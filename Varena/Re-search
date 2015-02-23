#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100;
const int Mmax = 200000 + 1;
const int Lmax = 5000 + 1;
const int SIGMA = 26;
const int NIL = -2;

char query[Mmax];
short solution[Mmax];

char str[Nmax][Lmax];
int L;

short position[Lmax][SIGMA];
short aux_pos[SIGMA];

short stiva[Lmax];
int top;

int N, M;

void precalculate(char s[])
{
    for ( int i = 0; i < SIGMA; ++i )
    {
        aux_pos[i] = NIL;
        position[L][i] = NIL;
    }

    for ( int i = L - 1; i >= 0; i-- )
    {
        aux_pos[ s[i] - 'a' ] = i;

        for ( int j = 0; j < SIGMA; ++j )
            position[i][j] = aux_pos[j];
    }
}

int main()
{
    FILE *in = fopen("search.in", "r");
    FILE *out = fopen("search.out", "w");

    fscanf(in, "%d %d ", &N, &M);

    for ( int i = 0; i < N; ++i )
        fscanf(in, "%s ", str[i]);

    for ( int i = 0; i < M; ++i )
        fscanf(in, "%c ", &query[i]);

    for ( int i = 0; i < N; ++i )
    {
        L = strlen(str[i]);
        precalculate(str[i]);

        stiva[ top = 0 ] = -1;

        for ( int j = 0; j < M; ++j )
        {
            if ( isalpha(query[j]) )
            {
                int p = stiva[top];

                if ( p != NIL )
                    p = position[p + 1][ query[j] - 'a' ];

                stiva[ ++top ] = p;
            }
            else
                top--;

            if ( stiva[top] != NIL )
                solution[j]++;
        }
    }

    for ( int i = 0; i < M; ++i )
        fprintf(out, "%d\n", solution[i]);

    return 0;
}
