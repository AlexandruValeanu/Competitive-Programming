#include <bits/stdc++.h>

using namespace std;

struct BloomFilter
{
    static const int NumberOfPrimes = 4;
    static const int Primes[NumberOfPrimes];

    struct BitSet
    {
        int N;
        unsigned long long *b;

        explicit BitSet() : N(0), b(nullptr)
        {
        }

        BitSet(const int _N) : N(_N), b(new unsigned long long[N / 64 + 1])
        {
            for ( int i = 0; i < N / 64 + 1; ++i )
                b[i] = 0;
        }

        void set(const int pos)
        {
            b[pos >> 6] |= ( 1ULL << ( pos & 63 ) );
        }

        bool test(const int pos)
        {
            return b[pos >> 6] & ( 1ULL << ( pos & 63 ) );
        }
    };

    BitSet filter[NumberOfPrimes];

    BloomFilter()
    {
        for ( int i = 0; i < NumberOfPrimes; ++i )
            filter[i] = BitSet( Primes[i] );
    }

    inline void insert(const long long key)
    {
        for ( int i = 0; i < NumberOfPrimes; ++i )
            filter[i].set( key % Primes[i] );
    }

    inline bool find(const long long key)
    {
        for ( int i = 0; i < NumberOfPrimes; ++i )
            if ( filter[i].test( key % Primes[i] ) == 0 )
                return false;

        return true;
    }
};

const int BloomFilter::Primes[] = { 666013, 100003, 826663, 797593 };

int main()
{
    return 0;
}
