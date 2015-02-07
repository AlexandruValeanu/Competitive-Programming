#include <bits/stdc++.h>
 
using namespace std;
 
const int Nmax = 100000 + 1;
const int MOD = 666013;
 
struct Lista
{
    int nod;
    int urm;
};
 
Lista G[2 * Nmax];
int vecini[Nmax];
 
int special[Nmax];
int dp[Nmax][2]; /// 0 - din subarbore
 
int N, K, contor;
 
void addEdge(int x, int y)
{
    contor++;
    G[contor].nod = y;
    G[contor].urm = vecini[x];
    vecini[x] = contor;
}
 
int pw(int a, int p)
{
    int res = 1;
    assert( a > 0 );
 
    while ( p )
    {
        if ( p & 1 )
            res = ( 1LL *res * a ) % MOD;
 
        p >>= 1;
        a = ( 1LL * a * a ) % MOD;
    }
 
    return res;
}
 
void DFS(int nod, int tata)
{
    dp[nod][1] = 1;
 
    for ( int p = vecini[nod]; p; p = G[p].urm )
    {
        int fiu = G[p].nod;
 
        if ( fiu != tata )
        {
            DFS(fiu, nod);
            dp[nod][1] = ( 1LL * dp[nod][1] * ( dp[fiu][0] + dp[fiu][1] ) ) % MOD;
        }
    }
 
    if ( special[nod] )
    {
        dp[nod][0] = dp[nod][1];
        dp[nod][1] = 0;
    }
    else
    {
        int produsPrecalculat = dp[nod][1];
 
        for ( int p = vecini[nod]; p; p = G[p].urm )
        {
            int fiu = G[p].nod;
 
            if ( fiu != tata )
            {
                int sol = produsPrecalculat;
                sol = ( 1LL * sol * pw(dp[fiu][0] + dp[fiu][1], MOD - 2) ) % MOD;
                sol = ( 1LL * sol * dp[fiu][0] ) % MOD;
 
                dp[nod][0] = ( dp[nod][0] + sol ) % MOD;
            }
        }
    }
}
 
int main()
{
    ifstream in("karb2.in");
    ofstream out("karb2.out");
 
    ios_base::sync_with_stdio( false );
 
    in >> N >> K;
 
    for ( int i = 1; i <= K; ++i )
    {
        int a;
        in >> a;
        special[a] = 1;
    }
 
    for ( int i = 1; i <= N - 1; ++i )
    {
        int a, b;
        in >> a >> b;
 
        addEdge(a, b);
        addEdge(b, a);
    }
 
    DFS(1, 0);
 
    out << dp[1][0] << "\n";
 
    return 0;
}
