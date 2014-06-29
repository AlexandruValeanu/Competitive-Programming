#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int Nmax = 1e5 + 2;

int N, Q;

int a[Nmax];
int b[Nmax];
int answer;

void MergeSort( int l, int r )
{
    int m = (l + r)/2, k, i, j;

    if ( l == r )
        return;

    MergeSort( l, m );
    MergeSort( m + 1, r );

    for( i = l, j = m + 1, k = l; i <= m || j <= r; )
        if( j > r || ( i <= m && a[i] <= a[j] ) )
            b[ k++ ] = a[ i++ ];
        else
        {
            b[ k++ ] = a[ j++ ];

            answer = ( answer + m - i + 1 ) % 2;
        }

    for( k = l; k <= r; k++ )
        a[k] = b[k];
}


int main()
{
    cin.sync_with_stdio( false );

    cin >> N >> Q;

    for ( int i = 1; i <= N; ++i )
        cin >> a[i];

    MergeSort( 1, N );

    while ( Q-- )
    {
        int X, Y;

        cin >> X >> Y;
        cout << ( answer ^= 1 ) << "\n";
    }

    return 0;
}
