#include <bits/stdc++.h>

using namespace std;

const int Nmax = 5e4 + 1;

class SegmentTree
{
public:

    SegmentTree(){}

    SegmentTree( const int _N )
    {
        N = _N;
        A = vector<int>( 4 * N );
        fill( A.begin(), A.end(), 0 );
    }

    void update( int pos, int val )
    {
        update( 1, 1, N, pos, val );
    }

    int query( int x, int y )
    {
        return query( 1, 1, N, x, y );
    }

private:

    int N;
    vector <int> A;

    void update( int nod, int st, int dr, int pos, int val )
    {
        if ( st == dr )
        {
            A[nod] = val;
        }
        else
        {
            int m = ( st + dr ) / 2;

            if ( pos <= m ) update( 2 * nod, st, m, pos, val );
            else            update( 2 * nod + 1, m + 1, dr, pos, val );

            A[nod] = max( A[2 * nod], A[2 * nod + 1] );
        }
    }

    int query( int nod, int st, int dr, int st_q, int dr_q )
    {
        if ( st_q <= st && dr <= dr_q )
        {
            return A[nod];
        }
        else
        {
            int m = ( st + dr ) / 2;
            int sol = 0;

            if ( st_q <= m ) sol = max( sol, query( 2 * nod, st, m, st_q, dr_q ) );
            if (  m < dr_q ) sol = max( sol, query( 2 * nod + 1, m + 1, dr, st_q, dr_q ) );

            return sol;
        }
    }
};

SegmentTree ST;
int tata[Nmax], maxim[Nmax], rang[Nmax], value[Nmax];
vector <int> Arb[Nmax];
int where[Nmax], MaxArb[Nmax];

int N, S, M;

void update_val( int x, int val )
{
    if ( x && MaxArb[x] < val )
    {
        MaxArb[x] = val;
        ST.update( x, val );
    }
}

int Find( int x )
{
    int y, R, mm = maxim[x];

    for ( R = x; R != tata[R]; R = tata[R] )
    {
        mm = max( mm, maxim[R] );
    }

    maxim[R] = max( maxim[R], mm );

    while ( x != tata[x] )
    {
        y = tata[x];
        tata[x] = R;
        x = y;
    }

    return R;
}

void Union( int x, int y )
{
    if ( rang[x] > rang[y] )
    {
        tata[y] = x;

        if ( where[x] == 0 )
            where[x] = where[y];

        maxim[x] = max( maxim[x], maxim[y] );
    }
    else
    {
        tata[x] = y;

        if ( where[y] == 0 )
             where[y] = where[x];

        maxim[y] = max( maxim[y], maxim[x] );
    }

    update_val( where[x], maxim[x] );
    update_val( where[y], maxim[y] );

    if ( rang[x] == rang[y] )
        rang[x]++;
}

int main()
{
    ifstream in("tabara2.in");
    ofstream out("tabara2.out");

    in.sync_with_stdio( false );

    in >> N >> S >> M;

    for ( int i = 1; i <= S; ++i )
    {
        in >> value[i];
        tata[i] = i;
        rang[i] = 1;
        maxim[i] = value[i];
    }

    ST = SegmentTree( N );

    for ( int l = 1; l <= M; ++l )
    {
        char ch;
        int tip, i, j;

        in >> ch;

        if ( ch == 'U' )
        {
            in >> tip >> i >> j;

            int Fi = Find( i );
            int Fj = Find( j );

            if( tip == 1 )
            {
                if ( Fi != Fj )
                    Union( Fi, Fj );
            }
            else
            {
                where[ Fj ] = i;
                update_val( i, maxim[Fj] );
            }
        }
        else
        {
            in >> i >> j;

            out << ST.query( i, j ) << "\n";
        }
    }

    return 0;
}
