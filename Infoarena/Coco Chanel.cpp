#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;

pair<int,int> A[Nmax];
int B[Nmax], sol[Nmax];
int N, M;

int cauta( int aux, int pos )
{
    int st = pos, dr = M, gasit = -1;

    while ( st <= dr )
    {
        int m = ( st + dr ) / 2;

        if ( aux <= B[m] )
        {
            gasit = m;
            dr = m - 1;
        }
        else
            st = m + 1;
    }

    return gasit;
}

int main()
{
    ifstream in("cocochanel.in");
    ofstream out("cocochanel.out");

    ios_base::sync_with_stdio( false );

    in >> N >> M;

    for ( int i = 1; i <= N; ++i )
    {
        in >> A[i].first;
        A[i].second = i;
    }

    for ( int j = 1; j <= M; ++j )
        in >> B[j];

    sort( A + 1, A + N + 1 );
    sort( B + 1, B + M + 1 );

    for ( int i = 1; i <= N; ++i )
    {
        int s = 0;
        int aux = A[i].first;

        int j = 1, p;
        int cont = 0;

        do
        {
            p = cauta( aux, j );

            aux *= 2;

            j = p + 1;
            if ( p != -1 ) cont++;

        } while ( p != -1 );

        sol[ A[i].second ] = cont;
    }

    for ( int i = 1; i <= N; ++i )
        out << sol[i] << "\n";

    return 0;
}
