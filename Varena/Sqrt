#include <bits/stdc++.h>

using namespace std;

const int BASE = 1000000000;
const char printFormat[] = { "%.9d" };

const int Lmax = 3050;
typedef int Huge[Lmax];

void add( Huge A, Huge B )
{
    int T = 0;
    int i;

    for ( i = 1; i <= A[0] || i <= B[0] || T; ++i )
    {
        if ( i > A[0] ) A[i] = 0;
        if ( i > B[0] ) B[i] = 0;

        T += A[i] + B[i];
        A[i] = T % BASE;
        T /= BASE;
    }

    A[0] = i - 1;
}

void add( Huge A, int x )
{
    int T = 0;
    int i;

    for ( i = 1; i <= A[0] || T; ++i )
    {
        if ( i > A[0] ) A[i] = 0;

        T += A[i] + x;
        A[i] = T % BASE;
        T /= BASE;

        x = 0;
    }

    A[0] = i - 1;
}

void multiply( Huge A, int x )
{
    long long T = 0;
    int i;

    for ( i = 1; i <= A[0] || T; ++i )
    {
        if ( i > A[0] ) A[i] = 0;

        T += 1LL * A[i] * x;
        A[i] = T % BASE;
        T /= BASE;
    }

    A[0] = i - 1;

    while ( !A[ A[0] ] && A[0] > 1 ) A[0]--;
}

void subtract( Huge A, Huge B )
{
    for ( int i = B[0] + 1; i <= A[0]; ++i ) B[i] = 0;

    int T = 0;

    for ( int i = 1; i <= A[0]; ++i )
    {
        A[i] -= B[i] + T;

        if ( A[i] < 0 )
            T = 1;
        else
            T = 0;

        if ( T )
            A[i] += BASE;
    }

    while ( !A[ A[0] ] && A[0] > 1 ) A[0]--;
}

int compare( Huge A, Huge B )
{
    if ( A[0] < B[0] )
        return -1;

    if ( A[0] > B[0] )
        return 1;

    for ( int i = A[0]; i >= 1; i-- )
    {
        if ( A[i] < B[i] )
            return -1;

        if ( A[i] > B[i] )
            return 1;
    }

    return 0;
}

void clearHuge( Huge A )
{
    for ( int i = 0; i < Lmax; ++i )
        A[i] = 0;
}

void initWithNumber( Huge A, int number )
{
    clearHuge( A );

    do
    {
        A[ ++A[0] ] = number % BASE;
        number /= BASE;

    } while ( number );
}

void copyHuge( Huge A, Huge B )
{
    for ( int i = B[0]; i >= 0; i-- )
        A[i] = B[i];
}

void readHuge( Huge A )
{
    char str[Lmax];
    clearHuge( A );

    scanf("%s", str);
    int n = strlen( str );

    for ( int i = n - 1; i >= 0; i-- )
        A[ ++A[0] ] = str[i] - '0';
}

void printHuge( Huge A )
{
    printf("%d", A[ A[0] ]);

    for ( int i = A[0] - 1; i >= 1; --i )
        printf(printFormat, A[i]);

    puts("");
}

void radical( Huge H )
{
    int grupa[Lmax], n = 0;
    memset( grupa, 0, sizeof( grupa ) );

    for ( int i = 1; i <= H[0]; i += 2 )
        grupa[ ++n ] = H[i + 1] * 10 + H[i];

    Huge answer;
    initWithNumber( answer, 0 );

    Huge remain;
    initWithNumber( remain, 0 );

    Huge odd;
    initWithNumber( odd, 0 );

    for ( int i = n; i >= 1; i-- )
    {
        copyHuge( odd, answer );
        multiply( odd, 20 );
        add( odd, 1 );

        multiply( remain, 100 );
        add( remain, grupa[i] );

        int digit = 0;

        while ( compare( remain, odd ) != -1 )
        {
            digit++;
            subtract( remain, odd );
            add( odd, 2 );
        }

        multiply( answer, 10 );
        add( answer, digit );
    }

    copyHuge( H, answer );
}

int main()
{
    freopen("sqrt.in", "r", stdin);
    freopen("sqrt.out", "w", stdout);

    Huge A;

    readHuge(A);
    radical(A);
    printHuge(A);

    return 0;
}
