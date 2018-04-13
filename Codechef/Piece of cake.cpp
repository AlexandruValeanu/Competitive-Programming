#include <bits/stdc++.h>

using namespace std;

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio( false );

    int T;

    cin >> T;

    while ( T-- )
    {
        string a;

        cin >> a;

        vector<int> v( 100, 0 );

        for ( char x: a )
            v[x - 'a']++;

        int valid = 0;
        int sum = a.size();

        for ( int i = 0; i < 30; ++i )
        {
            if ( v[i] != 0 )
            {
                if ( v[i] == sum - v[i] )
                    valid = 1;
            }
        }

        if ( valid )
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
