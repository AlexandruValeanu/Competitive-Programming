#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 1;

int stiva[Nmax], top;
int maxim;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    cin >> N;

    for (int i = 0, v; i < N; ++i)
    {
        cin >> v;

        while (top > 0)
        {
            maxim = max(maxim, stiva[top] ^ v);

            if (stiva[top] > v)
                break;
            else
                top--;
        }

        stiva[ ++top ] = v;
    }

    cout << maxim << "\n";

    return 0;
}
