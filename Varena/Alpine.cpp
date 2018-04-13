#include <bits/stdc++.h>

using namespace std;

const int Nmax = 10000 + 1;
const int Kmax = 1000 + 1;

vector <int> G[Kmax];

pair <int,int> tata[Nmax];
vector <short> v;

int dp[Nmax], D[Nmax];
int N, K, T1, T2, T3;

int sum_intre( int x, int y )
{
    return y - x + 1;
}

void gen()
{
    srand( time( NULL ) );

    ofstream out("alpine.in");

    const int NN = 10000;
    const int KK = 1000;

    out << NN << " " << KK << " 1 2 3\n";

    for ( int i = 1; i <= NN; ++i )
        out << 1 + rand() % KK << " ";

    out.close();
}

int main()
{
    ///gen();

    ifstream in("alpine.in");
    ofstream out("alpine.out");

    ios_base::sync_with_stdio( false );

    in >> N >> K >> T1 >> T2 >> T3;

    for ( int i = 1; i <= N; ++i )
    {
        in >> D[i];
        dp[i] = 1e9;
        G[ D[i] ].push_back( i );
    }

    dp[0] = 0;

    for ( int i = 1; i <= N; ++i )
    {
        if ( dp[i] > dp[i - 1] + T1 )
        {
            dp[i] = dp[i - 1] + T1;
            tata[i] = pair<int,int>( i - 1, -1 );
        }

        if ( dp[i] > dp[i - 1] + T2 + T3 )
        {
            dp[i] = dp[i - 1] + T2 + T3;
            tata[i] = pair<int,int>( i - 1, -2 );
        }

        int lafel = 1;
        int diferite = 0;
        int ultim = i;

        int j = 0;

        while ( j < G[ D[i] ].size() && G[ D[i] ][j] <= i ) j++;

        for ( ; j < G[ D[i] ].size(); ++j )
        {
            int pos = G[ D[i] ][j];

            lafel++;
            diferite += sum_intre( ultim + 1, pos - 1 );
            ultim = pos;

            if ( dp[pos] > dp[i - 1] + diferite * T1 + lafel * T2 + T3 )
            {
                dp[pos] = dp[i - 1] + diferite * T1 + lafel * T2 + T3;
                tata[pos] = pair<int,int>( i - 1, D[i] );
            }
        }
    }

    int pos = N;

    while ( pos )
    {
        pair<int,int> p = tata[pos];

        ///cout << pos << " " << p.first << " " << p.second << endl;

        if ( p.second < 0 )
        {
            pos = pos - 1;

            if ( p.second == -1 )
                v.push_back( 1 );
            else
            {
                v.push_back( 3 );
                v.push_back( 2 );
            }
        }
        else
        {
            int new_p = p.first;
            int val = p.second;

            vector <int> sol;

            for ( int i = new_p + 1; i <= pos; ++i )
            {
                if ( D[i] == val )
                    sol.push_back( 2 );
                else
                    sol.push_back( 1 );
            }

            sol.push_back( 3 );

            for ( int i = sol.size() - 1; i >= 0; i-- )
                v.push_back( sol[i] );

            pos = new_p;
        }
    }

    out << dp[N] << "\n";

    for ( int i = v.size() - 1; i >= 0; i-- )
        out << v[i];

    out << "\n";

    return 0;
}
