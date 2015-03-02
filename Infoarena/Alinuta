#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

int complement[Nmax];
int K, T, A, B;

void preproc()
{
    int ratie = 0;

    for ( int i = 0; i < Nmax; ++i )
    {
        if ( complement[i] || i + ratie >= Nmax )
            continue;

        complement[i] = i + ratie;

        if ( i + ratie < Nmax )
            complement[i + ratie] = i;

        ratie += (K + 1);
    }
}

int main()
{
    ifstream in("alinuta.in");
    ofstream out("alinuta.out");

    in >> K >> T;

    preproc();

    for ( int i = 1; i <= T; ++i )
    {
        in >> A >> B;

        if ( complement[A] == B || complement[B] == A )
            out << "B\n";
        else
            out << "A\n";
    }

    return 0;
}
