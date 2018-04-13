#include <bits/stdc++.h>

using namespace std;

const int Nmax = 300 + 1;

struct Mutare
{
    char tip;
    int x, y;
};

Mutare M[2 * Nmax];
int nrMutari;

int v[Nmax];
int N;

int main()
{
    ifstream in("grozavesti.in");
    ofstream out("grozavesti.out");

    in >> N;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= N; ++j )
        {
            int a;
            in >> a;

            if ( i == j )
                v[i] = a;
        }

    for ( int i = 1; i <= N; ++i )
    {
        int best = 1e9;
        int x = 0;

        for ( int j = i + 1; j <= N; ++j )
        {
            if ( best > v[j] )
            {
                best = v[j];
                x = j;
            }
        }

        if ( best < v[i] )
        {
            swap(v[i], v[x]);

            nrMutari++;
            M[nrMutari] = {'L', i, x};
            nrMutari++;
            M[nrMutari] = {'C', i, x};
        }
    }

    out << nrMutari << "\n";

    for ( int i = 1; i <= nrMutari; ++i )
        out << M[i].tip << " " << M[i].x << " " << M[i].y << "\n";

    return 0;
}
