#include <bits/stdc++.h>

#define VI vector<int>
#define VII vector<pair<int,int>>
#define QI queue<int>

#define ms(a,v) memset( a, v, sizeof( a ) )
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define foreach(v, c) for( typeof( (c).begin() ) v = (c).begin(); v != (c).end(); ++v)

#define pb push_back
#define pp pair<int,int>
#define mp make_pair
#define fi first
#define se second

#define popcount __builtin_popcount
#define gcd __gcd
#define bit(n,i) ( n & ( 1 << i ) )
#define lsb(x) ( x & ( -x ) )

#define FIN(str) freopen(str,"r",stdin)
#define FOUT(str) freopen(str,"w",stdout)
#define Fin(str) ifstream(str)
#define Fout(str) ostream(str)
#define SYNC ios_base::sync_with_stdio(0);

#define ll long long
#define ull unsigned long long

inline void read( int &a )
{
    register char ch;
    a = 0;

    do
    {
        ch = getchar();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar();

    } while( isdigit( ch ) );
}

inline void write( int a )
{
    char s[20];
    int i = 0;
    int sign = 1;

    if ( a < 0 )
        sign = -1,
        a = -a;

    do
    {
        s[ i++ ] = a % 10 + '0';
        a /= 10;

    } while ( a );

    i--;

    if ( sign == -1 )
        putchar( '-' );

    while ( i >= 0 ) putchar( s[ i-- ] );
}

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int dl[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const int INF = 1e9;
const double EPS = 1e-9;

const int Nmax = 300000 + 2;
const int Mmax = 100000 + 2;
const int Vmax = 100000 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

const int HighFrequency = 500;

int A[Nmax];
int frequency[Vmax];
VI position[Vmax];
VI HiFreq;

int freqPosition[Nmax];

pair<pp,int> Q[Mmax];
int answer[Mmax];

int N, K, M;

int main()
{

    read( N ); read( K );

    for ( int i = 1; i <= N; ++i )
    {
        scanf("%d ", &A[i]);

        frequency[ A[i] ]++;
        position[ A[i] ].pb( i );
    }

    for ( int i = 1; i < Vmax; ++i )
        if ( frequency[i] >= HighFrequency )
            HiFreq.pb( i );

    for ( int i = 1; i < HighFrequency; ++i )
        freqPosition[i] = INF;

    read( M );

    for ( int i = 1; i <= M; ++i )
    {
        read( Q[i].fi.fi );
        read( Q[i].fi.se );
        Q[i].se = i;
    }

    sort( Q + 1, Q + M + 1 );

    int ind = M;

    for ( int i = N; i >= 1; i-- )
    {
        if ( frequency[ A[i] ] < HighFrequency )
        {
            int j = 0;

            while ( position[ A[i] ][j] < i ) j++;

            for ( int frq = 1; j < position[ A[i] ].size(); frq++, j++ )
                freqPosition[frq] = min( freqPosition[frq], position[ A[i] ][j] );
        }

        while ( ind >= 1 && Q[ind].fi.fi == i )
        {
            int x = Q[ind].fi.fi, y = Q[ind].fi.se;
            int ans = -1;
            int val = -1;

            for ( vector <int>::iterator v = HiFreq.begin();  v != HiFreq.end(); ++v )
            {
                int a = lower_bound( position[*v].begin(), position[*v].end(), x ) - position[*v].begin();
                int b = lower_bound( position[*v].begin(), position[*v].end(), y + 1 ) - position[*v].begin();

                if ( b - a > ans )
                    ans = b - a,
                    val = ans;
            }

            int st = 1, dr = HighFrequency - 1, gasit = 0;

            while ( st <= dr )
            {
                int m = ( st + dr ) / 2;

                if ( freqPosition[m] <= y )
                {
                    gasit = m;
                    st = m + 1;
                }
                else
                    dr = m - 1;
            }

            if ( gasit > ans )
                ans = gasit,
                val = A[ freqPosition[gasit] ];

            if ( 2 * ans > y - x + 1 )
                answer[ Q[ind].se ] = val;
            else
                answer[ Q[ind].se ] = -1;

            ind--;
        }

    }

    for ( int i = 1; i <= M; ++i )
        if ( answer[i] < 0 )
            printf("no\n");
        else
            printf("yes %d\n", answer[i]);

    return 0;
}
