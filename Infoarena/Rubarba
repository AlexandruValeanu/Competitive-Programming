#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define EPS 1e-14
#define MAX_N 100000

#define Point pair<double,double>
#define x first
#define y second

Point P[MAX_N];
int N;

double area(double phi)
{
    double minX = INF, minY = INF;
    double maxX = -INF, maxY = -INF;

    double cs = cos(phi);
    double sn = sin(phi);

    for (int i = 0; i < N; ++i)
    {
        double X = (long double) P[i].x * cs - P[i].y * sn;
        double Y = (long double) P[i].x * sn + P[i].y * cs;

        minX = min(minX, X);
        maxX = max(maxX, X);

        minY = min(minY, Y);
        maxY = max(maxY, Y);
    }

    return (maxX - minX) * (maxY - minY);
}

double ternary_search(double l, double r)
{
    if (r - l < EPS)
        return l;

    double m1 = l + (r - l) / 3.0;
    double m2 = r - (r - l) / 3.0;

    if (area(m1) < area(m2))
        return ternary_search(l, m2);
    else
        return ternary_search(m1, r);
}

int main()
{
    ifstream in("rubarba.in");
    ofstream out("rubarba.out");

    in >> N;

    for (int i = 0; i < N; ++i)
        in >> P[i].x >> P[i].y;

    out << fixed << setprecision(2) << area(ternary_search(0, M_PI_2));
    out << "\n";

    return 0;
}
