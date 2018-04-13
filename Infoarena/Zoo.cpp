#include <bits/stdc++.h>
 
using namespace std;
 
const int Nmax = 16e3 + 2;
const int INF = 2e9 + 4;
 
#define Point pair<int,int>
#define x first
#define y second
 
int N, M;
Point P[Nmax];
vector <int> A[4 * Nmax];
 
void build( int nod, int st, int dr )
{
    A[nod] = vector <int>( dr - st + 2 );
    A[nod][0] = -INF;
 
    if ( st == dr )
    {
        A[nod][1] = P[st].y;
    }
    else
    {
        int m = ( st + dr ) / 2;
 
        build( 2 * nod, st, m );
        build( 2 * nod + 1, m + 1, dr );
 
        merge( A[2 * nod].begin() + 1, A[2 * nod].end(), A[2 * nod + 1].begin() + 1, A[2 * nod + 1].end(), A[nod].begin() + 1 );
    }
}
 
int query( int nod, int st, int dr, int x1, int y1, int x2, int y2 )
{
    if ( x1 <= P[st].x && P[dr].x <= x2 )
    {
        return upper_bound( A[nod].begin(), A[nod].end(), y2 ) - lower_bound( A[nod].begin(), A[nod].end(), y1 );
    }
    else
    {
        if ( st == dr ) return 0;
 
        int m = ( st + dr ) / 2;
        int sol = 0;
 
        if ( x1 <= P[m].x )     sol += query( 2 * nod, st, m, x1, y1, x2, y2 );
        if ( P[m + 1].x <= x2 ) sol += query( 2 * nod + 1, m + 1, dr, x1, y1, x2, y2 );
 
        return sol;
    }
}
 
int main()
{
    ifstream in("zoo.in");
    ofstream out("zoo.out");
 
    in.sync_with_stdio( false );
 
    in >> N;
 
    for ( int i = 1; i <= N; ++i )
        in >> P[i].x >> P[i].y;
 
    sort( P + 1, P + N + 1 );
    build( 1, 1, N );
 
    in >> M;
 
    for ( int i = 0; i < M; ++i )
    {
        int x1, x2, y1, y2;
 
        in >> x1 >> y1 >> x2 >> y2;
        out << query( 1, 1, N, x1, y1, x2, y2 ) << "\n";
    }
 
    return 0;
}
