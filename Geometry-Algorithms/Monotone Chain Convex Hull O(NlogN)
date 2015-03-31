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
double CCW(Point A, Point B, Point P)
{
    return (P.x - A.x) * (B.y - A.y) - (P.y - A.y) * (B.x - A.x);
}

/// Points in the result will be listed in counter-clockwise order.
vector<Point> convexHull(vector<Point> &points)
{
    /// basic case
    if (points.size() <= 3)
        return points;

    /// sort points after x (and after y in case of equality)
    sort(points.begin(), points.end());

    vector<Point> U, L; /// upper and lower hulls

    for (int i = 0; i < (int)points.size(); ++i)
    {
        while (U.size() >= 2 && CCW(U[U.size() - 2], U[U.size() - 1], points[i]) >= 0) ///clockwise turn
            U.pop_back();

        U.push_back(points[i]);
    }

    for (int i = (int)points.size() - 1; i >= 0; --i)
    {
        while (L.size() >= 2 && CCW(L[L.size() - 2], L[L.size() - 1], points[i]) >= 0) ///clockwise turn
            L.pop_back();

        L.push_back(points[i]);
    }

    /// Remove the last point of each list (it's the same as the first point of the other list).
    U.pop_back();
    L.pop_back();

    /// convex Hull = U + L
    for (int i = 0; i < (int)L.size(); ++i)
        U.push_back(L[i]);

    return U;
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
