#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359

const int MAX_EXP = 19;
const int MAX_N = (1 << MAX_EXP);

complex<double> A[MAX_N];
int N, EXP;

int reverse_bits(int x)
{
    int rev_x = 0;

    for (int i = 0; i < EXP; ++i)
    {
        bool bit = x & (1 << i);

        rev_x <<= 1;
        rev_x |= bit;
    }

    return rev_x;
}

void fft(complex<double> A[], int inverse)
{
    for (int i = 0; i < N; ++i)
    {
        int j = reverse_bits(i);

        if (i < j)
            swap(A[i], A[j]);
    }

    for (int length = 2; length <= N; length *= 2)
    {
        complex<double> root = polar(1.0, 2.0 * PI * inverse / length);

        for (int start = 0; start < N; start += length)
        {
            complex<double> wk = 1.0;

            for (int i = 0; i < length / 2; ++i)
            {
                complex<double> u = A[start + i];
                complex<double> v = A[start + i + length / 2];

                A[start + i] = u + wk * v;
                A[start + i + length / 2] = u - wk * v;

                wk *= root;
            }
        }
    }

    if (inverse == -1)
    {
        for (int i = 0; i < N; ++i)
            A[i] /= N;
    }
}

int main()
{
    ifstream in("fft.in");
    ofstream out("fft.out");

    int tmpN;
    in >> tmpN;

    for (int i = 0; i < tmpN; ++i)
    {
        double a;
        in >> a;

        A[i] = complex<double>(a, 0);
    }

    EXP = 0;

    while ((1 << EXP) < tmpN)
        EXP++;

    N = (1 << EXP);

    for (int i = tmpN; i < N; ++i)
        A[i] = 0;

    fft(A, 1);

    for (int i = 0; i < N; ++i)
        out << fixed << setprecision(4) << A[i].real() << " ";

    out << "\n";

    return 0;
}
