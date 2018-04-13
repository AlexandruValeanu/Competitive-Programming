#include <bits/stdc++.h>

using namespace std;

template <size_t Rows, size_t Cols, typename Type = unsigned, unsigned MOD = 0>
class Matrix
{
public:

    Matrix();
    Matrix(const Type& value);
    Matrix(const Matrix& mat);

    Type& at(size_t row, size_t col);
    const Type& at(size_t row, size_t col) const;

    Type mod(long long) const;

    size_t numberRows() const;
    size_t numberCols() const;
    size_t size() const;

    Matrix& operator = (const Matrix &mat);
    Matrix& operator += (const Matrix &mat);
    Matrix& operator -= (const Matrix &mat);
    Matrix& operator *= (const Type& scalar);
    Matrix& operator /= (const Type& scalar);    /// not working if MOD > 0

    class MutableReference;
    class ImmutableReference;
    MutableReference operator[] (size_t row);
    ImmutableReference operator[] (size_t row) const;

    friend ostream& operator << (ostream& stream, const Matrix& mat)
    {
        for ( size_t i = 0; i < mat.numberRows(); ++i )
        {
            for ( size_t j = 0; j < mat.numberCols(); ++j )
            {
                stream << mat.at( i, j ) << " ";
            }

            stream << "\n";
        }

        return stream;
    }

private:

    Type A[Rows * Cols];
};

///----------------------------------------------------------------------------------------------------

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator + (const Matrix <N, M, T, MOD> &st,
                                        const Matrix <N, M, T, MOD> &dr );

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator - (const Matrix <N, M, T, MOD> &st,
                                        const Matrix <N, M, T, MOD> &dr );

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator * (const Matrix <N, M, T, MOD> &st,
                                        const T& scalar);

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator * (const T& scalar,
                                        const Matrix <N, M, T, MOD> &st);

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator / (const Matrix <N, M, T, MOD> &st,
                                        const T& scalar);

///----------------------------------------------------------------------------------------------------

template <size_t N, typename T, unsigned MOD>
Matrix <N, N, T, MOD> Identity();

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <M, N> Transpose(const Matrix <N, M> &st);

template <size_t N, typename T, unsigned MOD>
const T Trace(const Matrix <N, N, T, MOD> &st );

template <size_t N, typename T, unsigned MOD>
const Matrix <N, N, T, MOD> power(const Matrix <N, N, T, MOD> &st, const size_t &pow );

///----------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------

template <size_t N, size_t M, typename T, unsigned MOD>
Matrix <N, M, T, MOD>::Matrix()
{
    fill( A, A + N * M, T() );
}

template <size_t N, size_t M, typename T, unsigned MOD>
Matrix <N, M, T, MOD>::Matrix(const T& value)
{
    fill( A, A + N * M, value );
}

template <size_t N, size_t M, typename T, unsigned MOD>
Matrix <N, M, T, MOD>::Matrix(const Matrix <N, M, T, MOD> &st)
{
    for ( size_t i = 0; i < st.size(); ++i )
        this->A[i] = st.A[i];
}

template <size_t N, size_t M, typename T, unsigned MOD>
T Matrix <N, M, T, MOD>::mod(long long value) const
{
    if ( MOD == 0 )
        return value;
    else
        return value % MOD;
}

template <size_t N, size_t M, typename T, unsigned MOD>
size_t Matrix <N, M, T, MOD>::numberRows() const
{
    return N;
}

template <size_t N, size_t M, typename T, unsigned MOD>
size_t Matrix <N, M, T, MOD>::numberCols() const
{
    return M;
}

template <size_t N, size_t M, typename T, unsigned MOD>
size_t Matrix <N, M, T, MOD>::size() const
{
    return N * M;
}

template <size_t N, size_t M, typename T, unsigned MOD>
T& Matrix <N, M, T, MOD>::at(size_t row, size_t col)
{
    return A[row * M + col];
}

template <size_t N, size_t M, typename T, unsigned MOD>
const T& Matrix <N, M, T, MOD>::at(size_t row, size_t col) const
{
    return A[row * M + col];
}

///----------------------------------------------------------------------------------------------------

template <size_t N, size_t M, typename T, unsigned MOD>
class Matrix <N, M, T, MOD>::MutableReference
{
public:

    T& operator [] (size_t col)
    {
        return parent->at( row, col );
    }
private:

    MutableReference(Matrix* owner, size_t ro) : parent(owner), row(ro) {}
    friend class Matrix;

    Matrix* const parent;
    const size_t row;
};

template <size_t N, size_t M, typename T, unsigned MOD>
class Matrix <N, M, T, MOD>::ImmutableReference
{
public:

    const T& operator [] (size_t col) const
    {
        return parent->at( row, col );
    }
private:

    ImmutableReference(const Matrix* owner, size_t ro) : parent(owner), row(ro) {}
    friend class Matrix;

    const Matrix* const parent;
    const size_t row;
};

template <size_t N, size_t M, typename T, unsigned MOD>
typename Matrix <N, M, T, MOD>::MutableReference Matrix <N, M, T, MOD>::operator [] (size_t row)
{
    return MutableReference(this, row);
}

template <size_t N, size_t M, typename T, unsigned MOD>
typename Matrix <N, M, T, MOD>::ImmutableReference Matrix <N, M, T, MOD>::operator [] (size_t row) const
{
    return ImmutableReference(this, row);
}

///----------------------------------------------------------------------------------------------------

