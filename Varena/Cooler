#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Nmax = 5000;

int A[Nmax + 1], B[Nmax + 1], C[Nmax + 1];
int vis[Nmax + 1];

int N, K;

void normalizare()
{
    memcpy( B, A, sizeof( A ) );
    sort( B + 1, B + N + 1 );

    for ( int i = 1; i <= N; ++i )
     C[i] = lower_bound( B + 1, B + N + 1, A[i] ) - B;
}

int solve1()
{
    memset( vis, 0, sizeof( vis ) );

    int maxim = 0;
    int minim = 2e9;
    int distincte = 0;

    for ( int i = 1; i <= K; ++i )
    {
        maxim = max( maxim, A[i] );
        minim = min( minim, A[i] );

        vis[ C[i] ]++;
    }

    for ( int i = 1; i <= K; ++i )
        distincte += ( vis[ C[i] ] == 1 );

    if ( maxim - minim + 1 == K && distincte == K )
        return maxim;
    else
        return distincte;
}

pair<int,int> solve2()
{
    int lgmax = 0;
    int contor = 0;

    for ( int i = 1; i <= N; ++i )
    {
        memset( vis, 0, sizeof( vis ) );

        int maxim = 0;
        int minim = 2e9;
        int valid = 1;

        for ( int j = i; j <= N; ++j )
        {
            maxim = max( maxim, A[j] );
            minim = min( minim, A[j] );

            if ( !vis[ C[j] ] )
                vis[ C[j] ] = 1;
            else
                valid = 0;

            if ( !valid )
                j = N + 1;
            else
                if ( maxim - minim + 1 == j - i + 1 )
                {
                    if ( j - i + 1 > lgmax )
                    {
                        lgmax = j - i + 1;
                        contor = 1;
                    }
                    else
                    {
                        if ( j - i + 1 == lgmax )
                            contor++;
                    }
                }
        }
    }

    return pair<int,int>( lgmax, contor );
}

int main()
{
    ifstream in("cooler.in");
    ofstream out("cooler.out");

    int p;

    in >> p >> N >> K;

    for ( int i = 1; i <= N; ++i )
        in >> A[i];

    normalizare();

    if ( p == 1 )
        out << solve1() << "\n";
    else
    {
        pair<int,int> sol = solve2();
        out << sol.first << "\n" << sol.second << "\n";
    }

    return 0;
}
