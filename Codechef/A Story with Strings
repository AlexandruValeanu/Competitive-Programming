#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
const ull BASE = 137;

const int Lmax = 25e4 + 2;

ull H1[Lmax], H2[Lmax];
ull Hpow[Lmax];
char A[Lmax], B[Lmax];
int N, M;

char sol[Lmax];
int ans;

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= max( N, M ); ++i )
        Hpow[i] = Hpow[i - 1] * BASE;

    for ( int i = 1; i <= N; ++i )
        H1[i] = H1[i - 1] * BASE + A[i];

    for ( int j = 1; j <= M; ++j )
        H2[j] = H2[j - 1] * BASE + B[j];
}

ull getHash( ull H[], int i, int j )
{
    return H[j] - H[i - 1] * Hpow[j - i + 1];
}

int valid( int lg )
{
    unordered_set <ull> S;

    for ( int i = 1; i + lg - 1 <= N; ++i )
    {
        S.insert( getHash( H1, i, i + lg - 1 ) );
    }

    for ( int i = 1; i + lg - 1 <= M; ++i )
    {
        if ( S.find( getHash( H2, i, i + lg - 1 ) ) != S.end() )
        {
            ans = lg;

            for ( int j = 1; j <= lg; ++j )
                    sol[j] = B[i + j - 1];

            return 1;
        }
    }

    return 0;
}

void bsearch()
{
    int lo = 0, hi = min( N, M ), mid;

    while ( lo <= hi )
    {
        mid = ( lo + hi ) / 2;

        if ( valid( mid ) )
            lo = mid + 1;
        else
            hi = mid - 1;
    }
}

int main()
{
    ///ifstream cin("data.in");

    cin.sync_with_stdio( false );

    cin >> ( A + 1 );
    cin >> ( B + 1 );

    N = strlen( A + 1 );
    M = strlen( B + 1 );

    pregen();

    bsearch();

    for ( int i = 1; i <= ans; ++i )
        cout << sol[i];

    if ( ans )
        cout << "\n";

    cout << ans << "\n";

    return 0;
}
