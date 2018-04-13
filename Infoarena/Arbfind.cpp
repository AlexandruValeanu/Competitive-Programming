#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
const ull BASE = 137;

const int Nmax = 32e3 + 2;

vector <int> T1[Nmax], T2[Nmax];
int lgA;
int begin2[Nmax], end2[Nmax], lgB;
char A[4 * Nmax], B[4 * Nmax];
int N, M;

int sum[4 * Nmax];

ull H1[4 * Nmax], H2[4 * Nmax];
ull Hpow[4 * Nmax];

void DFS1( int nod )
{
    A[ ++lgA ] = 'S';

    for ( auto x: T1[nod] )
    {
        A[ ++lgA ] = 'D';
        DFS1( x );
        A[ ++lgA ] = 'U';
    }

    A[ ++lgA ] = 'F';
}

void DFS2( int nod )
{
    begin2[nod] = ++lgB;
    B[lgB] = 'S';

    for ( auto x: T2[nod] )
    {
        B[ ++lgB ] = 'D';
        DFS2( x );
        B[ ++lgB ] = 'U';
    }

    end2[nod] = ++lgB;
    B[lgB] = 'F';
}

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= max( lgA, lgB ); ++i )
        Hpow[i] = Hpow[i - 1] * BASE;

    for ( int i = 1; i <= lgA; ++i )
        H1[i] = H1[i - 1] * BASE + A[i];

    for ( int i = 1; i <= lgB; ++i )
        H2[i] = H2[i - 1] * BASE + B[i];
}

ull getHash( ull H[], int i, int j )
{
    return H[j] - H[i - 1] * Hpow[j - i + 1];
}

int lcp( int nod )
{
    int i = 1, j = min( end2[nod] - begin2[nod] + 1, lgA ), m;

    while ( i <= j )
    {
        m = ( i + j ) / 2;

        if ( getHash( H1, 1, m ) == getHash( H2, begin2[nod], begin2[nod] + m - 1 ) )
            i = m + 1;
        else
            j = m - 1;
    }

    return j;
}

int main()
{
    ifstream in("arbfind.in");
    ofstream out("arbfind.out");

    in.sync_with_stdio( false );

    in >> N;

    for ( int i = 1; i <= N; ++i )
    {
        int nr, a;

        in >> nr;

        while ( nr-- )
        {
            in >> a;
            T1[i].push_back( a );
        }
    }

    in >> M;

    for ( int i = 1; i <= M; ++i )
    {
        int nr, a;

        in >> nr;

        while ( nr-- )
        {
            in >> a;
            T2[i].push_back( a );
        }
    }

    DFS1( 1 );
    DFS2( 1 );

    pregen();

    for ( int i = 1; i <= lgA; ++i )
        sum[i] = sum[i - 1] + ( A[i] == 'S' );

    for ( int i = 1; i <= M; ++i )
    {
        out << sum[ lcp( i ) ] << "\n";
    }

    return 0;
}
