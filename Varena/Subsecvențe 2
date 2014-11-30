#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

using namespace std;

typedef unsigned long long ULL;

const int Nmax = 50;
const int Smax = 5e5;
const int Lmax = 60;

char source[Smax + 1];
int buckets[2][Smax + 1];

char str[Smax + 1];
char aux[Smax + 1];
int N, solution, totalLg;

void radix_sort( int st, int dr, int lg, int p )
{
    ULL codA = 0, codB = 0;
    int drA = st - 1, stB = dr + 1;

    for ( int i = st; i <= dr; ++i )
    {
        int n = buckets[p ^ 1][i];

        if ( n + lg - 1 <= totalLg && source[n] == source[n + lg - 1] )
        {
            if ( str[n + lg - 1] == 'a' )
            {
                buckets[p][ ++drA ] = n;
                codA |= ( 1ULL << ( source[n] - '0' ) );
            }
            else
            {
                buckets[p][ --stB ] = n;
                codB |= ( 1ULL << ( source[n] - '0' ) );
            }
        }
    }

    if ( codA == ( 1ULL << N ) - 1 )
    {
        solution = max( solution, lg );
        radix_sort( st, drA, lg + 1, p ^ 1 );
    }

    if ( codB == ( 1ULL << N ) - 1 )
    {
        solution = max( solution, lg );
        radix_sort( stB, dr, lg + 1, p ^ 1 );
    }
}

int main()
{
    FILE *f = fopen("subsecvente2.in", "r");

    fscanf(f, "%d\n", &N);

    for ( int i = 0; i < N; ++i )
    {
        fscanf(f, "%s\n", aux);

        int lg = strlen( aux );

        for ( int k = 0; k < lg; ++k )
        {
            ++totalLg;
            str[totalLg] = aux[k];
            source[totalLg] = i + '0';
            buckets[0][totalLg] = totalLg;
        }
    }

    radix_sort( 1, totalLg, 1, 1 );

    FILE *g = fopen("subsecvente2.out", "w");

    fprintf(g, "%d\n", solution);

    fclose( f );
    fclose( g );

    return 0;
}
