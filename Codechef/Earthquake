#include <bits/stdc++.h>

using namespace std;

///TO-DO fast reading + fast rotations

const int MAX_L = 12; ///lcm(2, 3, 4) = 12
const int MAX_N = 800000;
const int MAX_Q = 200000;

struct Node
{
    int rots[MAX_L];
    int forceLazy;
};

Node tree[MAX_N * 4];
int V[MAX_N];
int power10[10];
int N, Q;

int shiftLeftInt(int x, int lg)
{
    return (x % power10[lg - 1]) * 10 + x / power10[lg - 1];
}

void combine(Node &T, const Node &L, const Node &R)
{
    for (int i = 0; i < MAX_L; ++i)
    {
        int p1 = (i + L.forceLazy) % MAX_L;
        int p2 = (i + R.forceLazy) % MAX_L;

        T.rots[i] = max(L.rots[p1], R.rots[p2]);
    }
}

void build(int node, int st, int dr)
{
    if (st == dr)
    {
        int curr = V[st];

        int numberDigits = 0;
        int tmp = V[st];

        do
        {
            numberDigits++;
            tmp /= 10;

        } while (tmp);

        tree[node].rots[0] = curr;

        for (int i = 1; i < MAX_L; ++i)
        {
            curr = shiftLeftInt(curr, numberDigits);
            tree[node].rots[i] = curr;
        }
    }
    else
    {
        int m = (st + dr) / 2;

        build(2 * node, st, m);
        build(2 * node + 1, m + 1, dr);

        combine(tree[node], tree[2 * node], tree[2 * node + 1]);
    }
}

void lazy(int node)
{
    tree[2 * node].forceLazy     += tree[node].forceLazy;
    tree[2 * node + 1].forceLazy += tree[node].forceLazy;

    tree[node].forceLazy = 0;
}

void update(int node, int st, int dr, const int l, const int r, const int force)
{
    if (l <= st && dr <= r)
    {
        tree[node].forceLazy += force;
    }
    else
    {
        int m = (st + dr) / 2;

        lazy(node);

        if (l <= m)
            update(2 * node, st, m, l, r, force);

        if (m < r)
            update(2 * node + 1, m + 1, dr, l, r, force);

        combine(tree[node], tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int node, int st, int dr, const int l, const int r)
{
    if (l <= st && dr <= r)
    {
        return tree[node].rots[tree[node].forceLazy % MAX_L];
    }
    else
    {
        int m = (st + dr) / 2;
        int sol = 0;

        lazy(node);

        if (l <= m)
        {
            int ans = query(2 * node, st, m, l, r);
            sol = max(sol, ans);
        }

        if (m < r)
        {
            int ans = query(2 * node + 1, m + 1, dr, l, r);
            sol = max(sol, ans);
        }

        combine(tree[node], tree[2 * node], tree[2 * node + 1]);

        return sol;
    }
}

int main()
{
    //ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> V[i];

    power10[0] = 1;

    for (int i = 1; i < 9; ++i)
        power10[i] = power10[i - 1] * 10;

    build(1, 0, N - 1);

    cin >> Q;

    while (Q--)
    {
        int tip, L, R, F;

        cin >> tip >> L >> R;

        if (tip == 0)
        {
            cin >> F;

            update(1, 0, N - 1, L, R, F);
        }
        else
        {
            cout << query(1, 0, N - 1, L, R) << "\n";
        }
    }

    return 0;
}
