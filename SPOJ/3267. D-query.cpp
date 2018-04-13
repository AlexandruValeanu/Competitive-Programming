#include <bits/stdc++.h>

using namespace std;

inline int readNumber()
{
    register int a = 0;
    char ch;

    do
    {
        ch = getchar();

    } while ( !isdigit(ch) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar();

    } while ( isdigit(ch) );

    return a;
}

const int Nmax = 30000;
const int LgMax = 15;

struct Node
{
    int L, R;
    int index;
    int size;
};

Node A[Nmax * LgMax * 2];
int T[Nmax];
map <int, int> position;
int N, M, contor;

int build( int st, int dr )
{
    if ( st > dr ) return 0;

    int idx = ++contor;
    int m = ( st + dr ) / 2;

    A[idx] = { build(st, m - 1), build(m + 1, dr), m, 0 };

    return idx;
}

int update( int nod, int new_index, int value )
{
    if ( nod == 0 ) return 0;

    int idx = ++contor;
    int new_L = A[nod].L;
    int new_R = A[nod].R;

    if ( new_index < A[nod].index ) new_L = update( new_L, new_index, value );
    if ( new_index > A[nod].index ) new_R = update( new_R, new_index, value );

    A[idx] = { new_L, new_R, A[nod].index, A[nod].size + value };

    return idx;
}

int query( int nod, int index )
{
    if ( index < A[nod].index )
        return query( A[nod].L, index ) + A[nod].size - A[ A[nod].L ].size;

    if ( index > A[nod].index )
        return query( A[nod].R, index );

    return A[nod].size - A[ A[nod].L ].size;
}

int main()
{
    ///freopen("data.in", "r", stdin);

    N = readNumber();
    T[0] = build( 1, N );

    for ( int i = 1; i <= N; ++i )
    {
        int val, pos;

        val = readNumber();
        pos = position[val];

        if ( pos == 0 )
            T[i] = update( T[i - 1], i, +1 );
        else
        {
            int new_node = update( T[i - 1], pos, -1 );
            T[i] = update( new_node, i, +1 );
        }

        position[val] = i;
    }

    M = readNumber();

    while ( M-- )
    {
        int a, b;
        a = readNumber(); b = readNumber();

        printf("%d\n", query(T[b], a));
    }

    return 0;
}

