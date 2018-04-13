#include <bits/stdc++.h>

using namespace std;

const int LIMIT = ( 1 << 16 );

long long dp[LIMIT];

int N, D;

int codifica(vector<int>& stare)
{
    int sol = 0;

    for ( int i = 0; i < stare.size(); ++i )
        sol = sol * D + stare[i];

    return sol;
}

long long getCost(vector<int>& stare)
{
    long long sum = 0;
    long long xorsum = 0;

    for ( int x: stare )
    {
        sum += x;
        xorsum ^= x;
    }

    return sum * xorsum;
}

long long memo(vector<int>& v)
{
    int id = codifica(v);

    if ( dp[id] != -1 )
        return dp[id];

    if ( id == 0 )
        return 0;

    long long cost = ( 1LL << 60 );

    for ( int i = 0; i < v.size(); ++i )
    {
        if ( v[i] > 0 )
        {
            vector<int> g = v;
            g[i]--;

            cost = min( cost, memo(g) );
        }
    }

    return dp[id] = cost + getCost(v);
}

int main()
{
    ///ifstream cin("data.in");

    int T;

    cin >> T;

    while ( T-- )
    {
        cin >> N >> D;

        vector<int> v;

        for ( int i = 0; i < N; ++i )
            v.push_back( D - 1 );

        memset( dp, -1, sizeof( dp ) );

        cout << memo(v) << "\n";
    }

    return 0;
}
