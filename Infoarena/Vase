#include <iostream>
#include <fstream>

using namespace std;

const int Nmax = 100000 + 1;

int st[Nmax];
int dr[Nmax];
long long v[Nmax];
int vis[Nmax];
int N;
long long S;

void solve( int a[], int ap, long long &x, long long &y )
{
    long long capat = S / 2;

    for ( int i = a[0]; i >= 1; i-- )
    {
        if ( a[i] == ap )
        {
            x = capat;
            y = capat - v[ a[i] ];
        }

        capat -= v[ a[i] ];
    }
}

int main()
{
    ifstream in("vase.in");
    ofstream out("vase.out");

    ios_base::sync_with_stdio( false );

    in >> N;

    for ( int i = 1; i <= N; ++i )
    {
        char id;

        in >> v[i] >> id;

        S += v[i];

        if ( id == 'S' )
        {
            st[ ++st[0] ] = i;
            vis[i] = 0;
        }
        else
        {
            dr[ ++dr[0] ] = i;
            vis[i] = 1;
        }
    }

    out << S / 2 << "\n";

    int ap;
    long long x, y;

    in >> ap;

    if ( vis[ap] == 0 ) /// ramura st
        solve( st, ap, x, y );
    else
        solve( dr, ap, x, y );

    if ( x == 0 || y == 0 ) /// este pe o ramura cu un capat in origine
    {
        long long sum = x + y;

        if ( sum < 0 )
            vis[ap] ^= 1;

        sum = abs( sum );

        if ( vis[ap] == 0 ) /// ramura st
        {
            out << sum << " S\n";
            out << "0 S\n";
        }
        else
        {
            out << sum << " D\n";
            out << "0 D\n";
        }

        return 0;
    }

    if ( x < 0 && y < 0 )
    {
        x = abs( x );
        y = abs( y );

        vis[ap] ^= 1;
    }

    if ( x > 0 && y > 0 ) /// este pe o ramura
    {
        if ( vis[ap] == 0 )
        {
            out << max( x, y ) << " S\n";
            out << min( x, y ) << " S\n";
        }
        else
        {
            out << max( x, y ) << " D\n";
            out << min( x, y ) << " D\n";
        }

        return 0;
    }

    /// este pe cele 2 ramuri

    if ( vis[ap] == 0 )
    {
        out << abs( max( x, y ) ) << " S\n";
        out << abs( min( x, y ) ) << " D\n";
    }
    else
    {
        out << abs( min( x, y ) ) << " S\n";
        out << abs( max( x, y ) ) << " D\n";
    }

    return 0;
}
