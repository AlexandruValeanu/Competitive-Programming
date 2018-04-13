#include <bits/stdc++.h>
 
using namespace std;
 
list <int> L[3];
int N, K;
 
int main()
{
    ifstream in("grid.in");
    ofstream out("grid.out");
 
    in >> N >> K;
 
    for ( int i = 1, id = 0; i <= 3 * N; ++i )
    {
        L[id].push_back( i );
 
        if ( i % N == 0 )
            id++;
    }
 
    while ( K-- )
    {
        int a, b, c, d;
 
        in >> a >> b >> c >> d;
 
        list<int>::iterator it1 = L[a].begin();
        advance( it1, b );
 
        int value = *it1;
        L[a].erase( it1 );
 
        list<int>::iterator it2 = L[c].begin();
        advance( it2, d );
 
        L[c].insert( it2, value );
    }
 
    for ( int i = 0; i < 3; ++i )
    {
        for ( list<int>::iterator x = L[i].begin(); x != L[i].end(); ++x )
            out << *x << " ";
 
        out << "\n";
    }
 
    return 0;
}
