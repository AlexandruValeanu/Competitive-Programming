#include <bits/stdc++.h>

using namespace std;

struct Point
{
    double x;
    double y;

    explicit Point() : x(0), y(0) {
    }

    Point(const double a, const double b) : x(a), y(b) {
    }

    Point operator + (const Point& P) const
    {
        return Point(this->x + P.x, this->y + P.y);
    }

    bool operator += (const Point& P)
    {
        *this = *this + P;
        return true;
    }

    Point operator - (const Point& P) const
    {
        return Point(this->x - P.x, this->y - P.y);
    }

    bool operator -= (const Point& P)
    {
        *this = *this- P;
        return true;
    }

    Point operator * (const double delta) const
    {
        return Point(this->x * delta, this->y * delta);
    }

    bool operator *= (const double delta)
    {
        *this = *this * delta;
        return true;
    }

    void rotateWithAngle(const double &alpha) /// in radians
    {
        double x = this->x;
        double y = this->y;

        double CosA = cos(alpha);
        double SinA = sin(alpha);

        this->x = CosA * x - SinA * y;
        this->y = SinA * x + CosA * y;
    }


    double manhattanDistance(const Point& P) const
    {
        return abs(this->x - P.x) + abs(this->y - P.y);
    }

    double euclidDistance(const Point& P) const
    {
        return sqrt((this->x - P.x) * (this->x - P.x) + (this->y - P.y) * (this->y - P.y));
    }


    friend istream& operator >> (istream& stream, Point& P)
    {
        stream >> P.x;
        stream >> P.y;

        return stream;
    }

    friend ostream& operator << (ostream& stream, const Point& P)
    {
        stream << P.x << " " << P.y;

        return stream;
    }
};

int main()
{
    return 0;
}
