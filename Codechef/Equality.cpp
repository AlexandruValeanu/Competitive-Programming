#include <bits/stdc++.h>

using namespace std;

const int Nmax = 50000 + 1;
long long A[Nmax];
int N, T;

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> T;

    while (T--)
    {
        cin >> N;
        long long sum = 0;

        for (int i = 1; i <= N; ++i)
        {
            cin >> A[i];
            sum += (long long)A[i];
        }

        sum /= (N - 1);

        for (int i = 1; i <= N; ++i)
            cout << sum - (long long)A[i] << " ";

        cout << "\n";
    }


    return 0;
}
