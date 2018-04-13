#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int Nmax = 1e5 + 2;
const int LgMax = 17 + 1;

vector <int> G[Nmax];
int A[LgMax][Nmax];
int depth[Nmax];
int N, Q, LGM;

void DFS( int node )
{
    for ( auto x: G[node] )
    {
        depth[x] = depth[node] + 1;
        DFS( x );
    }
}

int ancestor( int node, int pow )
{
    if ( pow == 0 )
        return A[0][node];

    int lg = LGM;

    while ( pow )
    {
        if ( ( 1 << lg ) <= pow )
        {
            node = A[lg][node];
            pow ^= ( 1 << lg );
        }

        lg--;
    }

    return node;
}

int lca( int a, int b )
{
    if ( depth[a] != depth[b] )
    {
        if ( depth[a] < depth[b] )
        {
            int l = depth[b] - depth[a];
            b = ancestor( b, l );
        }
        else
        {
            int l = depth[a] - depth[b];
            a = ancestor( a, l );
        }
    }

    if ( a == b )
        return a;

    int lo = 0, hi = N, sol = -1;

    while ( lo <= hi )
    {
        int m = ( lo + hi ) / 2;

        int ancA = ancestor( a, m );
        int ancB = ancestor( b, m );

        if ( ancA == 0 || ancB == 0 )
        {
            hi = m - 1;
            continue;
        }

        if ( ancA == ancB )
        {
            sol = ancA;
            hi = m - 1;
        }
        else
        {
            lo = m + 1;
        }
    }

    return sol;
}

int main()
{
    cin.sync_with_stdio( false );

    cin >> N >> Q;

    for ( int i = 2, a; i <= N; ++i )
    {
        cin >> a;

        G[a].push_back( i );
        A[0][i] = a;
    }

    DFS( 1 );

    LGM = 1;
    int lg = 1;

    for ( ; lg <= N; lg <<= 1, LGM++ );

    for ( int i = 1; i <= LGM; ++i )
        for ( int j = 1; j <= N; ++j )
            A[i][j] = A[i - 1][ A[i - 1][j] ];

    while ( Q-- )
    {
        int a, b;

        cin >> a >> b;
        cout << lca( a, b ) << "\n";
    }

    return 0;
}
