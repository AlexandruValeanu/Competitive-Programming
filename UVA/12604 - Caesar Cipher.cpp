#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

const int Amax =  62 + 2;
const int Wmax = 5e4 + 2;
const int Smax = 5e5 + 2;
const int Sigma = 256;

char A[Amax];
char W[Wmax];
char S[Smax];
int position[Sigma];

int pi[Wmax];
int d[Smax];

int T, lgA, lgW, lgS;

char nextC( char ch, int nxt )
{
    int p = position[ch] + nxt;

    while ( p > lgA ) p -= lgA;

    return A[p];
}

void build_prefix()
{
    int lgprefix = 0;

    pi[1] = 0;

    for ( int i = 2; i <= lgW; ++i )
    {
        while ( lgprefix > 0 && W[i] != W[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( W[i] == W[lgprefix + 1] )
            lgprefix++;

        pi[i] = lgprefix;
    }
}

int KMP( int nxt )
{
    int lgprefix = 0;
    int contor = 0;

    for ( int i = 1; i <= lgS; ++i )
    {
        while ( lgprefix > 0 && S[i] != nextC( W[lgprefix + 1], nxt ) )
                lgprefix = pi[lgprefix];

        if ( S[i] == nextC( W[lgprefix + 1], nxt ) )
            lgprefix++;

        d[i] = lgprefix;

        if ( d[i] == lgW ) contor++;

        if ( contor == 2 )
                return 0;
    }

    return contor;
}

int main()
{
    ///ifstream cin("data.in");

    cin >> T;

    while ( T-- )
    {
        cin >> ( A + 1 ) >> ( W + 1 ) >> ( S + 1 );

        lgA = strlen( A + 1 );
        lgW = strlen( W + 1 );
        lgS = strlen( S + 1 );

        for ( int i = 1; i <= lgA; ++i )
                position[ A[i] ] = i;

        build_prefix();

        vector <int> v;

        for ( int i = 0; i < lgA; ++i )
        {
            if ( KMP( i ) == 1 )
                    v.push_back( i );
        }

        if ( v.size() == 0 )
        {
            cout << "no solution\n";
            continue;
        }

        if ( v.size() == 1 )
        {
            cout << "unique: " << v[0] << "\n";
            continue;
        }

        cout << "ambiguous: ";

        for ( int i = 0; i < v.size(); ++i )
        {
            cout << v[i];

            if ( i != v.size() - 1 )
                    cout << " ";
        }

        cout << "\n";
    }

    return 0;
}
