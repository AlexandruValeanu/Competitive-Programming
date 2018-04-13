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

const char a[] = { "qwertyuiop" };
const char b[] = { "asdfghjkl;" };
const char c[] = { "zxcvbnm,./" };

string s;
int pos;

int main()
{
    ///FIN("data.in");
    ///FOUT("data.out");

    char p;

    cin >> p >> s;

    int pos = 0;

    if ( p == 'R' )
        pos = -1;
    else
        pos = +1;

    int lgA = strlen( a );
    int lgB = strlen( b );
    int lgC = strlen( c );

    for ( int i = 0; i < s.size(); ++i )
    {
        if ( s[i] == 'q' )
        {
            cout << 'w';
            continue;
        }

        if ( s[i] == 'a' )
        {
            cout << 's';
            continue;
        }

        if ( s[i] == 'z' )
        {
            cout << 'x';
            continue;
        }

        if ( s[i] == 'p' )
        {
            cout << 'o';
            continue;
        }

        if ( s[i] == ';' )
        {
            cout << 'l';
            continue;
        }

        if ( s[i] == '/' )
        {
            cout << '.';
            continue;
        }

        for ( int j = 0; j < lgA; ++j )
        {
            if ( a[j] == s[i] )
            {
                cout << a[j + pos];
                break;
            }
        }

        for ( int j = 0; j < lgB; ++j )
        {
            if ( b[j] == s[i] )
            {
                cout << b[j + pos];
                break;

            }
        }

        for ( int j = 0; j < lgC; ++j )
        {
            if ( c[j] == s[i] )
            {
                cout << c[j + pos];
                break;
            }
        }
    }

    return 0;
}
