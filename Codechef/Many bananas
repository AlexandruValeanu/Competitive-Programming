#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5;

int N, M, A, B, X, Y;

long long bit[Nmax + 1];
int d[Nmax + 1];
long long suma;

int lsb( int x )
{
    return x & ( -x );
}

void update( int p, long long v )
{
    for ( int i = p; i <= Nmax; i += lsb( i ) )
        bit[i] += v;
}

long long query( int p )
{
    long long s = 0;

    for ( int i = p; i >= 1; i -= lsb( i ) )
        s += bit[i];

    return s;
}

long long query( int i, int j )
{
    return query( j ) - query( i - 1 );
}

int main()
{
   /// ifstream cin("data.in");

    ios_base::sync_with_stdio( false );

    cin >> N;

    for ( int i = 1; i <= N; ++i )
    {
        cin >> A >> B;

        update( A, 1LL * A * B );
        suma += B;
    }

    cin >> M;

    while ( M-- )
    {
        char tip;

        cin >> tip;

        if ( tip == '+' )
        {
            cin >> X;
            update( X, X );
            suma++;
        }

        if ( tip == '-' )
        {
            cin >> X;
            update( X, -X );
            suma--;
        }

        if ( tip == '?' )
        {
            cin >> Y;

            long long sol = suma * Y;
            int n = 0;

            for ( int j = 1; j * j <= Y; ++j )
            {
                d[ ++n ] = j;

                if ( Y / j != j )
                    d[ ++n ] = Y / j;
            }

            for ( int j = 1; j <= n; ++j )
            {
                int L = Y / ( d[j] + 1 ) + 1;
                int R = Y / d[j];

                sol -= 1LL * query( L, R ) * d[j];
            }

            cout << sol << "\n";
        }
    }

    return 0;
}
