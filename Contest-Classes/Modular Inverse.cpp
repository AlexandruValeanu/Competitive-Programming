#include <bits/stdc++.h>

using namespace std;

class ModularInverse
{
public:

    ModularInverse(){}

    int modInv( int A, int N )
    {
        int x, y;
        euclid( A, N, x, y );

        if ( x <= 0 )
            x = N + x % N;

        return x;
    }

private:

    void euclid( int a, int b, int &x, int &y )
    {
        if ( !b )
        {
            x = 1;
            y = 0;
        }
        else
        {
            int x0, y0;

            euclid( b, a % b, x0, y0 );

            x = y0;
            y = x0 - ( a / b ) * y0;
        }
    }

};

int main()
{
    return 0;
}
