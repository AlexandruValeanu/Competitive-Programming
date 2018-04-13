#include <bits/stdc++.h>

using namespace std;

const int Pmax = 2 * 300000 + 1;

int P;
int value[Pmax];
int ind[Pmax];

int main()
{
    ifstream in("congr.in");
    ofstream out("congr.out");

    ios_base::sync_with_stdio(false);

    in >> P;

    long long sum = 0;

    for ( int i = 1; i <= 2 * P - 1; ++i )
    {
        in >> value[i];
        ind[i] = i;

        if ( i <= P )
            sum += value[i];
    }

    srand((time(0)));

    while ( sum % P != 0 )
    {
        int x = 1 + rand() % P;
        int y = P + 1 + rand() % (P - 2);

        sum -= value[ ind[x] ];
        sum += value[ ind[y] ];

        ///swap( value[ ind[x] ], value[ ind[y] ] );
        swap( ind[x], ind[y] );
    }

    for ( int i = 1; i <= P; ++i )
        out << ind[i] << " ";

    return 0;
}
