#include <bits/stdc++.h>

using namespace std;

int N;

inline void fastRead( int &a )
{
    register char ch;
    a = 0;

    do
    {
        ch = getchar_unlocked();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar_unlocked();

    } while( isdigit( ch ) );
}

inline void fastWrite( int a )
{
    char s[20];
    int i = 0;

    do
    {
        s[ i++ ] = a % 10 + '0';
        a /= 10;

    } while ( a );

    i--;

    while ( i >= 0 ) putchar_unlocked( s[ i-- ] );

    putchar_unlocked( '\n' );
}

int main()
{
    fastRead( N );

    while ( N-- )
    {
        int x, y, sol = 0;

        fastRead( x ); fastRead( y );

        while ( x != y )
        {
            if ( x > y )
                x >>= 1;
            else
                y >>= 1;

            sol++;
        }

        fastWrite( sol );
    }

    return 0;
}
