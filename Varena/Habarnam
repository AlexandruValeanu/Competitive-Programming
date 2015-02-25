#include <bits/stdc++.h>

using namespace std;

FILE *in, *out;

///---------------------------------------------------------
const int BS = (1 << 16);
char buffer[BS];
int position = BS;

inline char getChar()
{
    if (position == BS)
    {
        position = 0;
        fread(buffer, BS, 1, in);
    }

    return buffer[position++];
}

inline int getNr()
{
    int a = 0;
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
///---------------------------------------------------------

const int Nmax = (1 << 17);
const long long INF = (1LL << 60);

struct __attribute__((__packed__)) Node
{
    long long totalSum : 50;
    long long bestPrefix : 50;
    long long bestSuffix : 50;
    long long bestSum : 50;

    explicit Node() : totalSum(0), bestPrefix(0), bestSuffix(0), bestSum(0)
    {
    }

    void initWithValue(const long long value)
    {
        totalSum = bestPrefix = bestSuffix = bestSum = value;
    }

    Node(const long long value) : totalSum(value), bestPrefix(value), bestSuffix(value), bestSum(value)
    {
    }

};

Node A[2 * Nmax];
int v[Nmax];
int N, M;

inline void Merge(Node& sol, const Node& L, const Node& R)
{
    sol.totalSum   = L.totalSum + R.totalSum;
    sol.bestPrefix = max(L.bestPrefix, L.totalSum + R.bestPrefix);
    sol.bestSuffix = max(R.bestSuffix, R.totalSum + L.bestSuffix);
    sol.bestSum    = max(max(L.bestSum, R.bestSum), L.bestSuffix + R.bestPrefix);
}

void build(int nod, int st, int dr)
{
    if (st == dr)
    {
        A[nod].initWithValue(v[st]);
    }
    else
    {
        int m = (st + dr) >> 1;

        build(nod << 1, st, m);
        build((nod << 1) | 1, m + 1, dr);

        Merge(A[nod], A[nod << 1], A[(nod << 1) | 1]);
    }
}

void update(int nod, int st, int dr, int pos, int value)
{
    if (st == dr)
    {
        A[nod].initWithValue(value);
    }
    else
    {
        int m = (st + dr) >> 1;

        if ( pos <= m )
            update(nod << 1, st, m, pos, value);
        else
            update((nod << 1) | 1, m + 1, dr, pos, value);

        Merge(A[nod], A[nod << 1], A[(nod << 1) | 1]);
    }
}

Node query(int nod, int st, int dr, int st_q, int dr_q)
{
    if (st_q <= st && dr <= dr_q)
        return A[nod];
    else
    {
        int m = (st + dr) >> 1;
        Node sol;

        if ( st_q <= m && m < dr_q )
        {
            Merge(sol, query(nod << 1, st, m, st_q, dr_q), query((nod << 1) | 1, m + 1, dr, st_q, dr_q));
        }
        else
        {
            if ( st_q <= m )
                sol = query(nod << 1, st, m, st_q, dr_q);
            else
                sol = query((nod << 1) | 1, m + 1, dr, st_q, dr_q);
        }

        return sol;
    }
}

int main()
{
     in = fopen("habarnam.in", "r");
    out = fopen("habarnam.out", "w");

    N = getNr(); M = getNr();

    for ( int i = 1; i <= N; ++i )
        v[i] = getNr();

    build(1, 1, N);
    fprintf(out, "%lld\n", max(A[1].bestSum, 0LL));

    for ( int i = 1; i <= M; ++i )
    {
        int x = getNr();
        int y = getNr();

        update(1, 1, N, x, y);
        fprintf(out, "%lld\n", max(A[1].bestSum, 0LL));
    }

    return 0;
}
