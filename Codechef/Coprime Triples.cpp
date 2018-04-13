#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int Nmax = 1e5 + 2;
const int Vmax = 1e6 + 2;

int D[Vmax];
bool square_free[Vmax];
int sieve[Vmax];
int N;

int Mobius( int x )
{
    if ( square_free[x] )
        return 0;

    if ( sieve[x] % 2 == 0)
        return 1;
    else
        return -1;
}

long long C( long long n, long long k )
{
    if ( n < k )
        return 0;

    return n * ( n - 1 ) * ( n - 2 ) / 6LL;
}

int main()
{
    cin.sync_with_stdio( false );

    cin >> N;

    for ( int i = 1, A; i <= N; ++i )
    {
        cin >> A;

        for ( int j = 1; j * j <= A; ++j )
        {
            if ( A % j == 0 )
            {
                D[j]++;

                if ( A / j != j )
                    D[A / j]++;
            }
        }
    }

    for ( int i = 2; i * i < Vmax; ++i )
    {
        for ( int j = 1; j * i * i < Vmax; ++j )
            square_free[j * i * i] = 1;
    }

    for ( int i = 2; i < Vmax; ++i )
        if ( sieve[i] == 0 )
            for ( int j = i; j < Vmax; j += i )
                sieve[j]++;

    long long sol = 0;

    for ( int i = 1; i < Vmax; ++i )
        sol += 1LL * Mobius( i ) * C( D[i], 3 );

    cout << sol;

    return 0;
}
