#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2e5 + 1;

int aib[Nmax];
int N;

inline int lsb( int x )
{
    return x & -x;
}

void update( int pos, int val )
{
    for ( int i = pos; i <= N; i += lsb( i ) )
        aib[i] += val;
}

int query( int pos )
{
    int s = 0;

    for ( int i = pos; i >= 1; i -= lsb( i ) )
        s += aib[i];

    return s;
}

int query( int x, int y )
{
    return query( y ) - query( x - 1 );
}

int cauta( int k )
{
    int init = k, pos = 0;

    for ( int step = ( 1 << 18 ); step; step >>= 1 )
    {
        if ( pos + step <= N && aib[pos + step] < k )
        {
            k -= aib[pos + step];
            pos += step;
        }
    }

    if ( query( pos + 1 ) == init )
        return pos + 1;
    else
        return -1;
}


int main()
{
    ifstream in("costume.in");
    ofstream out("costume.out");

    in >> N;

    for ( int i = 1, a; i <= N; ++i )
    {
        in >> a;
        update( a, 1 );
        out << cauta( ( i + 1 ) / 2 ) << " ";
    }

    return 0;
}
