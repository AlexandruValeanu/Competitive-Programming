#include <bits/stdc++.h>

using namespace std;

class CountBits
{
public:

    CountBits()
    {
        memset( table, 0, sizeof( table ) );

        for ( int i = 0; i < 256; ++i )
            table[i] = table[i / 2] + ( i & 1 );
    }

    template <typename T>
    int popcount( const T x ) const
    {
        try
        {
            if ( x < 0 )
                throw -1;

        } catch( int err )
        {
            cerr << "An exception occurred. The value is negative\n";
            return err;
        }

        int sum = 0;
        int c = 32;

        if ( x >= ( 1LL << 31 ) )
            c = 64;

        for ( int i = 0; i < c; i += 8 )
            sum += table[ ( x >> i ) & 0xff ];

        return sum;
    }
private:

    int table[256];
};

int main()
{
    return 0;
}
