#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000000 + 1;

int N, S;
int V[Nmax];

int main()
{
    freopen("noname3.in", "r", stdin);
    freopen("noname3.out", "w", stdout);

    cin >> N >> S;

    if ( 2 * S - N * ( N - 1 ) <= 2 * N - 2 )
    {
        cout << "-1\n";
        return 0;
    }

    for ( int i = 1; i < N; ++i )
        V[i] = i;

    V[N] = S - N * ( N - 1 ) / 2;

    int k = ( V[N] - V[N - 1] ) / N;

    if ( ( V[N] - V[N - 1] ) % N == 0 )
        k--;

    for ( int i = 1; i < N; ++i )
        V[i] += k;

    V[N] -= ( N - 1 ) * k;


    for ( int i = N - 1; i >= 1; i-- )
    {
        V[N]--;
        V[i]++;

        if ( !( V[N] > V[N - 1] && V[i] < V[i + 1] ) )
        {
            V[N]++;
            V[i]--;
            break;
        }
    }

    for ( int i = 1; i <= N; ++i )
        cout << V[i] << " ";

    return 0;
}
