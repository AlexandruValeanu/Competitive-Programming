#include <bits/stdc++.h>

using namespace std;

typedef complex<double> Complex;

namespace FFT
{
    const int Nmax = ( 1 << 18 );
    const double PI = 3.141592653589793238460;
    const double EPS = 1e-10;

    Complex A[Nmax], B[Nmax], C[Nmax];

    int powerOfTwo, expTwo;

    int reverseBits( int x )
    {
        int sol = 0;

        for ( int i = 0; i < expTwo; ++i )
        {
            sol <<= 1;
            sol |= x & 1;
            x >>= 1;
        }

        return sol;
    }

    void clearArray( Complex x[], int n )
    {
        for ( int i = 0; i < n; ++i )
            x[i] = 0;
    }

    void padd( Complex x[], int n )
    {
        for ( int i = n; i < powerOfTwo; ++i )
            x[i] = 0;
    }

    void fft( Complex coef[], int inverse )
    {
        for ( int i = 0; i < powerOfTwo; ++i )
        {
            int j = reverseBits( i );

            if ( i < j )
                swap( coef[i], coef[j] );
        }

        for ( int len = 2; len <= powerOfTwo; len *= 2 )
        {
            int step = len / 2;

            Complex root = polar( 1.0, inverse * 2.0 * PI / len );
            Complex wk = Complex( 1, 0 );

            for ( int i = 0; i < powerOfTwo; i += 2 * step )
            {
                wk = Complex( 1, 0 );

                for ( int j = 0; j < step; ++j )
                {
                    Complex x = coef[i + j], y = coef[i + j + step] * wk;

                    coef[i + j] = x + y;
                    coef[i + j + step] = x - y;

                    wk = wk * root;
                }
            }
        }

        if ( inverse == -1 )
        {
            for ( int i = 0; i < powerOfTwo; ++i )
                coef[i] /= (double)powerOfTwo;
        }
    }

    void convolution( Complex a[], Complex b[], Complex c[], int lgA, int lgB, int &lgC )
    {
        for ( expTwo = 0; ( 1 << expTwo ) < 2 * max( lgA, lgB ); ++expTwo );

        powerOfTwo = ( 1 << expTwo );

        for ( int i = 0; i < lgA; ++i )
            A[i] = a[i];

        for ( int i = 0; i < lgB; ++i )
            B[i] = b[i];

        padd( A, lgA );
        padd( B, lgB );

        fft( A, 1 );
        fft( B, 1 );

        for ( int i = 0; i < powerOfTwo; ++i )
            C[i] = A[i] * B[i];

        fft( C, -1 );

        lgC = powerOfTwo;

        while ( lgC >= 2 && abs( C[lgC - 1] ) < EPS ) lgC--;

        for ( int i = 0; i < lgC; ++i )
            c[i] = C[i];
    }
}

int main()
{
    return 0;
}
