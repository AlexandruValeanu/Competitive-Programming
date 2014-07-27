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
        ch = getchar_unlocked();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getchar_unlocked();

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
        putchar_unlocked( '-' );

    while ( i >= 0 ) putchar_unlocked( s[ i-- ] );
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

struct Treap
{
    char key;
    int priority;
    int nr_nodes;

    Treap *st, *dr;

    Treap( const char _key, const int _priority, const int _nr_nodes, Treap *_st, Treap *_dr )
    {
        key = _key;
        priority = _priority;
        nr_nodes = _nr_nodes;
        st = _st;
        dr = _dr;
    }

} *root, *NIL;

void initTreap()
{
    srand( time( NULL ) );
    NIL = new Treap( 0, 0, 0, NULL, NULL );
    root = NIL;
}

void update( Treap *&T )
{
    T->nr_nodes = 1 + T->st->nr_nodes + T->dr->nr_nodes;
}

void rotateRight( Treap *&T )
{
    Treap *aux = T->st;
    T->st = aux->dr;
    aux->dr = T;

    update( T );
    update( aux );

    T = aux;
}

void rotateLeft( Treap *&T )
{
    Treap *aux = T->dr;
    T->dr = aux->st;
    aux->st = T;

    update( T );
    update( aux );

    T = aux;
}

void balance( Treap *&T )
{
    if ( T->priority < T->st->priority )
        rotateRight( T );

    if ( T->priority < T->dr->priority )
        rotateLeft( T );

    update( T );
}

void insert( Treap *&T, char key, int position, int prior = rand() + 1 )
{
    if ( T == NIL )
    {
        T = new Treap( key, prior, 1, NIL, NIL );
    }
    else
    {
        if ( position <= T->st->nr_nodes + 1 )
            insert( T->st, key, position, prior );
        else
            insert( T->dr, key, position - T->st->nr_nodes - 1, prior );

        balance( T );
    }
}

char kth_element( Treap *T, int position )
{
    if ( T == NIL ) return '+';

    if ( T->st->nr_nodes + 1 == position ) return T->key;
    if ( position <= T->st->nr_nodes ) return kth_element( T->st, position );
    else                               return kth_element( T->dr, position - T->st->nr_nodes - 1 );
}

void afis( Treap *T )
{
    if ( T == NIL ) return;
    afis( T->st );
    cout << T->key;
    afis( T->dr );
}

string s;
int Q;

int main()
{
    initTreap();

    cin.sync_with_stdio( false );
    cout.sync_with_stdio( false );

    cin >> Q;

    while ( Q-- )
    {
        char tip;
        int ind, dim;

        cin >> tip;

        if ( tip == '+' )
        {
            cin >> ind >> s;

            for ( int i = 0; i < s.size(); ++i )
                insert( root, s[i], ind + i + 1 );
        }
        else
        {
            cin >> ind >> dim;

            for ( int i = 0; i < dim; ++i )
                cout << kth_element( root, ind + i );

            cout << "\n";
        }
    }

    return 0;
}
