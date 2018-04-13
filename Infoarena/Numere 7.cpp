#include <bits/stdc++.h>

using namespace std;

const int Nmax = 22;

long long fact[Nmax];
char X[Nmax];
int contor[10];
int N;
long long n;

long long numberPerm()
{
    int nrCifs = 0;

    for ( int i = 1; i <= 9; ++i )
        nrCifs += contor[i];

    long long s = fact[nrCifs];

    for ( int i = 1; i <= 9; ++i )
        s /= fact[ contor[i] ];

    return s;
}

int main()
{
    ifstream in("numere7.in");
    ofstream out("numere7.out");

    ios_base::sync_with_stdio(false);

    in >> n >> X;
    N = strlen(X);

    for ( int i = 0; X[i]; ++i )
        contor[ X[i] - '0' ]++;

    fact[0] = 1;

    for ( int i = 1; i < Nmax; ++i )
        fact[i] = 1LL * i * fact[i - 1];

    if ( n > numberPerm() )
        out << "-1\n";
    else
    {
        for ( int i = 0; i < N; ++i )
        {
            for ( int d = 1; d <= 9; ++d )
            {
                if ( contor[d] )
                {
                    contor[d]--;
                    long long P = numberPerm();

                    if ( n <= P )
                    {
                        out << d;
                        break;
                    }

                    n -= P;
                    contor[d]++;
                }
            }
        }

        out << "\n";
    }

    return 0;
}
