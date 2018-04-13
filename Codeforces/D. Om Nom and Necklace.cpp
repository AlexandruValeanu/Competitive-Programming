#include <bits/stdc++.h>

using namespace std;

vector<int> Z_Algorithm(const string &str)
{
    const int N = str.size();
    vector<int> Z(N, 0);

    int L = 0, R = 0;

    for (int i = 1; i < N; ++i)
    {
        if (i <= R)
            Z[i] = min(R - i + 1, Z[i - L]);

        while (i + Z[i] < N && str[ Z[i] ] == str[ i + Z[i] ])
            Z[i]++;

        if (i + Z[i] >= R)
        {
            L = i;
            R = i + Z[i] - 1;
        }
    }

    return Z;
}

int main()
{
    ///ifstream cin("data.in");

    int N, K;
    string str;

    cin >> N >> K >> str;

    vector<int> z = Z_Algorithm(str);
    vector<int> cnt(N, 0);

    for (int prefLen = 1; K * prefLen <= N; ++prefLen)
    {
        int nr = z[prefLen] / prefLen + 1;

        if (nr < K)
            continue;

        int lenA = min(prefLen, z[K * prefLen]);

        cnt[K * prefLen - 1]++;

        if (K * prefLen + lenA < N)
            cnt[K * prefLen + lenA]--;
    }

    for (int i = 0; i < N; ++i)
    {
        if (i)
            cnt[i] += cnt[i - 1];

        if (cnt[i])
            cout << "1";
        else
            cout << "0";
    }

    cout << "\n";

    return 0;
}
