#include <bits/stdc++.h>

using namespace std;

int Z_Algorithm(const vector<int> &A, const vector<int> &B)
{
    vector<int> str;

    for (int i = 0; i < A.size(); ++i)
        str.push_back(A[i]);

    str.push_back(-2e9);

    for (int i = 0; i < B.size(); ++i)
        str.push_back(B[i]);

    const int N = str.size();
    vector<int> z(N, 0);

    int L = 0, R = 0;

    for (int i = 1; i < N; ++i)
    {
        if (i <= R)
            z[i] = min(R - i + 1, z[i - L]);

        while (i + z[i] < N && str[ z[i] ] == str[ i + z[i] ])
            z[i]++;

        if (i + z[i] > R)
        {
            R = i + z[i] - 1;
            L = i;
        }
    }

    int total = 0;

    for (int i = A.size() + 1; i < z.size(); ++i)
        if (z[i] == A.size())
            total++;

    return total;
}

int main()
{
    ///ifstream cin("data.in");

    int N, M;
    cin >> N >> M;

    if (M == 1)
    {
        cout << N << "\n";
        return 0;
    }

    vector<int> A(N, 0), B(M, 0);
    vector<int> dA(N, 0), dB(M, 0);

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < M; ++i)
        cin >> B[i];

    for (int i = 0; i < N - 1; ++i)
        dA[i] = A[i + 1] - A[i];

    for (int i = 0; i < M - 1; ++i)
        dB[i] = B[i + 1] - B[i];

    dA.pop_back();
    dB.pop_back();

    cout << Z_Algorithm(dB, dA) << "\n";

    return 0;
}
