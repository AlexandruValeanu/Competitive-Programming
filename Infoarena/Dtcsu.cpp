#include <bits/stdc++.h>

using namespace std;

///------------------------------------------------------
const int BS = 1 << 17;
char buffer[BS];
int position = BS;

inline char getChar()
{
    if ( position == BS )
    {
        position = 0;
        fread( buffer, BS, 1, stdin );
    }

    return buffer[ position++ ];
}

inline long long getNr()
{
    register long long a = 0;
    char ch;

    do
    {
        ch = getChar();

    } while ( !isdigit(ch) );

    do
    {
        a = (a << 3) + (a << 1) + ch - '0';
        ch = getChar();

    } while ( isdigit(ch) );

    return a;
}
///------------------------------------------------------

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

const int N = 276997;
int Q;

BloomFilter B;

int main()
{
    freopen("dtcsu.in", "r", stdin);
    freopen("dtcsu.out", "w", stdout);

    for ( int i = 1; i <= N; ++i )
    {
        long long X = getNr();
        B.insert(X);
    }

    Q = getNr();
    int sol = 0;

    while ( Q-- )
    {
        long long X = getNr();
        bool ok = B.find(X);

        if ( ok )
        {
            X /= (X&(-X));
            for ( ; (X/15)*15 == X ; X /= 15 );
            for ( ; (X/3)*3 == X ; X /= 3 );
            for ( ; (X/5)*5 == X ; X /= 5 );
            for ( ; (X/7)*7 == X ; X /= 7 );
            for ( ; (X/11)*11 == X ; X /= 11 );
            if ( X == 1 ) ++sol;
        }
    }

    printf("%d\n",sol);

    return 0;
}
