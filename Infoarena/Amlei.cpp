#include <bits/stdc++.h>

using namespace std;

const int Nmax = 5e2 + 2;

int a[10];
int N, T, U;

int main()
{
    ifstream in("amlei.in");
    ofstream out("amlei.out");

    in.sync_with_stdio( false );

    while ( in >> N >> T >> U )
    {
        vector < vector<int> > V[2];

        a[0] = T;
        a[1] = U;

        for ( int k = 0; k < 2; ++k )
        {
            for ( int i = 0; i < a[k]; ++i )
            {
                vector <int> v;

                for ( int j = 0, x; j < N; ++j )
                {
                    in >> x;
                    v.push_back( x );
                }

                sort( v.begin(), v.end() );
                V[k].push_back( v );
            }

        sort( V[k].begin(), V[k].end() );
        V[k].erase( unique( V[k].begin(), V[k].end() ), V[k].end() );
    }

        if ( V[0] == V[1] )
            out << "DA\n";
        else
            out << "NU\n";
    }

    return 0;
}
