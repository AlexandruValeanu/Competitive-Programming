#include <bits/stdc++.h>

using namespace std;

vector<int> Z_Algorithm( const string &str )
{
    int L = 0, R = 0;
    int lg = str.size();

    vector <int> Z( lg, 0 );

    for ( int i = 1; i < lg; ++i )
    {
        if ( i <= R )
            Z[i] = min( R - i + 1, Z[i - L] );

        while ( i + Z[i] < lg && str[ Z[i] ] == str[ i + Z[i] ] ) Z[i]++;

        if ( i + Z[i] - 1 > R )
        {
            L = i;
            R = i + Z[i] - 1;
        }
    }

    return Z;
}

int main()
{
    return 0;
}
