#include <fstream>

using namespace std;

const int Nmax = 1000 + 1;
const int Pmax = 100 + 1;

short A[Pmax][Nmax], v[Nmax];
int sum[Pmax][Nmax], sol[Nmax];
int N, M, P, Q;

int urm( int x )
{
    x++;

    if ( x > P )
        x = 1;

    return x;
}

/**

int brute()
{
    int maxim = 0;

    int D[Nmax][Nmax];

    ifstream in("livada.in");

    in >> N >> M >> P >> Q;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            in >> D[i][j];

    for ( int i = 1; i + P - 1 <= N; ++i )
    {
        for ( int j = 1; j + Q - 1 <= M; ++j )
        {
            int s = 0;

            for ( int k = i; k <= i + P - 1; ++k )
                for ( int l = j; l <= j + Q - 1; ++l )
                {
                    s += D[k][l];
                }

            maxim = max( maxim, s );
        }
    }

    in.close();

    return maxim;
}

void gen()
{
    srand( time( NULL ) );

    N = 1 + rand() % 500;
    M = 1 + rand() % 500;
    P = 1 + rand() % N;
    Q = 1 + rand() % M;

    P = min( P, 100 );
    Q = min( Q, 100 );

    ofstream out("livada.in");

    out << N << " " << M << " " << P << " " << Q << "\n";

    for ( int i = 1; i <= N; ++i, out << "\n" )
        for ( int j = 1; j <= M; ++j )
            out << 1 + rand() % 1000 << " ";

    out.close();
}

**/

int main()
{
   /// gen();

    ifstream in("livada.in");
    ofstream out("livada.out");

    ///ios_base::sync_with_stdio( false );

    in >> N >> M >> P >> Q;

    for ( int i = 1; i <= P; ++i )
        for ( int j = 1; j <= M; ++j )
            in >> A[i][j];

    for ( int i = 1; i <= P; ++i )
    {
        int s = 0;

        for ( int j = 1; j <= Q; ++j )
            s += A[i][j];

        sum[i][1] = s;

        for ( int j = 2; j + Q - 1 <= M; ++j )
            sum[i][j] = sum[i][j - 1] + A[i][j + Q - 1] - A[i][j - 1];

        for ( int j = 1; j + Q - 1 <= M; ++j )
            sol[j] = sol[j] + sum[i][j];
    }

    int maxim = 0;

    for ( int j = 1; j + Q - 1 <= M; ++j )
        maxim = max( maxim, sol[j] );

    int ind = 0;

    for ( int i = P + 1; i <= N; ++i )
    {
        for ( int j = 1; j <= M; ++j )
            in >> v[j];

        for ( int j = 1; j + Q - 1 <= M; ++j )
            sol[j] -= sum[ urm( ind ) ][j];

        int s = 0;

        for ( int j = 1; j <= Q; ++j )
            s += v[j];

        sum[ urm( ind ) ][1] = s;

        for ( int j = 2; j + Q - 1 <= M; ++j )
            sum[ urm( ind ) ][j] = sum[ urm( ind ) ][j - 1] + v[j + Q - 1] - v[j - 1];

        for ( int j = 1; j + Q - 1 <= M; ++j )
            sol[j] += sum[ urm( ind ) ][j];

        for ( int j = 1; j + Q - 1 <= M; ++j )
            maxim = max( maxim, sol[j] );

        ind = urm( ind );
    }

    /**if ( maxim != brute() )
        cout << "ERROR";
    else
        cout << "ACCEPTED";
    **/

    out << maxim << "\n";

    return 0;
}
