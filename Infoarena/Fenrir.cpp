#include <bits/stdc++.h>

using namespace std;

vector < pair<int,int> > edges;

int main()
{
    ofstream out("fenrir.out");

    for ( int i = 1; i <= 9; ++i )
        for ( int j = 10; j <= 20; ++j )
            edges.push_back( pair<int,int>( i, j ) );

    out << edges.size() << "\n";

    for ( unsigned i = 0; i < edges.size(); ++i )
        out << edges[i].first << " " << edges[i].second << "\n";

    return 0;
}
