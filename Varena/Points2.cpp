#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int Nmax = 36;

i64 sume[1 << (Nmax / 2)];
i64 v[Nmax];

i64 S;
int N;

int main()
{
    ifstream in("points2.in");
    ofstream out("points2.out");

    in >> N >> S;

    for ( int i = 0; i < N; ++i )
        in >> v[i];

    int n = N / 2;
    int ind = 0;

    for ( int i = 0; i < ( 1 << n ); ++i )
    {
        i64 suma = 0;

        for ( int j = 0; j < n; ++j )
            if ( i & ( 1 << j ) )
                suma += v[j];

        sume[ ind++ ] = suma;
    }

    sort( sume, sume + ind );

    int prev = n;
    n = N - n;

    i64 sol = 0;

    for ( int i = 0; i < ( 1 << n ); ++i )
    {
        i64 suma = 0;

        for ( int j = 0; j < n; ++j )
            if ( i & ( 1 << j ) )
                suma += v[prev + j];

        int p = lower_bound( sume, sume + ind, S - suma ) - sume;

        if ( p != -1 )
            sol += ind - p;
    }

    out << sol << "\n";

    return 0;
}
