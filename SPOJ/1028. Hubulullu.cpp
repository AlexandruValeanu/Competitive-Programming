#include <bits/stdc++.h>

using namespace std;

int dp[100];
int n;

int min_max( vector<int> &v )
{
    int c = 0;

    for ( int i = 1; i <= n; ++i )
        c += v[i];

    if ( c == n )
        return 0;

    int sol = 0;

    for ( int i = 1; i <= n; ++i )
    {
        if ( v[i] != 1 )
        {
            vector <int> a = v;

            for ( int j = 1; j <= i; ++j )
            {
                if ( i % j == 0 )
                    a[j] = 1;
            }

            if ( min_max( a ) == 0 )
            {
                sol = 1;
                break;
            }
        }
    }

    return sol;
}

int main()
{
    int T, N, cine;

    cin >> T;

    while ( T-- )
    {
        cin >> N >> cine;

        if ( cine == 0 )
            cout << "Airborne wins.\n";
        else
            cout << "Pagfloyd wins.\n";
    }

    return 0;
}
