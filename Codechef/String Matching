#include <bits/stdc++.h>

using namespace std;

struct Complex
{
    double re, im;

    Complex( double a = 0.0, double b = 0.0 ): re( a ), im( b )
    {
    }

    double& real()
    {
        return re;
    }

    double& imag()
    {
        return im;
    }

    void conj()
    {
        this->im = -this->im;
    }

    void polar( const double rho, const double theta )
    {
        this->re = rho * cos( theta );
        this->im = rho * sin( theta );
    }

    double abs()
    {
        return sqrt( this->re * this->re + this->im * this->im );
    }

    Complex& operator += ( const Complex& c )
    {
        this->re += c.re;
        this->im += c.im;

        return *this;
    }

    Complex operator + ( const Complex& c ) const
    {
        Complex aux = *this;
        aux += c;

        return aux;
    }

    Complex& operator -= ( const Complex& c )
    {
        this->re -= c.re;
        this->im -= c.im;

        return *this;
    }

    Complex operator - ( const Complex& c ) const
    {
        Complex aux = *this;
        aux -= c;

        return aux;
    }

    Complex& operator *= ( const Complex& c )
    {
        double auxRe = this->re * c.re - this->im * c.im;
        double auxIm = this->re * c.im + this->im * c.re;

        this->re = auxRe;
        this->im = auxIm;

        return *this;
    }

    Complex operator * ( const Complex& c ) const
    {
        Complex aux = *this;
        aux *= c;

        return aux;
    }

    Complex& operator /= ( const Complex& c )
    {
        double a = this->re * c.re + this->im * c.im;
        double b = this->im * c.re - this->re * c.im;
        double d = c.re * c.re + c.im * c.im;

        this->re = a / d;
        this->im = b / d;

        return *this;
    }

    Complex operator / ( const Complex& c ) const
    {
        Complex aux = *this;
        aux /= c;

        return aux;
    }

    friend istream& operator >> ( istream& stream, Complex& C )
    {
        stream >> C.re >> C.im;
        return stream;
    }

    friend ostream& operator << ( ostream& stream, const Complex& C )
    {
        stream << C.re << " " << C.im;
        return stream;
    }
};

namespace FFT
{
    const int Nmax = ( 1 << 18 );
    const int CUT_OFF = 400000;
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

        for ( int i = 1; i <= expTwo; ++i )
        {
            Complex w;
            w.polar( 1.0, inverse * 2.0 * PI / ( 1 << i ) );
            Complex wk = Complex( 1, 0 );
            int step = 1 << ( i - 1 );

            for ( int k = 0; k < step; ++k )
            {
                for ( int j = 0; j < powerOfTwo; j += 2 * step )
                {
                    Complex a = coef[j | k];
                    Complex b = wk * coef[j | k | step];

                    coef[j | k]        = a + b;
                    coef[j | k | step] = a - b;
                }

                wk = wk * w;
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
        if ( 1LL * lgA * lgB <= 0 )
        {
            lgC = lgA + lgB - 1;

            clearArray( c, lgC );

            for ( int i = 0; i < lgA; ++i )
                for ( int j = 0; j < lgB; ++j )
                    c[i + j] += a[i] * b[j];
        }
        else
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

            while ( lgC >= 2 && C[lgC - 1].abs() < EPS ) lgC--;

            for ( int i = 0; i < lgC; ++i )
                c[i] = C[i];
        }
    }
}

Complex A[FFT::Nmax], B[FFT::Nmax], C[FFT::Nmax];
char strA[FFT::Nmax], strB[FFT::Nmax];
int n, m, p, K;

int main()
{
    ios_base::sync_with_stdio( false );

    cin >> strA;

    n = strlen( strA );

    for ( int i = 0; i < n; ++i )
    {
        if ( strA[i] == '1' )
            A[i] = 1;
        else
            A[i] = -1;
    }

    cin >> K;

    while ( K-- )
    {
        cin >> strB;

        m = strlen( strB );

        reverse( strB, strB + m );

        for ( int i = 0; i < m; ++i )
        {
            if ( strB[i] == '1' )
                B[i] = 1;
            else
                B[i] = -1;
        }

        FFT::convolution( A, B, C, n, m, p );

        long long sol = 0;

        for ( int i = m - 1; i < n; ++i )
            sol = ( 1LL * sol * 100001 + (long long)( ( m - round( C[i].real() ) ) / 2 ) ) % 1000000007;

        cout << sol << "\n";
    }

    return 0;
}
