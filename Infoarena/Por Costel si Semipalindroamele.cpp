#include <bits/stdc++.h>

using namespace std;

const int Nmax = 64;

int T, N;
long long K;
char str[Nmax];

int main()
{
    ifstream in("semipal.in");
    ofstream out("semipal.out");

    in >> T;

    while ( T-- )
    {
        in >> N >> K;

        if ( K <= (1LL << (N - 2)) )
        {
            str[1] = 'a';
            str[N] = 'a';
        }
        else
        {
            K -= (1LL << (N - 2));
            str[1] = 'b';
            str[N] = 'b';
        }

        for ( int i = 2; i < N; ++i )
        {
            if ( K <= (1LL << (N - i - 1)) )
            {
                str[i] = 'a';
            }
            else
            {
                K -= (1LL << (N - i - 1));
                str[i] = 'b';
            }
        }

        for ( int i = 1; i <= N; ++i )
            out << str[i];

        out << "\n";
    }

    return 0;
}
