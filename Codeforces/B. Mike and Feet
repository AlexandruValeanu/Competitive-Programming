#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 1;

int st[MAX_N], dr[MAX_N];
int len[MAX_N];
int A[MAX_N];

int stiva[MAX_N], top;

int N;

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    for (int i = 1; i <= N; ++i)
    {
        while (top >= 1 && A[ stiva[top] ] >= A[i])
            top--;

        if (top == 0)
            st[i] = 1;
        else
            st[i] = stiva[top] + 1;

        stiva[ ++top ] = i;
    }

    top = 0;

    for (int i = N; i >= 1; i--)
    {
        while (top >= 1 && A[ stiva[top] ] >= A[i])
            top--;

        if (top == 0)
            dr[i] = N;
        else
            dr[i] = stiva[top] - 1;

        stiva[ ++top ] = i;
    }

    for (int i = 1; i <= N; ++i)
    {
        int l = dr[i] - st[i] + 1;

        len[l] = max(len[l], A[i]);
    }

    for (int i = N; i >= 1; --i)
        len[i] = max(len[i], len[i + 1]);

    for (int i = 1; i <= N; ++i)
        cout << len[i] << " ";

    return 0;
}
