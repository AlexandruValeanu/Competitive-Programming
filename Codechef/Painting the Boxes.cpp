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

const int Nmax = 1e5 + 2;

int v[Nmax];
int W, N;
int T, Q;

struct Node
{
    int culoareLeft;
    int culoareRight;

    int length;
    int prefix, suffix;

    long long sol;

    explicit Node() : culoareLeft(0), culoareRight(0), length(0), prefix(0), suffix(0), sol(0) {
    }

    Node(const int v) : culoareLeft(v), culoareRight(v), length(1), prefix(1), suffix(1) {

        if (W == 1)
            sol = 1;
        else
            sol = 0;
    }
};

Node join(Node& L, Node& R)
{
    Node ans = Node();

    if (L.culoareRight != R.culoareLeft)
    {
        ans.culoareLeft = L.culoareLeft;
        ans.culoareRight = R.culoareRight;

        ans.length = L.length + R.length;

        ans.prefix = L.prefix;
        ans.suffix = R.suffix;

        ans.sol = L.sol + R.sol;
    }
    else
    {
        ans.culoareLeft = L.culoareLeft;
        ans.culoareRight = R.culoareRight;

        ans.sol = L.sol + R.sol;

        if (L.suffix >= W)
            ans.sol -= (L.suffix - W + 1);

        if (R.prefix >= W)
            ans.sol -= (R.prefix - W + 1);

        int val = L.suffix + R.prefix;

        if (val >= W)
            ans.sol += (val - W + 1);

        ans.length = L.length + R.length;

        if (L.prefix == L.length)
            ans.prefix = L.prefix + R.prefix;
        else
            ans.prefix = L.prefix;

        if (R.suffix == R.length)
            ans.suffix = R.suffix + L.suffix;
        else
            ans.suffix = R.suffix;
    }

    return ans;
}

Node A[4 * Nmax];

void build(int nod, int st, int dr)
{
    if (st == dr)
        A[nod] = Node(v[st]);
    else
    {
        int m = (st + dr) / 2;

        build(2 * nod, st, m);
        build(2 * nod + 1, m + 1, dr);

        A[nod] = join(A[2 * nod], A[2 * nod + 1]);
    }
}

void update(int nod, int st, int dr, int pos, int new_key)
{
    if (st == dr)
        A[nod] = Node(new_key);
    else
    {
        int m = (st + dr) / 2;

        if (pos <= m)
            update(2 * nod, st, m, pos, new_key);
        else
            update(2 * nod + 1, m + 1, dr, pos, new_key);

        A[nod] = join(A[2 * nod], A[2 * nod + 1]);
    }
}

int main()
{
    ///freopen("data.in", "r", stdin);

    T = getNr();

    while (T--)
    {
        N = getNr(); W = getNr();

        for (int i = 1; i <= N; ++i)
            v[i] = getNr();

        build(1, 1, N);

        Q = getNr();

        while (Q--)
        {
            int a, b;
            a = getNr(); b = getNr();

            update(1, 1, N, a, b);

            printf("%lld\n", A[1].sol);
        }
    }

    return 0;
}
