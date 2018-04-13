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

const int Nmax = 30 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

int exist[Nmax][Nmax];
int grundy[Nmax][Nmax];

vector<int> Z_Algorithm( const string &str )
{
    const int N = str.size();
    int L = 0, R = 0;

    vector <int> Z( N, 0 );

    for ( int i = 1; i < N; ++i )
    {
        if ( i <= R )
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

void pattern_match( const string &pattern, const string &text )
{
    vector <int> Z = Z_Algorithm( pattern + text );

    for ( size_t i = pattern.size(); i < Z.size(); ++i )
    {
        if ( Z[i] >= pattern.size() )
        {
            exist[i - pattern.size()][i - 1] = 1;
        }
    }
}

int mex( int i, int j )
{
    unordered_set <int> Set;

    for ( int k = i; k <= j; ++k )
        for ( int l = k; l <= j; ++l )
            if ( exist[k][l] )
            {
                int val1 = 0;
                int val2 = 0;

                if ( i <= k - 1 ) val1 = grundy[i][k - 1];
                if ( l + 1 <= j ) val2 = grundy[l + 1][j];

                Set.insert( val1 ^ val2 );
            }

    int sol = 0;

    while ( Set.find( sol ) != Set.end() )
        sol++;

    return sol;
}

void sprague_grundy( const int N )
{
    for ( int i = N - 1; i >= 0; i-- )
    {
        for ( int j = i; j < N; ++j )
            grundy[i][j] = mex( i, j );
    }
}

int main()
{
    string text, pattern;
    int nrPatterns, tests;

    cin >> tests;

    while ( tests-- )
    {

        cin >> text;
        cin >> nrPatterns;

        while ( nrPatterns-- )
        {
            cin >> pattern;
            pattern_match( pattern, text );
        }

        sprague_grundy( (int)text.size() );

        if ( grundy[0][text.size() - 1] )
            cout << "Teddy\n";
        else
            cout << "Tracy\n";

        ms( exist, 0 );
        ms( grundy, 0 );
    }

    return 0;
}
