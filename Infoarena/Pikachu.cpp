#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

struct Node
{
    int count;
    long long sum;
};

Node A[4 * Nmax];
int values[Nmax];
int pos[Nmax], posInOrder[Nmax];

int N, K;

Node merge(Node A, Node B)
{
    Node sol;
    sol.count = A.count + B.count;
    sol.sum = A.sum + B.sum;

    return sol;
}

void update(int nod, int st, int dr, int pos, int value, int add)
{
    if ( st == dr )
    {
        A[nod].sum = value;
        A[nod].count = add;
    }
    else
    {
        int m = (st + dr) / 2;

        if ( pos <= m )
            update(2 * nod, st, m, pos, value, add);
        else
            update(2 * nod + 1, m + 1, dr, pos, value, add);

        A[nod] = merge(A[2 * nod], A[2 * nod + 1]);
    }
}

long long query(int nod, int st, int dr, int st_q, int dr_q)
{
    if ( st_q > dr_q )
        return 0;

    if ( st_q <= st && dr <= dr_q )
        return A[nod].sum;
    else
    {
        int m = (st + dr) / 2;
        long long s = 0;

        if ( st_q <= m )
            s += query(2 * nod, st, m, st_q, dr_q);

        if ( m < dr_q )
            s += query(2 * nod + 1, m + 1, dr, st_q, dr_q);

        return s;
    }
}

int kth_element(int nod, int st, int dr, int k)
{
    if ( st == dr )
        return st;
    else
    {
        int m = (st + dr) / 2;

        if ( k <= A[2 * nod].count )
            return kth_element(2 * nod, st, m, k);
        else
            return kth_element(2 * nod + 1, m + 1, dr, k - A[2 * nod].count);
    }
}

inline int cmp(const int a, const int b)
{
    return values[a] < values[b];
}

int main()
{
    ifstream in("pikachu.in");
    ofstream out("pikachu.out");

    ios_base::sync_with_stdio(false);

    in >> N >> K;

    for ( int i = 1; i <= N; ++i )
    {
        in >> values[i];
        pos[i] = i;
    }

    sort(pos + 1, pos + N + 1, cmp);

    for ( int i = 1; i <= N; ++i )
        posInOrder[ pos[i] ] = i;

    long long best = (1LL << 60);

    for ( int i = 1; i <= N; ++i )
    {
        update(1, 1, N, posInOrder[i], values[i], 1);

        if ( i >= K + 1 )
            update(1, 1, N, posInOrder[i - K], 0, 0);

        if ( i >= K )
        {
            int middle = 1 + (K / 2);
            int posMedian = kth_element(1, 1, N, middle);

            long long sol = 0;

            sol += 1LL * values[ pos[posMedian] ] * (K / 2) - query(1, 1, N, 1, posMedian - 1);
            sol += query(1, 1, N, posMedian + 1, N) - 1LL * values[ pos[posMedian] ] * (K - middle);

            best = min(best, sol);
        }
    }

    out << best << "\n";

    return 0;
}
