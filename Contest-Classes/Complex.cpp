#include <bits/stdc++.h>

using namespace std;

template <typename dataType>
class Complex
{
public:

    dataType re, im;

    Complex() : re(0), im(0) {
    }

    Complex (const dataType& a, const dataType& b) : re(a), im(b) {
    }

    Complex(const complex<dataType>& c) : re(c.real()), im(c.imag()) {
    }

    Complex& operator = (const complex<dataType>& c)
    {
        this->re = c.real();
        this->im = c.imag();

        return *this;
    }

    dataType real() const
    {
        return this->re;
    }

    dataType imag() const
    {
        return this->im;
    }

    void polar(const dataType& rho, const dataType& theta = 0)
    {
        this->re = rho * cos(theta);
        this->im = rho * sin(theta);
    }

    Complex conj() const
    {
        return Complex(this->re, -this->im);
    }

    dataType norm() const
    {
        return sqrt(this->re * this->re + this->im * this->im);
    }

    dataType normSquared() const
    {
        return this->re * this->re + this->im * this->im;
    }

    Complex inverse() const
    {
        return this->conj() / this->normSquared();
    }

    ///BEGIN OPERATORS-------------------------------------------------------------
    Complex operator + (const Complex<dataType>& c) const
    {
        return Complex(this->re + c.re, this->im + c.im);
    }

    Complex& operator += (const Complex<dataType>& c)
    {
        *this = *this + c;
        return *this;
    }

    Complex operator - (const Complex<dataType>& c) const
    {
        return Complex(this->re - c.re, this->im - c.im);
    }

    Complex& operator -= (const Complex<dataType>& c)
    {
        *this = *this + c;
        return *this;
    }

    Complex operator * (const Complex<dataType>& c) const
    {
        double aux_re = this->re * c.real() - this->im * c.imag();
        double aux_im = this->re * c.imag() + this->im * c.real();

        return Complex(aux_re, aux_im);
    }

    Complex& operator *= (const Complex<dataType>& c)
    {
        *this = *this * c;
        return *this;
    }

    Complex operator * (const dataType& c) const
    {
        return Complex(this->re * c, this->im * c);
    }

    Complex& operator *= (const dataType& c)
    {
        *this = *this * c;
        return *this;
    }

    Complex operator / (const Complex<dataType>& c) const
    {
        return *this * c.inverse();
    }

    Complex& operator /= (const Complex<dataType>& c)
    {
        *this = *this / c;
        return *this;
    }

    Complex operator / (const dataType& c) const
    {
        return Complex(this->re / c, this->im / c);
    }

    Complex& operator /= (const dataType& c)
    {
        *this = *this / c;
        return *this;
    }
    ///END OPERATORS--------------------------------------------------------------------

    friend istream& operator >> (istream& stream, Complex& C)
    {
        stream >> C.re >> C.im;
        return stream;
    }

    friend ostream& operator << (ostream& stream, const Complex& C)
    {
        stream << C.re << " " << C.im;
        return stream;
    }
};

int main()
{
    return 0;
}
