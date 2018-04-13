#include <bits/stdc++.h>
 
using namespace std;
 
const int Nmax = 100 + 1;
 
int A[Nmax][Nmax];
int N;
 
int main()
{
    ifstream in("joc5.in");
    ofstream out("joc5.out");
 
    in >> N;
 
    do
    {
        for ( int i = 1; i <= N; ++i )
            for ( int j = 1; j <= N; ++j )
                in >> A[i][j];
 
        int xorsum = 0;
 
        for ( int i = 1; i <= N; ++i )
            xorsum ^= A[i][i];
 
        if ( xorsum )
            out << "1\n";
        else
            out << "2\n";
 
        in >> N;
 
    } while ( N );
 
    return 0;
}
