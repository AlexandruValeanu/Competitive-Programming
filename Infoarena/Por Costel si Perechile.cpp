#include <bits/stdc++.h>

using namespace std;

long long solve(int N)
{
    if ( N == 1 )
        return 1;

    long long sum = 0;

    for ( int i = 1; i * i <= N; ++i )
        sum += N / i;

    int x = 1;

    while ( x * x <= N ) x++;
    x--;

    return 2LL * sum - x * x;
}

int main()
{
    ifstream in("perechi3.in");
    ofstream out("perechi3.out");

    ios_base::sync_with_stdio(false);

    int T, N;

    in >> T;

    while (T--)
    {
        in >> N;
        out << solve(N) << "\n";
    }

    return 0;
}
