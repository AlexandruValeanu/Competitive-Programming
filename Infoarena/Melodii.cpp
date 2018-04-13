#include <bits/stdc++.h>

using namespace std;

const int Rmax = 1e5 + 2;

int period[4 * Rmax];

int main()
{
    ifstream in("melodii.in");
    ofstream out("melodii.out");

    int T, R, p = 0;

    in >> T >> R;

    period[ ++p ] = 1;
    period[ ++p ] = 1;

    while ( 1 )
    {
        p++;
        period[p] = ( period[p - 1] + period[p - 2] ) % R;

        if ( period[p] == 1 && period[p - 1] == 1 ) break;
    }

    p -= 2;

    while ( T-- )
    {
        long long n;
        in >> n;
        n %= p;
        out << period[n + 1] << "\n";
    }

    return 0;
}
