#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int Nmax = 1000;
const int NR_BITS = 64;

ull D[Nmax + 1][Nmax / NR_BITS + 1];
char s[Nmax + 1];

int N, Q;

void genTest();

bool checkBit( int nod, int k )
{
    return D[nod][k / NR_BITS] & ( 1ull << ( k % NR_BITS ) );
}

int checkBrute( int a, int b )
{
    for ( int i = 0; i < N; ++i )
        if ( checkBit( i, a ) && checkBit( i, b ) )
            return 1;

    return 0;
}

int main()
{
    ///freopen("data.in", "r", stdin);
    ///freopen("data.out", "w", stdout);

    scanf("%d", &N);

    assert( 1 <= N && N <= 1000 );

    for ( int i = 0; i < N; ++i )
    {
        scanf("%s", s);

        assert( s[i] == '0' );

        for ( int j = 0; j < N; ++j )
        {
            if ( s[j] == '1' )
            {
                assert( '0' <= s[j] && s[j] <= '1' );

                D[i][j / NR_BITS] |= 1ull << ( j % NR_BITS );
            }
        }
    }

    for ( int i = 0; i < N; ++i )
        for ( int j = 0; j < N; ++j )
            assert( checkBit( i, j ) != 1 || checkBit( j, i ) != 1 );

    for ( int k = 0; k < N; ++k )
        for ( int i = 0; i < N; ++i )
        {
            if ( checkBit( i, k ) )
            {
                for ( int j = 0; j <= N / NR_BITS; ++j )
                    D[i][j] |= D[k][j];
            }
        }

    scanf("%d", &Q);

    assert( 1 <= Q && Q <= 50000 );

    while ( Q-- )
    {
        int a, b;

        scanf("%d %d", &a, &b);

        assert( a != b );
        assert( 1 <= a && a <= N );
        assert( 1 <= b && b <= N );

        a--; b--;

        if ( checkBrute( a, b ) )
            puts("No");
        else
            puts("YES");
    }

    return 0;
}

void genTest()
{
    ofstream out("data.in");

    srand( time( NULL ) );

    const int N = 1 + rand() % 1000;
    const int Q = 50000;

    out << N << "\n";

    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = 1; j <= N; ++j )
            if ( i == j )
                out << 0;
            else
                out << 1;

        out << "\n";
    }

    out << Q << "\n";

    for ( int i = 0; i < Q; ++i )
    {
        int a, b;

        a = 1 + rand() % N;
        b = 1 + rand() % N;

        while ( b == a ) b = 1 + rand() % N;

        out << a << " " << b << "\n";
    }

    out.close();
}
