#include <bits/stdc++.h>

using namespace std;

const int MAX_T = 1000000;

int v[MAX_T + 1];
int N, T;

int main()
{
    ifstream in("gardieni.in");
    ofstream out("gardieni.out");

    in >> N >> T;

    for (int i = 1; i <= T; ++i)
        v[i] = numeric_limits<int>::max();

    while (N--)
    {
        int a, b, c;
        in >> a >> b >> c;

        for (int i = a; i <= b; ++i)
            v[i] = min(v[i], c);
    }

    long long sol = 0;

    for (int i = 1; i <= T; ++i)
        sol += (long long)v[i];

    out << sol << "\n";

    return 0;
}
