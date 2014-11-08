#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e7 + 1;
const int Pmax = 20 + 1;

class LinearProbing
{
public:

    LinearProbing()
    {
        data = new unsigned[PW];

        for ( unsigned i = 0; i < PW; ++i )
            data[i] = EMPTY;
    }

    ~LinearProbing()
    {
        delete [] data;
    }

    void insert( const unsigned value )
    {
        for ( int i = ( ( value & MOD ) * PRIME ) & MOD; ; i = ( i + 1 ) & MOD )
        {
            if ( data[i] == EMPTY || data[i] == ERASED )
            {
                data[i] = value;
                break;
            }
        }
    }

    void erase( const unsigned value )
    {
        for ( int i = ( ( value & MOD ) * PRIME ) & MOD; data[i] != EMPTY; i = ( i + 1 ) & MOD )
        {
            if ( data[i] == value )
            {
                data[i] = ERASED;
                break;
            }
        }
    }

    bool find( const unsigned value ) const
    {
        for ( int i = ( ( value & MOD ) * PRIME ) & MOD; data[i] != EMPTY; i = ( i + 1 ) & MOD )
        {
            if ( data[i] == value )
                return true;
        }

        return false;
    }

private:

    static const unsigned PW = ( 1 << 22 );
    static const unsigned MOD = PW - 1;
    static const unsigned PRIME = 97;

    static const unsigned EMPTY = -1;
    static const unsigned ERASED = -2;

    unsigned *data;
};

char s[Nmax], sir[Pmax];
int T, P;

int main()
{
    ifstream in("abc2.in");
    ofstream out("abc2.out");

    ios_base::sync_with_stdio( false );

    LinearProbing L;

    in >> ( s + 1 );
    T = strlen( s + 1 );

    unsigned base = 1;

    while ( in >> ( sir + 1 ) )
    {
        if ( !P )
            P = strlen( sir + 1 );

        unsigned cod = 0;

        for ( int i = 1; i <= P; ++i )
            cod = cod * 3U + ( sir[i] - 'a' );

        L.insert( cod );
    }

    for ( int i = 1; i < P; ++i )
        base *= 3U;

    int sol = 0;
    unsigned cod = 0;

    for ( int i = 1; i <= T; ++i )
    {
        if ( i > P )
            cod -= 1U * base * ( s[i - P] - 'a' );

        cod = cod * 3U + ( s[i] - 'a' );

        if ( i >= P )
            sol += ( L.find( cod ) );
    }

    out << sol << "\n";

    return 0;
}
