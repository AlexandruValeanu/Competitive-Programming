#include <bits/stdc++.h>

using namespace std;

#define Point pair<double,double>
#define x first
#define y second

/**
    < 0 for counter-clockwise (trigonometric)
    = 0 for collinear
    > 0 for clockwise (anti-trigonometric)
**/
double CCW(const Point& A, const Point& B, const Point& C)
{
    return (C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x);
}

/// Points in the result will be listed in counter-clockwise order.
vector<Point> convexHull(vector<Point>& points)
{
    int N = points.size();
    int ind = 0;

    /// basic case
    if (N <= 3)
        return points;

    /// find lowest point (it belongs to the convex hull)
    for (int i = 1; i < N; ++i)
        if (points[i] < points[ind])
            ind = i;

    /// place it on the first position
    swap(points[0], points[ind]);

    /// sort points, using the lowset one, in counter-clockwise order (using c++ lambda)
    sort(points.begin() + 1, points.end(),
        [&](const Point A, const Point B) -> bool
         {
             return CCW(points[0], A, B) < 0;
         }
    );

    /// works as a stack
    vector<Point> hull(N);
    int dim = 0;

    for (int i = 0; i < N; ++i)
    {
        while (dim >= 2 && CCW(hull[dim - 2], hull[dim - 1], points[i]) >= 0) ///clockwise turn
            dim--;

        hull[dim++] = points[i];
    }

    hull.resize(dim);

    return hull;
}

int main()
{
    ifstream in("infasuratoare.in");
    ofstream out("infasuratoare.out");

    int N;
    in >> N;

    vector<Point> points(N);

    for (int i = 0; i < N; ++i)
        in >> points[i].x >> points[i].y;

    vector<Point> hull = convexHull(points);

    out << hull.size() << "\n";

    for (int i = 0; i < (int)hull.size(); ++i)
    {
        out << fixed << setprecision(10);
        out << hull[i].x << " " << hull[i].y << "\n";
    }

    return 0;
}
