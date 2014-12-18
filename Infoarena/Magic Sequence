#include <bits/stdc++.h>
 
using namespace std;
 
const int Nmax = 20000;
 
int v[Nmax];
int T, N;
 
int main()
{
    ifstream in("magicsequence.in");
    ofstream out("magicsequence.out");
 
    in >> T;
 
    while ( T-- )
    {
        in >> N;
 
        for ( int i = 0; i < N; ++i )
            in >> v[i];
 
        if ( v[0] <= v[N - 1] )
            out << "YES\n";
        else
            out << "NO\n";
    }
 
    return 0;
}
