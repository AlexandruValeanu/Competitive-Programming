#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100;

int A[Nmax], B[Nmax];
int T, N, M, K;

int main()
{
   // ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> T;

    while (T--)
    {
        cin >> N >> M >> K;

        for (int i = 0; i < M; ++i)
            cin >> A[i];

        for (int i = 0; i < K; ++i)
            cin >> B[i];

        sort(A, A + M);
        sort(B, B + K);

        int s1 = 0, s2 = 0;

        for (int i = 0; i < M; ++i)
            s1 += binary_search(B, B + K, A[i]);

        for (int i = 1; i <= N; ++i)
        {
            int a = binary_search(A, A + M, i);
            int b = binary_search(B, B + K, i);

            if (!a && !b)
                s2++;
        }

        cout << s1 << " " << s2 << "\n";
    }

    return 0;
}
