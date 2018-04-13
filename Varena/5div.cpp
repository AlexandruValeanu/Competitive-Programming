#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int Nmax = 2000000;

ull a[Nmax / 64 + 1];
ull b[Nmax / 64 + 1];

inline bool bit( const int n, const int k )
{
    return n & ( 1ULL << k );
}

inline void change( ull bits[], const int i, const int x )
{
    ull mask = ~( 1ULL << ( i & 63 ) );
    bits[i >> 6] = ( bits[i >> 6] & mask ) ^ ( (ull)x << ( i & 63 ) );
}

inline void toggle( ull bits[], const int i )
{
    bits[i >> 6] ^= ( 1ULL << ( i & 63 ) );
}

inline int get( ull bits[], const int i )
{
    return ( bits[i >> 6] >> ( i & 63 ) ) & 1;
}

inline int getTwoBits( const int n )
{
    return ( get( a, n ) << 1 ) | get( b, n );
}

inline void addDivisor( const int n )
{
    int c = getTwoBits( n ) + 1;

    if ( c <= 3 )
    {
        change( a, n, bit( c, 1 ) );
        change( b, n, bit( c, 0 ) );
    }
}

inline void setDivisors( const int n, const int d )
{
    change( a, n, bit( d, 1 ) );
    change( b, n, bit( d, 0 ) );
}

int nrDivisors( int x )
{
    int n = 1;

    for ( int i = 2; i * i <= x; ++i )
    {
        int e = 0;

        while ( x % i == 0 )
        {
            x /= i;
            e++;
        }

        n *= ( e + 1 );
    }

    if ( x > 1 )
        n *= 2;

    return n;
}

int brute( int N )
{
    int sol = 0;

    for ( int i = 1; i <= N; ++i )
    {
        sol += ( nrDivisors( i ) >= 5 );
    }

    return sol;
}

int main()
{
    ifstream in("5div.in");
    ofstream out("5div.out");

    int N;

    in >> N;

    int sol = 0;

    for ( int i = 2; i <= N; ++i )
    {
        int nrDiv;

        if ( i % 2 == 0 && i > 2 )
            nrDiv = getTwoBits( i / 2 ) + 2;
        else
            nrDiv = getTwoBits( i );

        if ( i % 4 == 0 )
            nrDiv--;

        if ( nrDiv > 3 )
            nrDiv = 3;

        setDivisors( i, nrDiv );

        if ( nrDiv == 3 )
            sol++;
        else
            for ( int j = 3 * i; j <= N; j += 2 * i )
                addDivisor( j );
    }

    out << sol << "\n";

    in.close();
    out.close();

    return 0;
}
