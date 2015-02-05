#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1002 + 1;
const int LgMax = log2(Nmax) + 1;

int rmq[LgMax][Nmax][Nmax];
int LOG[Nmax];
int A[Nmax][Nmax];
int sol[Nmax];

int N, M, K, Q;

inline int gcd(int a, int b)
{
    int r;

    while ( a )
    {
        r = b % a;
        b = a;
        a = r;
    }

    return b;
}

void build_rmq()
{
    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            rmq[0][i][j] = A[i][j];

    int limit = min( N, M );

    for ( int k = 1; ( 1 << k ) <= limit; ++k )
        for ( int i = 1; i + ( 1 << k ) - 1 <= N; ++i )
            for ( int j = 1; j + ( 1 << k ) - 1 <= M; ++j )
            {
                int p = ( 1 << (k - 1) );
                int numar = 0;

                numar = gcd(numar, rmq[k - 1][i + p][j]);
                numar = gcd(numar, rmq[k - 1][i][j + p]);
                numar = gcd(numar, rmq[k - 1][i + p][j + p]);
                numar = gcd(numar, rmq[k - 1][i][j]);

                rmq[k][i][j] = numar;
            }

    for ( int i = 2; i <= max(N, M); ++i )
        LOG[i] = LOG[i / 2] + 1;
}

int query( int i, int j, int l )
{
    int k = LOG[l];
    int p = ( 1 << k );
    int numar = 0;

    numar = gcd(numar, rmq[k][i + l - p][j]);
    numar = gcd(numar, rmq[k][i][j + l - p]);
    numar = gcd(numar, rmq[k][i + l - p][j + l - p]);
    numar = gcd(numar, rmq[k][i][j]);

    return numar;
}

int main()
{
    ifstream in("xcmmdc.in");
    ofstream out("xcmmdc.out");

    ios_base::sync_with_stdio( false );

    in >> N >> M >> K >> Q;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            in >> A[i][j];

    build_rmq();

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
        {
           int st = 1, dr = min(N - i + 1, M - j + 1), gasit1 = 1e9, gasit2 = 1e9;

           while ( st <= dr )
           {
               int m = ( st + dr ) / 2;
               int v = query(i, j, m);

               if ( v > K )
               {
                   st = m + 1;
               }
               else
               {
                    if ( v < K )
                        dr = m - 1;
                    else
                    {
                        gasit1 = m;
                        dr = m - 1;
                    }
               }
           }

           st = 1; dr = min(N - i + 1, M - j + 1);

           while ( st <= dr )
           {
               int m = ( st + dr ) / 2;
               int v = query(i, j, m);

               if ( v > K )
               {
                   st = m + 1;
               }
               else
               {
                    if ( v < K )
                        dr = m - 1;
                    else
                    {
                        gasit2 = m;
                        st = m + 1;
                    }
               }
           }

           if ( gasit1 <= gasit2 && gasit1 <= N && gasit2 <= N )
           {
               sol[gasit1]++;
               sol[gasit2 + 1]--;
           }
        }

    for ( int i = 1; i <= N; ++i )
        sol[i] += sol[i - 1];

    while ( Q-- )
    {
        int l;
        in >> l;
        out << sol[l] << "\n";
    }

    return 0;
}
