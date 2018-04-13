#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

const int BASE = 91;
const int MOD1 = ( 1 << 19 ) - 1;
const int MOD2 = 666013;

const int Lmax = 100 + 2;

char A[Lmax];
char B[Lmax];
int N, M;

vector <int> match;

int main()
{
    cin >> ( A + 1 );
    cin >> ( B + 1 );

    N = strlen( A + 1 );
    M = strlen( B + 1 );

    int hashP1 = 0, hashP2 = 0;
    int rollingHash1 = 0, rollingHash2 = 0;
    int base1N = 1, base2N = 1;

    if ( N > M )
    {
        cout << "0\n";
        return 0;
    }

    for ( int i = 1; i <= N; ++i )
    {
        base1N = ( base1N * BASE ) % MOD1;
        base2N = ( base2N * BASE ) % MOD2;

        hashP1 = ( hashP1 * BASE + A[i] ) % MOD1;
        hashP2 = ( hashP2 * BASE + A[i] ) % MOD2;

        rollingHash1 = ( rollingHash1 * BASE + B[i] ) % MOD1;
        rollingHash2 = ( rollingHash2 * BASE + B[i] ) % MOD2;
    }

    if ( hashP1 == rollingHash1 && hashP2 == rollingHash2 )
    {
        match.push_back( 1 );
    }

    for ( int i = N + 1; i <= M; ++i )
    {
        rollingHash1 = ( ( rollingHash1 * BASE ) % MOD1 + B[i] - ( base1N * B[i - N] ) % MOD1 + MOD1 ) % MOD1;
        rollingHash2 = ( ( rollingHash2 * BASE ) % MOD2 + B[i] - ( base2N * B[i - N] ) % MOD2 + MOD2 ) % MOD2;

        if ( hashP1 == rollingHash1 && hashP2 == rollingHash2 )
        {
            match.push_back( i - N + 1 );
        }
    }

    cout << match.size() << "\n";

    for ( int i = 0; i < match.size(); ++i )
    {
        cout << match[i] << " ";
    }

    return 0;
}
