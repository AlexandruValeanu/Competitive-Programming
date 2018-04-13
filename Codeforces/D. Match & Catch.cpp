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

const int Nmax = 2 * ( 5e3 + 2 );

const int LgMax = log2(Nmax) + 1;

using namespace std;

string A, B, str;
int Rank[Nmax], tmpRank[Nmax];
int SA[Nmax], lcp[Nmax], invSA[Nmax];

int N, M, NM, gap;

int sufComp( int i, int j )
{
    if ( Rank[i] != Rank[j] )
        return Rank[i] < Rank[j];

    i += gap;
    j += gap;

    if ( i < NM && j < NM )
        return Rank[i] < Rank[j];
    else
        return i > j;
}

void SuffixArray()
{
    for ( int i = 0; i < NM; ++i )
    {
        SA[i] = i;
        Rank[i] = str[i];
    }

    for ( gap = 1; gap; gap <<= 1 )
    {
        sort( SA, SA + NM, sufComp );

        for ( int i = 0; i < NM - 1; ++i )
            tmpRank[i + 1] = tmpRank[i] + sufComp( SA[i], SA[i + 1] );

        for ( int i = 0; i < NM; ++i )
            Rank[ SA[i] ] = tmpRank[i];

        if ( tmpRank[NM - 1] == NM - 1 ) break;
    }
}

void LCP()
{
    for ( int i = 0; i < NM; ++i )
        invSA[ SA[i] ] = i;

    int l = 0;

    for ( int i = 0; i < NM; ++i )
    {
        if ( invSA[i] > 0 )
        {
            int k = invSA[i];
            int j = SA[k - 1];

            while ( i + l < NM && j + l < NM && str[i + l] == str[j + l] ) l++;

            lcp[k] = l;

            if ( l ) l--;
        }
    }
}

int main()
{
    cin >> A >> B;

    str = A + "$" + B + "#";

    N = A.size();
    M = B.size();
    NM = str.size();

    SuffixArray();
    LCP();

    int sol = INF;

    for ( int i = 0; i + 1 < NM; ++i )
    {
        if ( ( SA[i] < N ) != ( SA[i + 1] < N ) )
        {
            int x = lcp[i];
            int z = lcp[i + 1];
            int y = lcp[i + 2];

            if ( z > max( x, y ) && sol > max( x, y ) + 1 )
            {
                sol = max( x, y ) + 1;
            }
        }
    }

    if ( sol == INF )
        sol = -1;

    cout << sol << "\n";

    return 0;
}
