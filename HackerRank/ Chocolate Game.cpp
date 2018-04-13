#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 2;

int d[Nmax];
map <int, int> Map;

int N;
long long ans;

void solve( int even = 0 )
{
    Map.clear();
    Map[0] = 1;

    int xorsum = 0;

    for ( int i = N - even; i >= 1; i -= 2 )
    {
        int aux = d[i];

        if ( i > 1 ) aux -= d[i - 1];

        ans += Map[xorsum ^ d[i]];

        if ( i > 1 ) ans += Map[xorsum ^ aux];

        xorsum ^= aux;
        Map[xorsum]++;
    }
}

int main()
{
    cin >> N;

    for ( int i = 1; i <= N; ++i )
        cin >> d[i];

    solve( 0 );
    solve( 1 );

    cout << 1LL * N * ( N - 1 ) / 2 - ans;

    return 0;
}
