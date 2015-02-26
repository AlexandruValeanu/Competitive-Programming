#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

int dp[Nmax], age[Nmax], sumDp[Nmax];
vector<int> G[Nmax];
int v[Nmax];

int N, S;

void dfs(int nod)
{
    for (int& son: G[nod])
        dfs(son);

    if ( G[nod].size() == 0 )
    {
        dp[nod] = 1;
        sumDp[nod] = age[nod];
    }
    else
    {
        int contor = 0;

        for (int& son: G[nod])
        {
            v[ ++contor ] = sumDp[son];
            dp[nod] += dp[son];

        }

        sort(v + 1, v + contor + 1);

        int sum_cr = age[nod];
        int i = 1;

        while ( i <= contor && sum_cr + v[i] <= S )
        {
            sum_cr += v[i];
            i++;
        }

        sumDp[nod] = sum_cr;
        dp[nod] -= (i - 2);
    }
}

int main()
{
    ifstream in("mese.in");
    ofstream out("mese.out");

    ios_base::sync_with_stdio(false);

    in >> N >> S;

    for ( int i = 1, tata; i <= N; ++i )
    {
        in >> tata >> age[i];
        G[tata].push_back(i);
    }

    age[0] = 0;
    dfs(0);

    out << dp[0] << "\n";

    return 0;
}
