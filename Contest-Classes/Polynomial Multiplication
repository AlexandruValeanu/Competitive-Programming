#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (1 << 20);

complex<double> A[MAX_N], B[MAX_N], C[MAX_N];
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

void fft(complex<double> A[], int N, int inverse)
{
    for (int i = 0; i < N; ++i)
    {
        int j = reverse_bits(i);

        if (i < j)
            swap(A[i], A[j]);
    }

    for (int length = 2; length <= N; length *= 2)
    {
        complex<double> root = polar(1.0, 2.0 * M_PI * (1.0 * inverse) / length);

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
            A[i] /= (1.0 * N);
    }
}

int main()
{
   // ifstream cin("data.in");

    int T;
    cin >> T;

    while (T--)
    {
        int auxN;
        cin >> auxN;
        auxN++;

        for (int i = auxN - 1; i >= 0; --i)
        {
            double value;
            cin >> value;

            A[i] = complex<double>(value, 0);
        }

        for (int i = auxN - 1; i >= 0; --i)
        {
            double value;
            cin >> value;

            B[i] = complex<double>(value, 0);
        }

        EXP = 0;

        while ((1 << EXP) < 2 * auxN)
            EXP++;

        N = (1 << EXP);

        for (int i = auxN; i < N; ++i)
        {
            A[i] = 0;
            B[i] = 0;
        }

        fft(A, N, 1);
        fft(B, N, 1);

        for (int i = 0; i < N; ++i)
        {
            C[i] = A[i] * B[i];
        }

        fft(C, N, -1);

        int ind = N - 1;

        for (int i = 2 * auxN - 2; i >= 0; i--)
            cout << (int)(C[i].real() + 0.5) << " ";

        cout << "\n";
    }

    return 0;
}
