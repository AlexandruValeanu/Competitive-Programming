#include <bits/stdc++.h>

using namespace std;

int main()
{
    ///ifstream cin("data.in");

    int T, N;

    cin >> T;

    while ( T-- )
    {
        vector <int> v;
        map < int, multiset<int> > MapSet;

        cin >> N;

        for ( int i = 0, a; i < N; ++i )
        {
            cin >> a;
            v.push_back( a );
        }

        sort( v.begin(), v.end() );

        for ( int i = 0; i < N; ++i )
        {
            if ( MapSet.count( v[i] - 1 ) )
            {
                int dim = *MapSet[ v[i] - 1 ].begin();
                MapSet[ v[i] - 1 ].erase( MapSet[ v[i] - 1 ].begin() );
                MapSet[ v[i] ].insert( dim + 1 );

                if ( MapSet[ v[i] - 1 ].empty() )
                    MapSet.erase( v[i] - 1 );
            }
            else
            {
                MapSet[ v[i] ].insert( 1 );
            }
        }

        if ( MapSet.size() == 0 )
        {
            cout << "0\n";
            continue;
        }

        int sol = 1e9;

        for ( auto x: MapSet )
            if ( x.second.size() )
                sol = min( sol, *x.second.begin() );

        cout << sol << "\n";
    }

    return 0;
}
