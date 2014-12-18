#include <iostream>
#include <fstream>

using namespace std;

const int Nmax = 500 + 1;

int C[Nmax][Nmax];
int N, M, X, Y;
int S;
int Z, T, K;

void update( int sum, int k, int z )
{
    if ( sum > T )
    {
        Z = z;
        T = sum;
        K = k;
    }
    else
        if ( sum == T )
        {
            if ( k < K )
            {
                Z = z;
                K = k;
            }
        }
}

int main()
{
    ifstream in("cri.in");
    ofstream out("cri.out");

    ios_base::sync_with_stdio( false );

    in >> N >> M >> X >> Y;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            in >> C[i][j];

    int sum, k, minim, dx, dy;

    ///---------------------------------------------------
    dx = X; dy = Y;
    sum = 0; k = dx * dy; minim = 1e9;

    for ( int i = 1, l = 1; i <= X; ++i, l++ )
        for ( int j = 1, c = 1; j <= Y; ++j, c++ )
        {
            sum += C[i][j];

            if ( ( l + c ) % 2 == 1 )
                minim = min( minim, C[i][j] );
        }

    if ( dx % 2 == 0 && dy % 2 == 0 )
    {
        k--;
        sum -= minim;
    }

    update( sum, k, 1 );

    ///---------------------------------------------------
    dx = X; dy = ( M - Y + 1 );
    sum = 0; k = dx * dy; minim = 1e9;

    for ( int i = 1, l = 1; i <= X; ++i, l++ )
        for ( int j = M, c = 1; j >= Y; --j, c++ )
        {
            sum += C[i][j];

            if ( ( l + c ) % 2 == 1 )
                minim = min( minim, C[i][j] );
        }

    if ( dx % 2 == 0 && dy % 2 == 0 )
    {
        k--;
        sum -= minim;
    }

    update( sum, k, 2 );

    ///---------------------------------------------------
    dx = ( N - X + 1 ); dy = Y;
    sum = 0; k = dx * dy; minim = 1e9;

    for ( int i = N, l = 1; i >= X; i--, l++)
        for ( int j = 1, c = 1; j <= Y; ++j, c++ )
        {
            sum += C[i][j];

            if ( ( l + c ) % 2 == 1 )
                minim = min( minim, C[i][j] );
        }

    if ( dx % 2 == 0 && dy % 2 == 0 )
    {
        k--;
        sum -= minim;
    }

    update( sum, k, 3 );

    ///---------------------------------------------------
    dx = ( N - X + 1 ); dy = ( M - Y + 1 );
    sum = 0; k = dx * dy; minim = 1e9;

    for ( int i = N, l = 1; i >= X; i--, l++ )
        for ( int j = M, c = 1; j >= Y; --j, c++ )
        {
            sum += C[i][j];

            if ( ( l + c ) % 2 == 1 )
                minim = min( minim, C[i][j] );
        }

    if ( dx % 2 == 0 && dy % 2 == 0 )
    {
        k--;
        sum -= minim;
    }

    update( sum, k, 4 );

    out << Z << " " << T << " " << K << "\n";

    return 0;
}
