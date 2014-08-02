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

int N, M;
int A[10 * Nmax], B[10 * Nmax];
int NN;
VI v;

int main()
{
    ///FIN("data.in");
    //FOUT("data.out");

    cin >> N;

    for ( int i = 1; i <= N; ++i )
        cin >> A[i];

    int valid = 0;

    for ( int i = 1; i <= N; ++i )
        if ( A[i] < A[i - 1] )
            valid = 1;

    if ( valid == 0 )
    {
        cout << "0\n";
        return 0;
    }

    int minim = *min_element( A + 1, A + N + 1 );
    int primul = A[1];
    int nr = 0;
    int ultim = N;

    while ( ultim >= 1 && A[ultim] <= primul )
    {
        v.pb( A[ultim] );
        primul = A[ultim];
        ultim--;

        nr++;
    }

    for ( int i = v.size() - 1; i >= 0; i-- )
        B[ ++NN ] = v[i];

    for ( int i = 1; i <= ultim; ++i )
        B[ ++NN ] = A[i];

    valid = 0;

    for ( int i = 1; i <= NN; ++i )
        if ( B[i] < B[i - 1] )
            valid = 1;

    if ( valid == 0 )
    {
        cout << nr << "\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}
