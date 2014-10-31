#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100 + 1;
const int Kmax = 50 + 1;

short mex[Kmax][Nmax][Nmax];
short a[Kmax][Nmax];
int lg[Kmax];
int K;

int compute_grundy( short a[], int st, int dr, short d[][Nmax] );

int getGrundy( short a[], int st, int dr, short d[][Nmax], int pos )
{
    int sum = 0;

    for ( int i = st; i <= dr; ++i )
    {
        if ( a[i] <= a[pos] ) continue;

        int p = i;

        while ( p + 1 <= dr && a[p + 1] > a[pos] ) p++;

        sum ^= compute_grundy( a, i, p, d );

        i = p + 1;
    }

    return sum;
}

int compute_grundy( short a[], int st, int dr, short d[][Nmax] )
{
    if ( d[st][dr] != -1 )
        return d[st][dr];

    int Set[Nmax];

    memset( Set, 0, sizeof( Set ) );

    for ( int k = st; k <= dr; ++k )
    {
        int sum = getGrundy( a, st, dr, d, k );

        Set[sum]++;
    }

    d[st][dr] = 0;

    while ( Set[ d[st][dr] ] ) d[st][dr]++;

    return d[st][dr];
}

int sprague_grundy()
{
    int s = 0;

    for ( int i = 1; i <= K; ++i )
        s ^= mex[i][1][ lg[i] ];

    return s;
}

int getMove( short a[], int n, short d[][Nmax], int xorsum )
{
    int newSum = xorsum ^ d[1][n];

    for ( int i = 1; i <= n; ++i )
    {
        if ( getGrundy( a, 1, n, d, i ) == newSum )
            return i;
    }

    return -1;
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio( false );

    cin >> K;

    memset( mex, -1, sizeof( mex ) );

    for ( int i = 1; i <= K; ++i )
    {
        cin >> lg[i];

        for ( int j = 1; j <= lg[i]; ++j )
            cin >> a[i][j];

        mex[i][1][ lg[i] ] = compute_grundy( a[i], 1, lg[i], mex[i] );
    }

    int xorsum = sprague_grundy();

    if ( !xorsum )
        cout << "S\n";
    else
    {
        cout << "G\n";

        for ( int i = 1; i <= K; ++i )
        {
            int m = getMove( a[i], lg[i], mex[i], xorsum );

            if ( m != -1 )
            {
                cout << i << " ";
                cout << m << "\n";
                return 0;
            }
        }
    }

    return 0;
}
