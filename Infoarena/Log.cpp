#include <bits/stdc++.h>
 
using namespace std;
 
const int Nmax = 10000 + 1;
const int INF = 2e9;
 
int a[Nmax];
int b[Nmax];
int dp[Nmax];
 
int N, t1, t2, t3;
 
int costEval(int A, int B)
{
    return t3 * (A - B) * (A - B);
}
 
int main()
{
    ifstream in("log.in");
    ofstream out("log.out");
 
    in >> N;
    in >> t1 >> t2 >> t3;
 
    for ( int i = 1; i <= N; ++i )
        in >> a[i] >> b[i];
 
    for ( int i = 1; i <= N; ++i )
    {
        int CST = costEval(a[i], b[i]) + dp[i - 1];
 
        if ( i != 1 )
            CST += t1;
 
        dp[i] = CST;
 
        int auxA = a[i];
        int auxB = b[i];
 
        int cost2 = 0;
 
        for ( int j = i - 1; j >= 1; j-- )
        {
            if ( b[j] == auxA )
            {
                cost2 += t2;
                auxA = a[j];
                auxB = auxB;
 
                int COST = dp[j - 1] + cost2 + costEval(auxA, auxB);
 
                if ( j != 1 )
                    COST += t1;
 
                dp[i] = min(dp[i], COST);
            }
            else
                break;
        }
    }
 
    out << dp[N] << "\n";
 
    return 0;
}
