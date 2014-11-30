#include <bits/stdc++.h>

using namespace std;

const int Nmax = 500;
const double EPS = 1e-8;
const int NUMBER_TRY_POINTS = 3;

class Point
{
public:

    double x, y;

    Point() : x(0), y(0) {}

    Point(const double _x, const double _y) :
        x(_x), y(_y) {}

    double distanceToPoint(const Point &P) const
    {
        return sqrt( ( x - P.x ) * ( x - P.x ) + ( y - P.y ) * ( y - P.y ) );
    }

    friend istream& operator >> (istream &stream, Point &P)
    {
        stream >> P.x >> P.y;
        return stream;
    }

    friend ostream& operator << (ostream &stream, const Point &P)
    {
        stream << P.x << " " << P.y;
        return stream;
    }
};

class Segment
{
public:

    Point A, B;

    Segment(const Point &X, const Point &Y) : A(X), B(Y) {}

    bool contains(const Point &P) const
    {
        return abs( A.distanceToPoint( B ) - A.distanceToPoint( P ) - B.distanceToPoint( P ) ) < EPS;
    }

    friend istream& operator >> (istream &stream, Segment &S)
    {
        stream >> S.A >> S.B;
        return stream;
    }

    friend ostream& operator << (ostream &stream, const Segment &S)
    {
        stream << S.A << " " << S.B;
        return stream;
    }
};

int sign(double a)
{
    if ( a > EPS )
        return +1;

    if ( a < -EPS )
        return -1;

    return 0;
}

int CCW(const Point &A, const Point &B, const Point &C)
{
    return sign( (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y) );
}

bool SegmentIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    Segment S1(A,B);
    Segment S2(C,D);

    if ( S1.contains(C) || S1.contains(D) || S2.contains(A) || S2.contains(B) )
        return true;

    if ( CCW(A,C,D) == CCW(B,C,D) || CCW(A,B,C) == CCW(A,B,D) )
        return false;

    return true;
}

bool belongsOnEdge(Point Polygon[], const int &N, const Point &P)
{
    for ( int i = 0; i < N; ++i )
        if ( Segment(Polygon[i], Polygon[i + 1]).contains(P) )
            return true;

    return false;
}

string solve(Point Polygon[], const int &N, const Point &P, const Point &EXT)
{
    if ( belongsOnEdge(Polygon, N, P) )
        return "BOUNDARY";

    int contor = 0;

    for ( int i = 0; i < N; ++i )
    {
        if ( SegmentIntersection(Polygon[i], Polygon[i + 1], P, EXT) )
            contor++;
    }

    if ( contor % 2 == 1 )
        return "INTERIOR";
    else
        return "EXTERIOR";
}

Point genExteriorPoint(const double maxX, const double maxY)
{
    int r1 = rand() % 1000 + 10.0;
    int r2 = rand() % 1000 + 10.0;

    return Point(maxX + r1, maxY + r2);
}

string query(Point Polygon[], const int &N, const Point &testPoint, const double maxX, const double maxY)
{
    int valid = 0;

    for ( int i = 0; i < NUMBER_TRY_POINTS && !valid; ++i )
    {
        Point ExtPoint = genExteriorPoint(maxX, maxY);

        if ( solve(Polygon, N, testPoint, ExtPoint) != "EXTERIOR" )
            valid = 1;
    }

    if ( valid )
        return "DA";
    else
        return "NU";
}

Point Polygon[Nmax + 1];
int N, K;

int main()
{
    ifstream in("poligon.in");
    ofstream out("poligon.out");

    srand( time(NULL) );

    in >> N >> K;

    for ( int i = 0; i < N; ++i )
        in >> Polygon[i];

    Polygon[N] = Polygon[0];

    double maxX = 0, maxY = 0;

    for ( int i = 0; i < N; ++i )
    {
        maxX = max( maxX, Polygon[i].x );
        maxY = max( maxY, Polygon[i].y );
    }

    Point testPoint;

    while ( K-- )
    {
        in >> testPoint;
        out << query(Polygon, N, testPoint, maxX, maxY) << "\n";
    }

    return 0;
}
