#include <bits/stdc++.h>

using namespace std;

class Point
{
public:

    long long x, y;

    Point() : x(0), y(0) {}

    Point(const long long _x, const long long _y) : x(_x), y(_y) {}

    bool operator < ( const Point &P ) const
    {
        if ( y != P.y )
            return y < P.y;
        else
            return x < P.x;
    }

    long long distanceToPoint( const Point &P ) const
    {
        return ( x - P.x ) * ( x - P.x ) + ( y - P.y ) * ( y - P.y );
    }

    friend istream& operator >> ( istream &stream, Point &P )
    {
        stream >> P.x >> P.y;
        return stream;
    }

    friend ostream& operator << ( ostream &stream, const Point &P )
    {
        stream << P.x << " " << P.y;
        return stream;
    }
};

const int Nmax = 100000;
const int Hmax = 1000;

Point Polygon[Nmax];
Point stiva[2 * Hmax];
int N, top;

long long CCW( const Point &A, const Point &B, const Point &C )
{
    return ( B.x - A.x ) * ( C.y - A.y ) -
           ( B.y - A.y ) * ( C.x - A.x );
}

int Comp( const Point &A, const Point &B )
{
    long long ccw = CCW( Polygon[0], A, B );

    if ( ccw == 0 )
        return Polygon[0].distanceToPoint( A ) < Polygon[0].distanceToPoint( B );
    else
        return ccw < 0;
}

void SortPoints()
{
    int pos = 0;

    for ( int i = 1; i < N; ++i )
        if ( Polygon[i] < Polygon[pos] )
            pos = i;

    swap( Polygon[pos], Polygon[0] );

    sort( Polygon + 1, Polygon + N, Comp );
}

void GrahamScan()
{
    top = -1;

    stiva[ ++top ] = Polygon[0];
    stiva[ ++top ] = Polygon[1];

    for ( int i = 2; i < N; ++i )
    {
        while ( top >= 1 && CCW( stiva[top - 1], stiva[top], Polygon[i] ) >= 0 )
            top--;

        stiva[ ++top ] = Polygon[i];
    }
}

void PrintConvexHull()
{
    int pos = 0;

    for ( int i = 1; i <= top; ++i )
        if ( stiva[i] < stiva[pos] )
            pos = i;

    int cate = top + 1;
    int ind = pos;
    int dim = top + 1;

    ofstream out("infasuratoare.out");

    out << dim << "\n";

    while ( cate-- )
    {
        out << stiva[ind] << "\n";
        ind = ( ind - 1 + dim ) % dim;
    }
}

int main()
{
    ifstream in("infasuratoare.in");

    in >> N;

    for ( int i = 0; i < N; ++i )
        in >> Polygon[i];

    SortPoints();
    GrahamScan();
    PrintConvexHull();

    return 0;
}
