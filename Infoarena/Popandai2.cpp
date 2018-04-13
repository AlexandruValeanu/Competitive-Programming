#include <bits/stdc++.h>

using namespace std;

#define Point pair<int,int>
#define x first
#define y second

const int Nmax = 1000;

Point P[2 * Nmax];
int N;

int CCW(Point A, Point B, Point C)
{
    return (C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x);
}

int area(int i, int j, int k)
{
    return abs(CCW(P[i], P[j], P[k]));
}

int main()
{
    ifstream in("popandai2.in");
    ofstream out("popandai2.out");

    in >> N;

    for (int i = 0; i < N; ++i)
    {
        in >> P[i].x >> P[i].y;
        P[N + i] = P[i];
    }

    int best = 0;

    for (int i = 0; i < N; ++i)
    {
        int p = i + 1;
        int q = i + 3;

        for (int j = i + 2; j < N; ++j)
        {
            while (p < j && area(i, j, p + 1) >= area(i, j, p))
                p++;

            while (q < i + N && area(i, j, q + 1) >= area(i, j, q))
                q++;

            best = max(best, area(i, j, p) + area(i, j, q));
        }
    }

    out << fixed << setprecision(1) << (best / 2.0) << "\n";

    return 0;
}
