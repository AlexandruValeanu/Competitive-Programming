#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

const int BASE = 91;
const int MOD1 = 666013;
const int MOD2 = ( 1 << 19 ) - 1;

const int Lmax = 2e6 + 2;

/// H( S[i...j] ) = S[i] + S[i + 1] * base + ... + S[j] * base ^ ( j - i );

vector <int> match;

int H1[Lmax];
int H2[Lmax];

char A[Lmax];
char B[Lmax];

int invBasePw1[Lmax];
int invBasePw2[Lmax];

int N, M;

int pw( int a, int p, int MOD )
{
    int res = 1;

    for ( int i = 0; ( 1 << i ) <= p; ++i )
    {
        if ( p & ( 1 << i ) )
                res = ( 1LL * res * a ) % MOD;

        a = ( 1LL * a * a ) % MOD;
    }

    return res;
}

int inv( int a, int MOD )
{
    return pw( a, MOD - 2, MOD );
}

void calc_inv()
{
    invBasePw1[0] = 1;
    invBasePw2[0] = 1;

    int I1 = inv( BASE, MOD1 );
    int I2 = inv( BASE, MOD2 );

    for ( int i = 1; i <= M; ++i )
    {
        invBasePw1[i] = ( 1LL * invBasePw1[i - 1] * I1 ) % MOD1;
        invBasePw2[i] = ( 1LL * invBasePw2[i - 1] * I2 ) % MOD2;
    }
}

void compute_hash()
{
    int baseI1 = 1;
    int baseI2 = 1;

    H1[0] = 0;
    H2[0] = 0;

    for ( int i = 1; i <= M; ++i )
    {
        H1[i] = ( H1[i - 1] + baseI1 * B[i] ) % MOD1;
        H2[i] = ( H2[i - 1] + baseI2 * B[i] ) % MOD2;

        baseI1 = ( baseI1 * BASE ) % MOD1;
        baseI2 = ( baseI2 * BASE ) % MOD2;
    }
}

pair<int,int> getHash( int i, int j )
{
    int c1 = H1[j] - H1[i - 1];
    int c2 = H2[j] - H2[i - 1];

    if ( c1 < MOD1 ) c1 += MOD1;
    if ( c2 < MOD2 ) c2 += MOD2;

    return pair<int,int>( ( 1LL * c1 * invBasePw1[i - 1] ) % MOD1, ( 1LL * c2 * invBasePw2[i - 1] ) % MOD2 );
}

pair<int,int> getCodeHash( char X[], int i, int j )
{
    int hash_p1 = 0, hash_p2 = 0;
    int baseI1 = 1, baseI2 = 1;

    for ( int k = i; k <= j; ++k )
    {
        hash_p1 = ( hash_p1 + baseI1 * X[k] ) % MOD1;
        hash_p2 = ( hash_p2 + baseI2 * X[k] ) % MOD2;

        baseI1 = ( baseI1 * BASE ) % MOD1;
        baseI2 = ( baseI2 * BASE ) % MOD2;
    }

    return pair<int,int>( hash_p1, hash_p2 );
}

int main()
{
    cin >> ( A + 1 );
    cin >> ( B + 1 );

    N = strlen( A + 1 );
    M = strlen( B + 1 );

    if ( N > M )
    {
        cout << "0\n";
        return 0;
    }

    calc_inv();
    compute_hash();

    pair<int,int> hashPattern = getCodeHash( A, 1, N );
    pair<int,int> rollingHash = getHash( 1, N );

    if ( hashPattern == rollingHash )
    {
        match.push_back( 0 );
    }

    for ( int i = N + 1; i <= M; ++i )
    {
        rollingHash = getHash( i - N + 1, i );

        if ( hashPattern == rollingHash )
        {
            match.push_back( i - N );
        }
    }

    cout << match.size() << "\n";

    for ( int i = 0; i < match.size(); ++i )
    {
        cout << match[i] << " ";
    }

    return 0;
}
