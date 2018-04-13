#include <bits/stdc++.h>

using namespace std;

class Matrix
{
public:

    int N, M;
    vector<int> a;

    Matrix() : N(0), M(0), a(vector<int>()) {
    }

    Matrix& operator = (const Matrix &B)
    {
        this->alloc(B.N, B.M);

        for (int i = 0; i < this->N * this->M; ++i)
            this->a[i] = B.a[i];

        return *this;
    }

    void alloc(int n, int m)
    {
        this->N = n;
        this->M = m;

        a = vector<int>(this->N * this->M, 0);
    }

    int at(int i, int j) const
    {
        return this->a[i * this->M + j];
    }

    int& at(int i, int j)
    {
        return this->a[i * this->M + j];
    }

    Matrix operator + (const Matrix &B) const
    {
        Matrix A;
        A.alloc(this->N, this->M);

        for (int i = 0; i < A.N * A.M; ++i)
            A.a[i] = this->a[i] + B.a[i];

        return A;
    }

    Matrix operator - (const Matrix &B) const
    {
        Matrix A;
        A.alloc(this->N, this->M);

        for (int i = 0; i < A.N * A.M; ++i)
            A.a[i] = this->a[i] - B.a[i];

        return A;
    }

    friend ostream& operator << (ostream& stream, const Matrix &A)
    {
        for (int i = 0; i < A.N; ++i)
        {
            for (int j = 0; j < A.M; ++j)
                stream << A.at(i, j) << ' ';

            stream << '\n';
        }

        return stream;
    }
};

Matrix bruteForceMultiplication(const Matrix &A, const Matrix &B)
{
    Matrix C;
    C.alloc(A.N, B.M);

    for (int k = 0; k < A.M; ++k)
        for (int i = 0; i < A.N; ++i)
            for (int j = 0; j < B.M; ++j)
                C.at(i, j) += A.at(i, k) * B.at(k, j);

    return C;
}

Matrix strassenMultiplication(const Matrix &L, const Matrix &R)
{
    int N = L.N;

    if (N <= 64)
        return bruteForceMultiplication(L, R);

    Matrix A[2][2], B[2][2], C[2][2];

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        {
            A[i][j].alloc(N / 2, N / 2);
            B[i][j].alloc(N / 2, N / 2);
            C[i][j].alloc(N / 2, N / 2);

            for (int x = 0; x < N / 2; ++x)
                for (int y = 0; y < N / 2; ++y)
                {
                    A[i][j].at(x, y) = L.at(i * N / 2 + x, j * N / 2 + y);
                    B[i][j].at(x, y) = R.at(i * N / 2 + x, j * N / 2 + y);
                }
        }

    Matrix M1 = strassenMultiplication(A[0][0] + A[1][1], B[0][0] + B[1][1]),
           M2 = strassenMultiplication(A[1][0] + A[1][1], B[0][0]),
           M3 = strassenMultiplication(A[0][0], B[0][1] - B[1][1]),
           M4 = strassenMultiplication(A[1][1], B[1][0] - B[0][0]),
           M5 = strassenMultiplication(A[0][0] + A[0][1], B[1][1]),
           M6 = strassenMultiplication(A[1][0] - A[0][0], B[0][0] + B[0][1]),
           M7 = strassenMultiplication(A[0][1] - A[1][1], B[1][0] + B[1][1]);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;

    Matrix solution;
    solution.alloc(N, N);

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int x = 0; x < N / 2; ++x)
                for (int y = 0; y < N / 2; ++y)
                    solution.at(i * N / 2 + x, j * N / 2 + y) = C[i][j].at(x, y);

    return solution;
}

int main()
{

}
