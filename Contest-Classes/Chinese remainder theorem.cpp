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

class ChineseRemainderTheorem
{
public:

    ChineseRemainderTheorem( vector<int> &x, vector<int> &y )
    {
        a = x;
        r = y;

        S = vector<int>( x.size() );
        K = vector<int>( x.size() );
    }

    pair<int,int> solve()
    {
        R = 1;

        for ( unsigned i = 0; i < r.size(); ++i )
            R *= r[i];

        for ( unsigned i = 0; i < r.size(); ++i )
            S[i] = R / r[i];

        ModularInverse A;

        for ( unsigned i = 0; i < K.size(); ++i )
            K[i] = A.modInv( S[i], r[i] );

        int solK = 0;

        for ( unsigned i = 0; i < K.size(); ++i )
            solK = ( solK + S[i] * K[i] * a[i] ) % R;

        return pair<int,int>( solK, R );
    }

private:

    vector <int> a, r;
    vector <int> S;
    vector <int> K;
    int R;
};

int main()
{
    return 0;
}
