#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int Nmax = 1000001;

int N, R, C;
int H[Nmax], A[Nmax];

int valid( int D )
{
    for ( int i = 1; i <= N; ++i )
    {
        A[i] = 0;

        if ( i >= C && H[i] - H[i - C + 1] <= D )
        {
            A[i] = max( A[i - 1], A[i - C] + 1 );
        }
        else
        {
            A[i] = A[i - 1];
        }

        if ( A[i] >= R )
                return 1;
    }

    return 0;
}

int cautare()
{
    int st = 0, dr = 1000000000, m, gasit = 0;;

    while ( st <= dr )
    {
        m = ( st + dr ) / 2;

        if ( valid( m ) )
        {
            gasit = m;
            dr = m - 1;
        }
        else
        {
            st = m + 1;
        }
    }

    return gasit;
}

const int BUFF_SIZE = 1 << 20;
int position = BUFF_SIZE;
char buffer[BUFF_SIZE];

char getChar()
{
    if ( position == BUFF_SIZE )
    {
        fread( buffer, 1, BUFF_SIZE, stdin );
        position = 0;
    }

    return buffer[ position++ ];
}

int read()
{
    int nr = 0;
    char c;

    do
    {
        c = getChar();

    } while ( !isdigit( c ) );

    do
    {
        nr = nr * 10 + c - '0';
        c = getChar();

    } while ( isdigit( c ) );

    return nr;
}

int main()
{
    freopen("easychoice.in", "r", stdin);
    freopen("easychoice.out", "w", stdout);

    N = read(); R = read(); C = read();

    for ( int i = 1; i <= N; ++i )
    {
        H[i] = read();
    }

    sort( H + 1, H + N + 1 );

    printf("%d\n", cautare());

    return 0;
}
