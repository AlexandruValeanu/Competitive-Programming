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
#define bit(n,i) ( n & ( 1LL << i ) )
#define lsb(x) ( x & ( -x ) )

#define FIN(str) freopen(str,"r",stdin)
#define FOUT(str) freopen(str,"w",stdout)
#define Fin(str) ifstream(str)
#define Fout(str) ostream(str)
#define SYNC ios_base::sync_with_stdio(0);

#define ll long long
#define ull unsigned long long

inline void read( long long &a )
{
    register char ch;
    a = 0;
    int sign = 1;

    do
    {
        ch = getchar();

    } while ( !isdigit( ch ) && ch != '-' );

    if ( ch == '-' )
    {
        sign = -1;
        ch = getchar();
    }

    do
    {
        a = a * 10LL + ch - '0';
        ch = getchar();

    } while( isdigit( ch ) );

    a *= sign;
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

const int INF = 2e9;
const double EPS = 1e-9;

const int Mmax = 524288 + 10;
const int Nmax = Mmax;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int T, H;
int N, M;
int A, B, IND;
int D[Mmax];
int vis[Mmax];
ll x[Mmax];

int main()
{
    ///FIN("data.in");
    ///FOUT("data.out");

    cin >> T;

    while ( T-- )
    {
        cin >> H;
        cin >> N >> M;
        cin >> A >> B >> IND;

        for ( int i = 0; i < M; ++i )
            cin >> D[i];

        ms( vis, 0 );

        int period = 0;
        int start = 0;
        ll area = 0;
        ll sumPeriod = 0;

        int i;

        for ( i = 1; ; i++ )
        {
            if ( vis[ IND ] )
            {
                period = i - vis[ IND ];
                start = vis[ IND ] - 1;
                sumPeriod = x[i - 1] - x[start];

                break;
            }

            vis[IND] = i;
            x[i] = x[i - 1] + 1LL * D[IND];
            IND = ( 1LL * A * IND + B ) % M;
        }

        if ( N <= i )
            area = x[N - 1];
        else
        {
            area = x[start];
            N -= start + 1;
            area += 1LL * ( N / period ) * sumPeriod;
            area += x[start + N % period] - x[start];
        }

        area *= 1LL * H;

        if ( area % 2 )
            cout << area / 2 << ".5" << "\n";
        else
            cout << area / 2 << ".0" << "\n";
    }

    return 0;
}
