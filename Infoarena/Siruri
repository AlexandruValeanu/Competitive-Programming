#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
const int Lmax = 1e5 + 2;
const int BASE = 137;

int A[Lmax];
int B[Lmax];
int N, M;

ull HA[Lmax], HB[Lmax];
ull Hpow[Lmax];

int startA, startB;

ull getHash( ull H[], int i, int j )
{
    return H[j] - H[i - 1] * Hpow[j - i + 1];
}

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= max( N, M ); ++i )
            Hpow[i] = Hpow[i - 1] * BASE;

    for ( int i = 1; i <= N; ++i )
            HA[i] = HA[i - 1] * BASE + A[i];

    for ( int i = 1; i <= M; ++i )
            HB[i] = HB[i - 1] * BASE + B[i];
}

int checkLength( int l )
{
    unordered_set <ull> US;

    for ( int i = 1; i <= N - l + 1; ++i )
            US.insert( getHash( HA, i, i + l - 1 ) );

    for ( int i = 1; i <= M - l + 1; ++i )
            if ( US.find( getHash( HB, i, i + l - 1 ) ) != US.end() )
            {
                startB = i;

                for ( int j = 1; j <= N - l + 1; ++j )
                {
                    if ( getHash( HA, j, j + l - 1 ) == getHash( HB, i, i + l - 1 ) )
                    {
                        startA = j;
                        break;
                    }
                }

                return 1;
            }

    return 0;
}

int bsearch()
{
    int st = 1, dr = min( N, M ), m;

    while ( st <= dr )
    {
        m = ( st + dr ) / 2;

        if ( checkLength( m ) )
            st = m + 1;
        else
            dr = m - 1;
    }

    return dr;
}

int main()
{
    ifstream in("siruri.in");
    ofstream out("siruri.out");

    in.sync_with_stdio( false );

    in >> N;

    for ( int i = 1; i <= N; ++i )
        in >> A[i];

    in >> M;

    for ( int i = 1; i <= M; ++i )
        in >> B[i];

    for ( int i = 1; i < N; ++i )
    {
        A[i] = A[i + 1] - A[i];
    }

    for ( int i = 1; i <= M; ++i )
    {
        B[i] = B[i] - B[i + 1];
    }

    N--;
    M--;

    pregen();

    int b = bsearch();

    out << b + 1 << " " << startA << " " << startB << "\n";

    return 0;
}
