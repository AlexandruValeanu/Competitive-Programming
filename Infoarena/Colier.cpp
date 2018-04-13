#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("colier.in");
    ofstream out("colier.out");

    ios_base::sync_with_stdio(false);

    int T;
    in >> T;

    while (T--)
    {
        int N, nrZero = 0, nrUnu = 0;
        char ch;

        in >> N;

        for (int k = 0; k < N; ++k)
        {
            in >> ch;

            int col = ch - '0';

            if (col == 0)
                nrZero++;
            else
                nrUnu++;
        }

        if (nrUnu == 0)
        {
            out << "NU\n";
            continue;
        }

        if (nrZero == 0)
        {
            if (N == 1)
                out << "DA\n";
            else
                out << "NU\n";

            continue;
        }

        if (nrZero & 1)
            out << "DA\n";
        else
            out << "NU\n";
    }

    return 0;
}
