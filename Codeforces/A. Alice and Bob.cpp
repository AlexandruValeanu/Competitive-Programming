#include <bits/stdc++.h>

using namespace std;

int N, maxim, a, x;

int main()
{
    cin >> N;

    for ( int k = 1; k <= N; ++k )
    {
        cin >> a;
        x = __gcd( x, a );
        maxim = max( maxim, a );
    }

    int nrMoves = maxim / x - N;

    if ( nrMoves % 2 )
        cout << "Alice";
    else
        cout << "Bob";

    return 0;
}
