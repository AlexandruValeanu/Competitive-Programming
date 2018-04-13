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

const int Nmax = 1e4 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

const int SIGMA = 26;

class TrieNode
{
public:

    TrieNode *sons[SIGMA + 1];
    int count;
    int nr_sons;

    TrieNode()
    {
        count = 0;
        nr_sons = 0;
        memset( sons, 0, sizeof( sons ) );
    }
};

    TrieNode *root;

    void insert( TrieNode *&R, const string &str, size_t pos )
    {
        if ( pos == str.size() )
        {
            R->count++;
        }
        else
        {
            if ( R->sons[ str[pos] - 'a' ] == NULL )
            {
                R->nr_sons++;
                R->sons[ str[pos] - 'a' ] = new TrieNode();
            }

            insert( R->sons[ str[pos] - 'a' ], str, pos + 1 );
        }
    }

    int find( TrieNode *R, const string &str, size_t pos )
    {
        if ( pos == str.size() )
        {
            return R->count;
        }
        else
        {
            if ( R->sons[ str[pos] - 'a' ] == NULL )
                return 0;

            return find( R->sons[ str[pos] - 'a' ], str, pos + 1 );
        }
    }

    bool erase( TrieNode *&R, const string &str, size_t pos )
    {
        if ( pos == str.size() )
        {
            R->count--;
        }
        else
        {
            if ( erase( R->sons[ str[pos] - 'a' ], str, pos + 1 ) )
            {
                R->sons[ str[pos] - 'a' ] = NULL;
                R->nr_sons--;
            }
        }

        if ( R->count == 0 && R->nr_sons == 0 && R != root )
        {
            delete R;
            return true;
        }

        return false;
    }

    int longest_common_prefix( TrieNode *R, const string &str, size_t pos )
    {
        if ( pos == str.size() )
        {
            return 0;
        }
        else
        {
            if ( R->sons[ str[pos] - 'a' ] != NULL )
                return 1 + longest_common_prefix( R->sons[ str[pos] - 'a' ], str, pos + 1 );
            else
                return 0;
        }
    }

    void insert( const string &str )
    {
        insert( root, str, 0 );
    }

    int find( const string &str )
    {
        return find( root, str, 0 );
    }

    void erase( const string &str )
    {
        erase( root, str, 0 );
    }

    int longest_common_prefix( const string &str )
    {
        return longest_common_prefix( root, str, 0 );
    }


int N, K;

int finalState( TrieNode *r )
{
    for ( int i = 0; i < SIGMA; ++i )
    {
        if ( r->sons[i] != NULL )
            return 0;
    }

    return 1;
}

int solveCastiga( TrieNode *r )
{
    if ( finalState( r ) )
        return 0;

    int sol = 0;

    for ( int i = 0; i < SIGMA; ++i )
    {
        if ( r->sons[i] != NULL )
        {
            if ( solveCastiga( r->sons[i] ) == 0 )
            {
                sol = 1;
                break;
            }
        }
    }

    return sol;
}

int solvePierde( TrieNode *r )
{
    if ( finalState( r ) )
        return 1;

    int sol = 0;

    for ( int i = 0; i < SIGMA; ++i )
    {
        if ( r->sons[i] != NULL )
        {
            if ( solvePierde( r->sons[i] ) == 0 )
            {
                sol = 1;
                break;
            }
        }
    }

    return sol;
}

int main()
{
    cin >> N >> K;

    root = new TrieNode();

    for ( int i = 0; i < N; ++i )
    {
        string str;

        cin >> str;

        insert( str );
    }

    int ansWin = solveCastiga( root );
    int ansLose = solvePierde( root );


    if ( ansWin == 0 )
    {
        cout << "Second";
    }
    else
    {
        if ( ansLose == 0 )
        {
            if ( K % 2 == 1 )
                cout << "First";
            else
                cout << "Second";
        }
        else
        {
            cout << "First";
        }
    }

    return 0;
}