template <size_t N, size_t M, typename T, unsigned MOD>
Matrix <N, M, T, MOD>& Matrix <N, M, T, MOD>::operator = (const Matrix <N, M, T, MOD> &mat)
{
    for ( size_t i = 0; i < mat.size(); ++i )
        this->A[i] = mat.A[i];

    return *this;
}

template <size_t N, size_t M, typename T, unsigned MOD>
Matrix <N, M, T, MOD>& Matrix <N, M, T, MOD>::operator += (const Matrix <N, M, T, MOD> &mat)
{
    for ( size_t i = 0; i < this->size(); ++i )
    {
        this->A[i] = mod( this->A[i] + mat.A[i] );
    }

    return *this;
}

template <size_t N, size_t M, typename T, unsigned MOD>
Matrix <N, M, T, MOD>& Matrix <N, M, T, MOD>::operator -= (const Matrix <N, M, T, MOD> &mat)
{
    for ( size_t i = 0; i < this->size(); ++i )
    {
        this->A[i] = mod( this->A[i] - mat.A[i] + MOD );
    }

    return *this;
}

template <size_t N, size_t M, typename T, unsigned MOD>
Matrix <N, M, T, MOD>& Matrix <N, M, T, MOD>::operator *= (const T &scalar)
{
    for ( size_t i = 0; i < this->size(); ++i )
    {
        this->A[i] = mod( 1LL * this->A[i] * scalar );
    }

    return *this;
}

template <size_t N, size_t M, typename T, unsigned MOD>
Matrix <N, M, T, MOD>& Matrix <N, M, T, MOD>::operator /= (const T &scalar)
{
    for ( size_t i = 0; i < this->size(); ++i )
    {
        this->A[i] = mod( this->A[i] / scalar );
    }

    return *this;
}

///----------------------------------------------------------------------------------------------------

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator + (const Matrix <N, M, T, MOD> &st,
                                        const Matrix <N, M, T, MOD> &dr )
{
    return Matrix <N, M, T, MOD>(st) += dr;
}

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator - (const Matrix <N, M, T, MOD> &st,
                                        const Matrix <N, M, T, MOD> &dr )
{
    return Matrix <N, M, T, MOD>(st) -= dr;
}

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator * (const Matrix <N, M, T, MOD> &st,
                                        const T& scalar)
{
     return Matrix <N, M, T, MOD>(st) *= scalar;
}

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator * (const T& scalar,
                                        const Matrix <N, M, T, MOD> &st)
{
    return Matrix <N, M, T, MOD>(st) *= scalar;
}

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <N, M, T, MOD> operator / (const Matrix <N, M, T, MOD> &st,
                                        const T& scalar)
{
    return Matrix <N, M, T, MOD>(st) /= scalar;
}

///----------------------------------------------------------------------------------------------------

template <size_t N, size_t M, size_t P, typename T, unsigned MOD>
const Matrix <N, P, T, MOD> operator * (const Matrix <N, M, T, MOD>& st,
                                        const Matrix <M, P, T, MOD>& dr);

template <size_t N, typename T, unsigned MOD>
Matrix <N, N, T>& operator *= (Matrix <N, N, T, MOD> &lhs,
                              const Matrix <N, N, T, MOD> &rhs);

///----------------------------------------------------------------------------------------------------

template <size_t N, size_t M, size_t P, typename T, unsigned MOD>
const Matrix <N, P, T, MOD> operator * (const Matrix <N, M, T, MOD>& st,
                                        const Matrix <M, P, T, MOD>& dr)
{
    Matrix <N, P, T, MOD> C;

    for ( size_t row = 0; row < C.numberRows(); ++row )
        for ( size_t col = 0; col < C.numberCols(); ++col )
            for ( size_t i = 0; i < M; ++i )
                C[row][col]= C.mod( C[row][col] + 1LL * st[row][i] * dr[i][col] );

    return C;
}

template <size_t M, typename T, unsigned MOD>
Matrix<M, M, T, MOD>& operator *= (Matrix<M, M, T, MOD>& st,
                                   const Matrix<M, M, T, MOD>& dr)
{
    return st = st * dr;
}

///----------------------------------------------------------------------------------------------------

template <size_t N, typename T, unsigned MOD>
Matrix <N, N, T, MOD> Identity()
{
    Matrix <N, N, T, MOD> result;

    for ( size_t i = 0; i < N; ++i )
        result[i][i] = T(1);

    return result;
}

template <size_t N, size_t M, typename T, unsigned MOD>
const Matrix <M, N, T, MOD> Transpose(const Matrix <N, M, T, MOD> &st)
{
    Matrix <M, N, T, MOD> result;

    for ( size_t i = 0; i < N; ++i )
        for ( size_t j = 0; j < M; ++j )
            result[j][i] = st[i][j];

    return result;
}

template <size_t N, typename T, unsigned MOD>
const T Trace(const Matrix <N, N, T, MOD> &st )
{
    T value = T(0);

    for ( size_t i = 0; i < N; ++i )
        value = st.mod( value + st.at( i, i ) );

    return value;
}

///----------------------------------------------------------------------------------------------------

template <size_t N, typename T, unsigned MOD>
const Matrix <N, N, T, MOD> power(const Matrix <N, N, T, MOD> &st, const size_t &pow )
{
    if ( pow == T(0) )
        return Identity<N, T, MOD>();

    if (pow == T(1))
        return st;

    Matrix <N, N, T, MOD> result = Identity<N, T, MOD>();
    Matrix <N, N, T, MOD> a = st;

    for ( size_t i = 0; ( 1 << i ) <= pow; ++i )
    {
        if (pow & ( 1 << i ))
            result = result * a;

        a = a * a;
    }

    return result;
}

///----------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------

int main()
{
    return 0;
}
