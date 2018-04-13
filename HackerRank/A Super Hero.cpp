#include <bits/stdc++.h>

using namespace std;

inline int read_int() {
    register int x = 0;
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;

    return x;
}

class cmp1
{
public:

    bool operator () ( const pair<int,int> &a, const pair<int,int> &b ) const
    {
        if ( a.second != b.second )
            return a.second < b.second;
        else
            return a.first < b.first;
    }
};

class cmp2
{
public:

    bool operator () ( const pair<int,int> &a, const pair<int,int> &b ) const
    {
        if ( a.first != b.first )
            return a.first < b.first;
        else
            return a.second < b.second;
    }
};

const int Nmax = 100 + 2;
const int Mmax = 5e5 + 1;
const int Pmax = 1000 + 2;
const int INF = 0x3f3f3f3f;

int T, N, M;

vector < vector<int> > P, B;
int dp[Nmax][Pmax];

int main()
{
    ///freopen("data.in", "r", stdin);

    ios_base::sync_with_stdio( false );

    T = read_int();

    while ( T-- )
    {
        P.clear();
        B.clear();

        N = read_int(); M = read_int();

        P = vector< vector<int> >( N + 1 );
        B = vector< vector<int> >( N + 1 );

        for ( int i = 1; i <= N; ++i )
        {
            P[i] = vector<int>( M + 1, 0 );
            B[i] = vector<int>( M + 1, 0 );

            for ( int j = 1; j <= M; ++j )
                P[i][j] = read_int();
        }

        for ( int i = 1; i <= N; ++i )
            for ( int j = 1; j <= M; ++j )
                B[i][j] = read_int();

        memset( dp, 0x3f, sizeof( dp ) );

        dp[1][0] = 0;

        for ( int i = 1; i <= N; ++i )
        {
            for ( int j = 1; j <= M; ++j )
            {
                for ( int k = 0; k <= 1000; ++k )
                {
                    if ( dp[i][k] == INF ) continue;

                    int nevoie = max( 0, P[i][j] - k );

                    if ( dp[i + 1][ B[i][j] ] > dp[i][k] + nevoie )
                        dp[i + 1][ B[i][j] ] = dp[i][k] + nevoie;
                }
            }
        }

        cout << *min_element( dp[N + 1] + 1, dp[N + 1] + 1000 + 1 ) << "\n";
    }

    return 0;
}
