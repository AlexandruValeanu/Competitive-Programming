#include <bits/stdc++.h>

using namespace std;

#define dataType long long

#define Point pair<dataType,dataType>
#define x first
#define y second

const int Nmax = 100000 + 1;

/**
    < 0 for counter-clockwise (trigonometric)
    = 0 for collinear
    > 0 for clockwise (anti-trigonometric)
**/
dataType CCW(Point A, Point B, Point C)
{
    return (C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x);
}

dataType dist(Point A, Point B)
{
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

dataType area(Point A, Point B, Point C)
{
    return abs(CCW(A, B, C));
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

dataType diameter(vector<Point>& points) ///points is a convex polygon
{
    int N = points.size();

    /// basic cases
    if (N == 1)
        return 0;
    else if (N == 2)
        return dist(points[0], points[1]);

    int q = 1;
    /// find the farthest point(q) from line Pn-1,P0
    while (area(points[N - 1], points[0], points[(q + 1) % N]) > area(points[N - 1], points[0], points[q]))
        q = (q + 1) % N;

    /// compute the distance from q to both ends of line Pn-1,P0
    dataType best = max(dist(points[N - 1], points[q]), dist(points[0], points[q]));

    for (int i = 0; i < N; ++i)
    {
        /// find the farthest point(q) from line Pi,P(i+1)%n
        while (area(points[i], points[(i + 1) % N], points[(q + 1) % N]) > area(points[i], points[(i + 1) % N], points[q]))
            q = (q + 1) % N;

        /// compute the distance from q to both ends of line Pi,P(i+1)%n
        best = max(best, dist(points[i], points[q]));
        best = max(best, dist(points[(i + 1) % N], points[q]));
    }

    return best;
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    int T, N;
    cin >> T;

    while (T--)
    {
        cin >> N;
        vector<Point> points(N);

        for (int i = 0; i < N; ++i)
            cin >> points[i].x >> points[i].y;

        vector<Point> hull = convexHull(points);
        cout << diameter(hull) << "\n";
    }

    return 0;
}
