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

const int INF = ( 1 << 30 ) + 1;
const double EPS = 1e-9;

const int Nmax = 1e4 + 2;

const int LgMax = log2(Nmax) + 1;

using namespace std;

typedef int Type;

struct Treap
{
    int priority, nr_nodes;
    int rev;
    Type key;

    Treap *st, *dr;

    Treap( const Type _key, const int _priority, const int _nr_nodes, Treap *_st, Treap *_dr )
    {
        key = _key;
        priority = _priority;
        nr_nodes = _nr_nodes;
        st = _st;
        dr = _dr;
        rev = 0;
    }
};

Treap *NIL, *root;

void initTreap()
{
    srand( time( NULL ) );
    NIL = new Treap( Type(), 0, 0, NULL, NULL );
    root = NIL;
}

void lazy( Treap *&T )
{
    if ( T != NIL && T->rev )
    {
        T->st->rev ^= 1;
        T->dr->rev ^= 1;
        T->rev = 0;

        swap( T->st, T->dr );
    }
}

void update( Treap *&T )
{
    lazy( T ); lazy( T->st ); lazy( T->dr );

    T->nr_nodes = 1 + T->st->nr_nodes + T->dr->nr_nodes;
}

void rotateRight( Treap *&T )
{
    lazy( T ); lazy( T->st ); lazy( T->dr );

    Treap *aux = T->st;
    T->st = aux->dr;
    aux->dr = T;

    update( T );
    update( aux );

    T = aux;
}

void rotateLeft( Treap *&T )
{
    lazy( T ); lazy( T->st ); lazy( T->dr );

    Treap *aux = T->dr;
    T->dr = aux->st;
    aux->st = T;

    update( T );
    update( aux );

    T = aux;
}

void balance( Treap *&T )
{
    lazy( T );

    if ( T->st->priority > T->priority )
        rotateRight( T );

    if ( T->dr->priority > T->priority )
        rotateLeft( T );

    update( T );
}

void insert( Treap *&T, Type key, int pos, int p = rand() % INF )
{
    if ( T == NIL )
    {
        T = new Treap( key, p, 1, NIL, NIL );
    }
    else
    {
        lazy( T ); lazy( T->st ); lazy( T->dr );

        if ( pos <= T->st->nr_nodes + 1 )
            insert( T->st, key, pos, p );
        else
            insert( T->dr, key, pos - 1 - T->st->nr_nodes, p );

        balance( T );
    }
}

void erase( Treap *&T, int pos )
{
    if ( T == NIL ) return;

    lazy( T ); lazy( T->st ); lazy( T->dr );

    if ( pos <= T->st->nr_nodes )
        erase( T->st, pos );
    else
        if ( pos > T->st->nr_nodes + 1 )
            erase( T->dr, pos - T->st->nr_nodes - 1 );
        else
        {
            if ( T->st == NIL && T->dr == NIL )
            {
                delete T;
                T = NIL;
            }
            else
            {
                if ( T->st->priority > T->dr->priority )
                {
                    rotateRight( T );
                    erase( T->dr, pos - 1 - T->st->nr_nodes );
                }
                else
                {
                    rotateLeft( T );
                    erase( T->st, pos );
                }
            }
        }

    if ( T != NIL )
        update( T );
}

int kth_element( Treap *T, int pos )
{
    lazy( T );

    if ( T->st->nr_nodes + 1 == pos ) return T -> key;
    if ( T->st->nr_nodes >= pos )     return kth_element( T->st, pos );
    else                              return kth_element( T->dr, pos - T->st->nr_nodes - 1 );
}

void split( Treap *&root, Treap *&L, Treap *&R, int pos )
{
    insert( root, 1, pos, INF );
    L = root->st;
    R = root->dr;
    delete root;
    root = NIL;
}

void merge( Treap *&root, Treap *&L, Treap *&R )
{
    root = new Treap( 0, INF, 1, L, R );
    update( root );
    erase( root, root->st->nr_nodes + 1 );
}

void reverse( int i, int j )
{
    Treap *tmp, *T1, *T2, *T3;

    split( root, tmp, T3, j + 1 );
    split( tmp, T1, T2, i );
    T2->rev = 1;
    merge( tmp, T1, T2 );
    merge( root, tmp, T3 );
}

void erase( int i, int j )
{
    Treap *L, *R, *aux1, *aux2;

    split( root, L, R, j + 1 );
    split( L, aux1, aux2, i );

    merge( root, aux1, R );
}

void inorder( Treap *T )
{
    if ( T == NIL )return;

    lazy( T ); lazy( T->st ); lazy( T->dr );

    inorder( T->st );
    printf("%d ", T->key);
    inorder( T->dr );
}

int N, M, a, b, c;

int main()
{
    FIN("secv8.in");
    FOUT("secv8.out");

    initTreap();

    int N, rev, k, x, y;
    char oper;

    read( N ); read( rev );

    while ( N-- )
    {
        scanf("%c ", &oper);

        switch ( oper )
        {
            case 'A':
            {
                read( k );
                printf("%d\n", kth_element( root, k ));
                break;
            }
            case 'D':
            {
                read( x ); read( y );
                erase( x, y );
                break;
            }
            case 'I':
            {
                read( x ); read( y );
                insert(root, y, x);
                break;
            }
            case 'R':
            {
                read( x ); read( y );
                reverse( x, y );
                break;
            }
        }

    }

    inorder( root );

    return 0;
}
