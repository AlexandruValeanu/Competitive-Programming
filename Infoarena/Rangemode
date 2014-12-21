#include <bits/stdc++.h>
 
using namespace std;
 
const int Nmax = 100000 + 1;
const int RADICAL = 1 + sqrt( Nmax );
 
struct Query
{
    int l;
    int r;
};
 
Query q[Nmax];
int A[Nmax];
int frequency[Nmax];
int sol[Nmax];
vector <int> Q[RADICAL];
 
int N, M, SQRT;
 
int cmp( int a, int b )
{
    return q[a].r < q[b].r;
}
 
void update( int &value, int pos )
{
    if ( frequency[ A[pos] ] > frequency[ value ] )
    {
        value = A[pos];
    }
    else
        if ( frequency[ A[pos] ] == frequency[ value ] )
            value = min( value, A[pos] );
}
 
int main()
{
    freopen("rangemode.in", "r", stdin);
    freopen("rangemode.out", "w", stdout);
 
    cin >> N >> M;
 
    for ( int i = 1; i <= N; ++i )
        cin >> A[i];
 
    for ( SQRT = 1; SQRT * SQRT <= N; ++SQRT );
 
    for ( int i = 1; i <= M; ++i )
    {
        cin >> q[i].l >> q[i].r;
        Q[ 1 + q[i].l / SQRT ].push_back( i );
    }
 
    for ( int i = 1; i <= N / SQRT + 1; ++i )
    {
        sort( Q[i].begin(), Q[i].end(), cmp );
        memset( frequency, 0, sizeof( frequency ) );
 
        int value = 0;
        int start_pos = i * SQRT + 1;
 
        for ( auto x: Q[i] )
        {
            while ( start_pos <= q[x].r )
            {
                frequency[ A[start_pos] ]++;
                update( value, start_pos );
                start_pos++;
            }
 
            int aux = value;
 
            for ( int j = q[x].l; j <= i * SQRT && j <= q[x].r; ++j )
            {
                frequency[ A[j] ]++;
                update( aux, j );
            }
 
            for ( int j = q[x].l; j <= i * SQRT && j <= q[x].r; ++j )
                frequency[ A[j] ]--;
 
            sol[x] = aux;
        }
    }
 
    for ( int i = 1; i <= M; ++i )
        cout << sol[i] << "\n";
 
    return 0;
}
