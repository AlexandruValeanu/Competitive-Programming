#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

long long v[Nmax];
int N;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N;

    for ( int i = 1; i <= N; ++i )
        cin >> v[i];

    sort(v + 1, v + N + 1, greater<int>());

    int i = 1, j = 63;

    while (i <= N && j >= 0)
    {
        int x = 0;

        for ( int k = i; k <= N; ++k )
            if ( v[k] & (1LL << j) )
            {
                x = k;
                break;
            }

        if ( !x )
        {
            j--;
            continue;
        }

        swap(v[i], v[x]);

        for ( int k = 1; k <= N; ++k )
            if ( k != i && v[k] & (1LL << j) )
                v[k] ^= v[i];

        i++; j--;
    }

    long long sol = 0;

    for ( int i = 1; i <= N; ++i )
        sol ^= v[i];

    cout << sol << "\n";

    return 0;
}
