#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1001000 + 1;

int A[Nmax];
int MaxSecv[Nmax];
int MinSecv[Nmax];
int N;

int main()
{
    ifstream in("2sec.in");
    ofstream out("2sec.out");

    in >> N;

    for ( int i = 1; i <= N; ++i )
        in >> A[i];

    for ( int i = 1; i <= N; ++i )
        MinSecv[i] = min( MinSecv[i - 1], 0 ) + A[i];

    for ( int i = N; i >= 1; i-- )
        MaxSecv[i] = max( MaxSecv[i + 1], 0 ) + A[i];

    int sol = -1e9;

    for ( int i = 1; i <= N; ++i )
        sol = max( sol, MaxSecv[i + 1] - MinSecv[i] );

    out << sol << "\n";

    return 0;
}
