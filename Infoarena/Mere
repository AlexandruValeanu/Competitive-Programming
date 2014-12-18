#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ifstream in("mere.in");
    ofstream out("mere.out");
 
    int T, N, K;
 
    in >> T;
 
    while ( T-- )
    {
        in >> N >> K;
 
        if ( N < K )
        {
            out << "Remiza\n";
            continue;
        }
 
        if ( ( N / K ) & 1 || ( N % K ) )
            out << "Santa Klaus\n";
        else
            out << "Remiza\n";
    }
 
    return 0;
}
