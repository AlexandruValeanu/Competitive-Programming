#include <bits/stdc++.h>

using namespace std;

class BitSet
{
public:

    BitSet() : maxn( 0 ), bits( NULL )
    {
    }

    BitSet( const size_t n ) : maxn( n ), bits( new unsigned[n / 32 + 1] )
    {
        this->clear();
    }

    BitSet& operator = ( const BitSet& B )
    {
        delete bits;

        this->maxn = B.maxn;
        this->bits = new unsigned[maxn / 32 + 1];

        for ( size_t i = 0; i < maxn / 32 + 1; ++i )
            this->bits[i] = B.bits[i];

        return *this;
    }

    void flip( const size_t position )
    {
        bits[position >> 5] ^= ( 1U << ( position & 31 ) );
    }

    bool test( const size_t position ) const
    {
        return ( bits[position >> 5] >> ( position & 31 ) ) & 1;
    }

    bool operator [] ( const size_t position ) const
    {
        return test( position );
    }

    void set( const size_t position, const bool value )
    {
        if ( test( position ) != value )
            flip( position );
    }

    void clear()
    {
        for ( size_t i = 0; i < maxn / 32 + 1; ++i )
            bits[i] = 0;
    }

    BitSet operator & ( const BitSet& rhs ) const
    {
        BitSet solution( maxn );

        for ( size_t i = 0; i < maxn / 32 + 1; ++i )
            solution.bits[i] = this->bits[i] & rhs.bits[i];

        return solution;
    }

    BitSet operator ^ ( const BitSet& rhs ) const
    {
        BitSet solution( maxn );

        for ( size_t i = 0; i < maxn / 32 + 1; ++i )
            solution.bits[i] = this->bits[i] ^ rhs.bits[i];

        return solution;
    }

    BitSet operator | ( const BitSet& rhs ) const
    {
        BitSet solution( maxn );

        for ( size_t i = 0; i < maxn / 32 + 1; ++i )
            solution.bits[i] = this->bits[i] | rhs.bits[i];

        return solution;
    }

    BitSet& operator &= ( const BitSet& rhs )
    {
        for ( size_t i = 0; i < maxn / 32 + 1; ++i )
            this->bits[i] &= rhs.bits[i];

        return *this;
    }

    BitSet& operator |= ( const BitSet& rhs )
    {
        for ( size_t i = 0; i < maxn / 32 + 1; ++i )
            this->bits[i] |= rhs.bits[i];

        return *this;
    }

    BitSet& operator ^= ( const BitSet& rhs )
    {
        for ( size_t i = 0; i < maxn / 32 + 1; ++i )
            this->bits[i] ^= rhs.bits[i];

        return *this;
    }

    void setUnsigned( size_t position, const unsigned value )
    {
        size_t ind = position >> 5;

        if ( ind < maxn / 32 + 1 )
            bits[ind] |= value << ( position & 31 );

        position += 31;
        ind = position >> 5;

        if ( ind < maxn / 32 + 1 )
            bits[ind] |= value << ( 31 - ( position & 31 ) );
    }

    BitSet shift( const int sh )
    {
        BitSet sol( maxn );
        sol.clear();

        for ( size_t i = 0; i < maxn / 32 + 1; ++i )
        {
            size_t position = ( i << 5 ) + sh;
            sol.setUnsigned( position, bits[i] );
        }

        return sol;
    }

    friend ostream& operator << ( ostream &stream, const BitSet& B )
    {
        for ( size_t i = 0; i < B.size(); ++i )
            stream << B[i];

        return stream;
    }

    size_t size() const
    {
        return maxn;
    }

private:

    size_t maxn;
    unsigned *bits;
};

int main()
{
    return 0;
}
