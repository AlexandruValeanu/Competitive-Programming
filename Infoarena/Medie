#include <bits/stdc++.h>

using namespace std;

const int Nmax = 9000;
const int Vmax = 7000;

int Hash[Vmax + 1];
int v[Nmax];
int N;

int main()
{
    ifstream in("medie.in");
    ofstream out("medie.out");

    ios_base::sync_with_stdio(false);

    in >> N;

    for ( int i = 1; i <= N; ++i )
    {
        in >> v[i];
        Hash[v[i]]++;
    }

    int sol = 0;

    for ( int i = 1; i <= N; ++i )
        for ( int j = i + 1; j <= N; ++j )
        {
            if ( (v[i] + v[j]) % 2 == 0 )
            {
                int medie = (v[i] + v[j]) / 2;

                sol += Hash[medie];

                if ( v[i] == medie )
                    sol--;

                if ( v[j] == medie )
                    sol--;
            }
        }

    out << sol << "\n";

    return 0;
}
