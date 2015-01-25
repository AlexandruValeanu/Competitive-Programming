#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef int Huge[2000];

long long Mod(Huge A, long long X)
{
    long long R = 0;

    for ( int i = A[0]; i >= 1; i-- )
    {
        R = R * 10LL + A[i];
        R %= X;
    }

    return R;
}

long long Divide(Huge A, long long X)
{
    long long R = 0;

    for ( int i = A[0]; i >= 1; i-- )
    {
        R = R * 10LL + A[i];
        A[i] = R / X;
        R %= X;
    }

    while ( !A[A[0]] && A[0] ) A[0]--;

    return R;
}

long long M;
Huge X, Y;

void getHuge(Huge A, const string& s)
{
    for ( int i = 0; i < 2000; ++i )
        A[i] = 0;

    for ( int i = s.size() - 1; i >= 0; i-- )
        A[ ++A[0] ] = s[i] - '0';
}

void printHuge(Huge A)
{
    for ( int i = A[0]; i >= 1; --i )
        cout << A[i];
}

long long inmulture(long long a,long long b)
{
    long long int res = 0;

    while (a > 0)
    {
        if (a & 1)
        {
            res += b;
            res %= M;
        }

        a >>= 1;
        b <<= 1;

        b %= M;
    }

    return res;
}

long long power( long long a )
{
    long long sol = 1;

    while ( Y[0] )
    {
        int r = Divide( Y, 2 );

        if ( r == 1 )
            sol = inmulture( sol, a );

        a = inmulture( a, a );
    }

    return sol;
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio( false );

    int T;

    cin >> T;

    while ( T-- )
    {
        string s;

        cin >> M;
        cin >> s;

        long long ans = 1;

        for ( int i = 0; i < s.size(); )
        {
            string x, y;

            int j = i;

            while ( isdigit( s[j] ) )
            {
                x.push_back( s[j] );
                j++;
            }

            j++;
            j++;

            while ( isdigit( s[j] ) )
            {
                y.push_back( s[j] );
                j++;
            }

            j++;
            i = j;

            getHuge( X, x );
            getHuge( Y, y );

            long long newX = Mod( X, M );

            ans = inmulture( ans, power( newX ) );
        }

        cout << ans << "\n";
    }

    return 0;
}
