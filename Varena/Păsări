#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000;

int aib[Nmax + 1];
int table[256];

int N, S, K;

void initTable()
{
    for ( int i = 0; i < 256; ++i )
            table[i] = table[i / 2] + ( i & 1 );
}

inline int popcount( int x )
{
    int s = 0;

    for ( int i = 0; i < 32; i += 8 )
        s += table[ ( x >> i ) & 0xff ];

    return s;
}

inline int lsb( int x )
{
    return x & ( -x );
}

void update( int pos, int val )
{
    for ( int i = pos; i <= N; i += lsb( i ) )
        aib[i] |= val;
}

int query( int pos )
{
    int s = 0;

    for ( int i = pos; i >= 1; i -= lsb( i ) )
        s |= aib[i];

    return s;
}

int main()
{
    ifstream in("pasari.in");
    ofstream out("pasari.out");

    in >> N >> S >> K;

    initTable();

    while ( K-- )
    {
        int tip, s, x;

        in >> tip;

        if ( tip == 1 )
        {
            in >> s >> x;
            s--;
            update( x, 1 << s );
        }
        else
        {
            in >> x;
            out << popcount( query( x ) ) << "\n";
        }
    }

    return 0;
}
