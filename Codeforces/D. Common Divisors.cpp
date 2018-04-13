#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int Lmax = 1e5 + 2;

char A[Lmax];
char B[Lmax];

int N, M;

int isValidPeriod( char A[], int lgA, int dimP )
{
    for ( int i = 1; i <= lgA - dimP; ++i )
    {
        if ( A[i] != A[i + dimP] )
                return 0;
    }

    return 1;
}

int findPeriod( char A[], int lgA )
{
    int sol = lgA;

    for ( int i = 1; i * i <= lgA; ++i )
    {
        if ( lgA % i == 0 )
        {
            if ( isValidPeriod( A, lgA, i ) )
                sol = min( sol, i );

            if ( isValidPeriod( A, lgA, lgA / i ) )
                sol = min( sol, lgA / i );
        }
    }

    return sol;
}

int equalP( int p1, int p2 )
{
    if ( p1 != p2 )
            return 0;

    for ( int i = 1; i <= p1; ++i )
    {
        if ( A[i] != B[i] )
                return 0;
    }

    return 1;
}

int main()
{
    ///ifstream cin("data.in");

    cin.sync_with_stdio( false );

    cin >> ( A + 1 );
    cin >> ( B + 1 );

    N = strlen( A + 1 );
    M = strlen( B + 1 );

    int p1 = findPeriod( A, N );
    int p2 = findPeriod( B, M );

    if ( equalP( p1, p2 ) == 0 )
    {
        cout << "0\n";
    }
    else
    {
        int sol = 0;

        for ( int i = 1; i * p1 <= N; ++i )
        {
            if ( ( N % ( i * p1 ) == 0 ) && ( M % ( i * p1 ) == 0 ) )
                sol++;
        }

        cout << sol << "\n";
    }

    return 0;
}
