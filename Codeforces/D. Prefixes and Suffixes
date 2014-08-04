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

inline void read( int &a )
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
        a = a * 10 + ch - '0';
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

const int Nmax = 1e5 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

vector<int> Z_Algorithm( const string &str )
{
    int L = 0, R = 0;
    int N = str.size();

    vector<int> Z( N, 0 );

    for ( int i = 1; i < N; ++i )
    {
        if ( i < R )
            Z[i] = min( R - i + 1, Z[i - L] );

        while ( i + Z[i] < N && str[ Z[i] ] == str[ i + Z[i] ] ) Z[i]++;

        if ( i + Z[i] - 1 > R )
        {
            L = i;
            R = i + Z[i] - 1;
        }
    }

    return Z;
}

int sum[Nmax];

int main()
{
    string str;

    cin >> str;

    vector<int> Z = Z_Algorithm( str );

    int N = str.size();

    for ( int i = 0; i < N; ++i )
    {
        sum[0]++;
        sum[ Z[i] ]--;
    }

    vector <int> sol;

    for ( int i = N - 1; i >= 0; i-- )
    {
        if ( i + Z[i] == N )
            sol.pb( N - i );
    }

    for ( int i = 0; i < N; ++i )
    {
        if ( i > 0 )
            sum[i] += sum[i - 1];
    }

    cout << sol.size() + 1 << "\n";

    for ( auto x: sol )
        cout << x << " " << sum[x - 1] + 1 << "\n";

    cout << N << " 1\n";

    return 0;
}
