#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("latin.in");
    ofstream out("latin.out");

    int N, L;
    in >> N;

    L = (1 << N);

    for (int i = 1; i <= L; ++i)
    {
        int aux = i;

        for (int k = 1; k <= L; ++k)
        {
            out << aux << " ";

            if ( ++aux > L )
                aux -= L;
        }

        out << "\n";
    }

    return 0;
}
