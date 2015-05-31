#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 1;
const int MOD = 1e9 + 7;

int match[MAX_N];
bool used[MAX_N];

vector<int> Z_Algorithm(const string &str)
{
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
            L = i;
            R = i + z[i] - 1;
        }
    }

    return z;
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    string p;
    cin >> p;

    for (int i = 1; i <= M; ++i)
    {
        cin >> match[i];
        used[ match[i] ] = 1;
    }

    int pos = 0;
    string str = "";

    for (int i = 1; i <= N; ++i)
    {
        if (used[i])
            pos = i;

        if (pos == 0)
            str.push_back('?');
        else
        {
            if (i - pos < p.size())
                str.push_back(p[i - pos]);
            else
                str.push_back('?');
        }
    }

    vector<int> z = Z_Algorithm(p + "#" + str);

    for (int i = 1; i <= M; ++i)
    {
        if (z[ p.size() + match[i] ] != p.size())
        {
            cout << "0\n";
            return 0;
        }
    }

    int sol = 1;

    for (auto c: str)
        if (c == '?')
            sol = (1LL * sol * 26) % MOD;

    cout << sol << "\n";

    return 0;
}
