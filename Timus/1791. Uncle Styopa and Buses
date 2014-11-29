#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

int t[2][Nmax], p[2][Nmax], f[2][Nmax];
int N, M;

void compute( int t[], int p[], int f[], int n )
{
    for ( int i = 1; i <= n; ++i )
        f[i] = t[i] + p[i] - 1;

    for ( int i = n - 1; i >= 1; i-- )
        f[i] = min( f[i + 1] - 1, f[i] );
}

void addQueue( queue<int>&Q, int &ind, int n, int timp, int t[] )
{
    while ( ind <= n && t[ind] <= timp )
    {
        Q.push( ind );
        ind++;
    }
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio( false );

    cin >> N;

    for ( int i = 1; i <= N; ++i )
        cin >> t[0][i] >> p[0][i];

    cin >> M;

    for ( int i = 1; i <= M; ++i )
        cin >> t[1][i] >> p[1][i];

    compute( t[0], p[0], f[0], N );
    compute( t[1], p[1], f[1], M );

    int i = 1, j = 1;
    queue <int> Q[2];
    int timp = 0;

    while ( i <= N || j <= M || Q[0].size() || Q[1].size() )
    {
        addQueue( Q[0], i, N, timp, t[0] );
        addQueue( Q[1], j, M, timp, t[1] );

        if ( Q[0].size() == 0 && Q[1].size() == 0 )
        {
            int aux = 1e9;

            if ( i <= N ) { aux = min( aux, t[0][i] ); }
            if ( j <= M ) { aux = min( aux, t[1][j] ); }

            timp = max( aux, timp );
            continue;
        }

        if ( Q[0].size() && Q[1].size() == 0 )
        {

            int x = Q[0].front();
            Q[0].pop();

            if ( timp > f[0][x] )
            {
                cout << "NO\n";
                return 0;
            }

            timp++;
            continue;
        }

        if ( Q[0].size() == 0 && Q[1].size() )
        {
            int x = Q[1].front();
            Q[1].pop();

            if ( timp > f[1][x] )
            {
                cout << "NO\n";
                return 0;
            }

            timp++;
            continue;
        }

        if ( Q[0].size() && Q[1].size() )
        {
            int x = Q[0].front(), y = Q[1].front();

            if ( timp > f[0][x] || timp > f[1][y] )
            {
                cout << "NO\n";
                return 0;
            }

            if ( timp == f[0][x] )
            {
                Q[0].pop();
            }
            else
            {
                Q[1].pop();
            }

            timp++;
            continue;
        }
    }

    cout << "YES\n";

    return 0;
}
