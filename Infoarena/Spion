#include <bits/stdc++.h>

using namespace std;

const int MOD = 100003;

int pw( int a, int p = MOD - 2 )
{
    int res = 1;

    for ( int i = 0; ( 1 << i ) <= p; ++i )
    {
        if ( p & ( 1 << i ) )
            res = ( 1LL * res * a ) % MOD;

        a = ( 1LL * a * a ) % MOD;
    }

    return res;
}

int fact( int n )
{
    int res = 1;

    for ( int i = 1; i <= n; ++i )
        res = ( 1LL * res * i ) % MOD;

    return res;
}

int p;
string path;

int main()
{
    ifstream in("spion.in");
    ofstream out("spion.out");

    in >> p >> path;

    if ( p == 1 )
    {
        out << count( path.begin(), path.end(), 'E' ) + 1 << "\n";
    }
    else
    {
        int k = count( path.begin(), path.end(), 'V' );
        int n = path.size();

        out << ( ( 1LL * fact( n ) * pw( fact( k ) ) ) % MOD ) * pw( fact( n - k ) ) % MOD << "\n";
    }

    return 0;
}
