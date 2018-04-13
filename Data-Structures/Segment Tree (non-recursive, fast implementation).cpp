#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;
const int NIL = numeric_limits<int>::min();

int T[2 * Nmax];
int N, M;

int join(int a, int b)
{
    return max(a, b);
}

void build()
{
    for (int i = N - 1; i >= 1; i--)
        T[i] = join(T[(i << 1)], T[(i << 1) | 1]);
}

void update(int x, int value)
{
    x += N;

    T[x] = value;

    while (x > 1)
    {
        T[x >> 1] = join(T[x], T[x ^ 1]);
        x >>= 1;
    }
}

int query(int x, int y) /// [x, y)
{
    x += N;
    y += N;

    int solX = NIL;
    int solY = NIL;

    while (x < y)
    {
        if (x & 1)
        {
            solX = join(solX, T[x]);
            x++;
        }

        if (y & 1)
        {
            y--;
            solY = join(T[y], solY);
        }

        x >>= 1;
        y >>= 1;
    }

    return join(solX, solY);
}

int main()
{
    return 0;
}
