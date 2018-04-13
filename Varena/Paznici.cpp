#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000;
const int Cmax = 1000;

struct Paznic
{
    int x, y, c;

    bool operator < ( const Paznic& P ) const
    {
        if ( c != P.c )
            return c < P.c;
        else
            return x < P.x;
    }

    friend istream& operator >> ( istream& stream, Paznic& P )
    {
        stream >> P.x >> P.y >> P.c;
        return stream;
    }

} v[Nmax + 1];

int C[Nmax + 1];
int N, A, B;

int main()
{
    ifstream in("paznici.in");
    ofstream out("paznici.out");

    ios_base::sync_with_stdio( false );

    in >> A >> B;
    in >> N;

    for ( int i = 0; i < N; ++i )
        in >> v[i];

    sort( v, v + N );

    v[ N++ ].c = -1;

    Paznic actual = v[0];

    for ( int i = 1; i < N; ++i )
    {
        if ( v[i].c != actual.c )
        {
            C[ actual.c ] += actual.y - actual.x + 1;
            actual = v[i];
        }
        else
        {
            if ( actual.y >= v[i].x ) ///intersec
            {
                actual.y = max( actual.y, v[i].y );
            }
            else
            {
                C[ actual.c ] += actual.y - actual.x + 1;
                actual = v[i];
            }
        }
    }

    int maxim = 0, p = 0;

    for ( int i = 1; i <= Cmax; ++i )
        if ( C[i] > maxim )
        {
            maxim = C[i];
            p = i;
        }

    out << p << "\n";

    return 0;
}
