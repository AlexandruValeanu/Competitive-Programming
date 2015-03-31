#include <bits/stdc++.h>

using namespace std;

#define dataType long long

#define Point pair<dataType,dataType>
#define x first
#define y second

const int Nmax = 100000;

dataType dist(Point A, Point B)
{
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

/// comp function use for merge
bool comp(Point A, Point B)
{
    return A.y < B.y;
}

dataType solve(int st, int dr, vector<Point>& points)
{
    /// basic cases
    if (st >= dr)
        return numeric_limits<dataType>::max();
    else if (st + 1 == dr)
    {
        /// sort points after y
        if (points[st].y > points[dr].y)
            swap(points[st], points[dr]);

        return dist(points[st], points[dr]);
    }

    int m = (st + dr) / 2;
    dataType medianX = points[m].x; /// median of X[st...dr]
    dataType d1 = solve(st, m, points); /// solve for [st...m]
    dataType d2 = solve(m + 1, dr, points); /// solve for [m + 1...dr]
    dataType  d = min(d1, d2); /// combine solutions

    /// auxiliar used for merging the two sides (!It is allocated once only!)
    static vector<Point> auxiliar(points.size());

    /// actual merge operation
    int i = st, j = m + 1, k = st;

    while (i <= m && j <= dr)
    {
        if (points[i].y <= points[j].y)
            auxiliar[k++] = points[i++];
        else
            auxiliar[k++] = points[j++];
    }

    while (i <= m)  auxiliar[k++] = points[i++];
    while (j <= dr) auxiliar[k++] = points[j++];

    for (int i = st; i <= dr; ++i)
        points[i] = auxiliar[i];

    int dim = 0;

    /// find "special" points (points at dist<=d from median)
    for (int i = st; i <= dr; ++i)
        if (abs(points[i].x - medianX) <= d)
            auxiliar[dim++] = points[i];

    for (int i = 0; i < dim; ++i)
    {
        int cnt = 8; /// number of "interesting" points for points[i]
        int j = i - 1;

        while (j >= 0 && cnt > 0)
        {
            d = min(d, dist(auxiliar[i], auxiliar[j]));
            j--;
            cnt--;
        }
    }

    return d;
}

double closestPair(vector<Point>& points)
{
    /// sort points after x (and after y)
    sort(points.begin(), points.end());
    return sqrt(solve(0, points.size() - 1, points));
}

int main()
{
    //ifstream cin("data.in");
    //ofstream out("cmap.out");

    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Point> points(N);

    for (int i = 0; i < N; ++i)
        cin >> points[i].x >> points[i].y;

    cout << fixed << setprecision(6);
    cout << closestPair(points) << "\n";

    return 0;
}
