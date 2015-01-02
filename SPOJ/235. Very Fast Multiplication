#include <bits/stdc++.h>

using namespace std;

typedef complex<double> Complex;

namespace FFT
{
    const int Nmax = ( 1 << 20 );
    const double PI = M_PI;
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

    void padd( Complex a[], int n )
    {
        for ( int i = n; i < powerOfTwo; ++i )
            a[i] = 0;
    }

    void clearArray( Complex a[], int n )
    {
        for ( int i = 0; i < n; ++i )
            a[i] = 0;
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
            Complex wk;

            for ( int i = 0; i < powerOfTwo; i += 2 * step )
            {
                wk = Complex( 1, 0 );

                for ( int j = 0; j < step; ++j )
                {
                    Complex x = coef[i + j];
                    Complex y = coef[i + j + step] * wk;

                    coef[i + j]        = x + y;
                    coef[i + j + step] = x - y;

                    wk *= root;
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
        for ( expTwo = 1; ( 1 << expTwo ) < 2 * max( lgA, lgB ); ++expTwo );

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

       /// while ( lgC >= 2 && abs( C[lgC - 1] ) < EPS ) lgC--;

        for ( int i = 0; i < lgC; ++i )
            c[i] = C[i];
    }
}

int T, lgA, lgB, lgC;
char a[FFT::Nmax], b[FFT::Nmax];
Complex A[FFT::Nmax], B[FFT::Nmax], C[FFT::Nmax];

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio( false );

    cin >> T;

    while ( T-- )
    {
        cin >> a >> b;

        lgA = strlen( a );
        lgB = strlen( b );

        for ( int i = 0; i < lgA; ++i )
            A[i] = Complex( a[lgA - i - 1] - '0', 0 );

        for ( int i = 0; i < lgB; ++i )
            B[i] = Complex( b[lgB - i - 1] - '0', 0 );

        FFT::convolution( A, B, C, lgA, lgB, lgC );

        int carry = 0;

        for ( int i = 0; i < lgC; ++i )
        {
            int c = (int)( C[i].real() + 0.5 );

            c += carry;
            carry = c / 10;
            c %= 10;

            C[i] = Complex( c, 0 );
        }

        int valid = 0;

        for ( int i = lgC - 1; i >= 0; i-- )
        {
            int c = (int)C[i].real();

            if ( c || i == 0 )
                valid = 1;

            if ( valid )
                cout << c;
        }

        cout << "\n";
    }

    return 0;
}
