#include <bits/stdc++.h>

using namespace std;

unordered_map <int, int> UM;
int N, K;

int solve( int nr )
{
    if ( UM[nr] != 0 )
        return UM[nr];

    if ( nr == 0 )
        return UM[nr] = 2;

    int sol = 2;

    for ( int i = 2; i <= K && sol == 2; ++i )
    {
        if ( solve( nr / i ) == 2 )
            sol = 1;
    }

    return UM[nr] = sol;
}

int main()
{
    ifstream in("pp.in");
    ofstream out("pp.out");

    in >> N >> K;
    out << 2 - solve( N ) << "\n";

    return 0;
}
