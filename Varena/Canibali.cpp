#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2048 + 1;

struct Canibal
{
    int X, Y, Z, T;

    bool operator < (const Canibal& A) const
    {
        return (X < A.X && Y < A.Y && Z < A.Z && T < A.T);
    }

    bool operator == (const Canibal& A) const
    {
        return (X == A.X && Y == A.Y && Z == A.Z && T == A.T);
    }
};

Canibal C[Nmax];
vector<int> G[2 * Nmax];
bool used[2 * Nmax];
int L[2 * Nmax], R[2* Nmax];
int N;

bool validEdge(int x, int y)
{
    if (C[y] == C[x])
        return x < y;

    return C[y] < C[x];
}

bool pairUp(int nod)
{
    if (used[nod])
        return false;

    used[nod] = true;

    for (auto son: G[nod])
        if (!R[son])
        {
            L[nod] = son;
            R[son] = nod;
            return true;
        }

    for (auto son: G[nod])
        if (pairUp(R[son]))
        {
            L[nod] = son;
            R[son] = nod;
            return true;
        }

    return false;
}

int matching()
{
    bool change;

    do
    {
        change = false;

        memset(used, 0, sizeof(used));

        for (int i = 1; i <= 2 * N; ++i)
            if (!L[i])
                change |= pairUp(i);

    } while (change);

    int nr_c = 0;

    for (int i = 1; i <= 2 * N; ++i)
        nr_c += (L[i] > 0);

    return nr_c;
}

int main()
{
    ifstream in("canibali.in");
    ofstream out("canibali.out");

    in >> N;

    for (int i = 1; i <= N; ++i)
        in >> C[i].X >> C[i].Y >> C[i].Z >> C[i].T;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            if (validEdge(i, j))
            {
                G[i].push_back(j);
                G[i + N].push_back(j);
            }
        }

    out << N - matching();

    return 0;
}
