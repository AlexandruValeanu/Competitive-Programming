#include <bits/stdc++.h>

using namespace std;

#define Point pair<double,double>
#define x first
#define y second

/// assumes that polygon is given in clockwise/counter-clockwise order
double signedArea(vector<Point>& points)
{
    double area = 0;
    int N = points.size();

    for (int i = 0; i < N; ++i)
        area += (points[i].x * points[(i + 1) % N].y - points[(i + 1) % N].x * points[i].y);

    return area / 2.0;
}

int main()
{
    return 0;
}
