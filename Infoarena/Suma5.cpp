#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 1;

struct Node
{
    long long lazy;
    long long sumaInt, sumaQuery;
    int capatSt, capatDr;

    Node()
    {
        lazy = sumaInt = sumaQuery = 0;
        capatSt = capatDr = 0;
    }

    long long real_sum() const
    {
        return sumaInt + 1LL * ( capatDr - capatSt + 1 ) * lazy;
    }

    long long real_sum_query() const
    {
        int lg = capatDr - capatSt + 1;
        long long s = 1LL * lg * ( lg + 1 ) / 2;

        return sumaQuery + s * lazy;
    }

    void combine( const Node A, const Node B )
    {
        this->sumaInt = A.real_sum() + B.real_sum();

        this->capatSt = A.capatSt;
        this->capatDr = B.capatDr;

        this->sumaQuery = A.real_sum_query() + ( B.real_sum_query() + 1LL * ( A.capatDr - A.capatSt + 1 ) * B.real_sum() );
    }
};

Node A[4 * Nmax];
int value[Nmax];
int N, M;

void build( int nod, int st, int dr )
{
    if ( st == dr )
    {
        A[nod].sumaInt = A[nod].sumaQuery = value[st];
        A[nod].capatSt = A[nod].capatDr = st;
    }
    else
    {
        int m = ( st + dr ) / 2;

        build( 2 * nod, st, m );
        build( 2 * nod + 1, m + 1, dr );

        A[nod].combine( A[2 * nod], A[2 * nod + 1] );
     }
}

void lazy_update( int nod )
{
    if ( A[nod].lazy )
    {
        A[2 * nod].lazy += A[nod].lazy;
        A[2 * nod + 1].lazy += A[nod].lazy;
        A[nod].lazy = 0;
    }
}

void update( int nod, int st, int dr, int st_q, int dr_q, int val )
{
    if ( st_q <= st && dr <= dr_q )
    {
        A[nod].lazy += val;
    }
    else
    {
        lazy_update( nod );

        int m = ( st + dr ) / 2;

        if ( st_q <= m )
            update( 2 * nod, st, m, st_q, dr_q, val );

        if ( m < dr_q )
            update( 2 * nod + 1, m + 1, dr, st_q, dr_q, val );

        A[nod].combine( A[2 * nod], A[2 * nod + 1] );
    }
}

Node query( int nod, int st, int dr, int st_q, int dr_q )
{
    if ( st_q <= st && dr <= dr_q )
    {
        return A[nod];
    }
    else
    {
        lazy_update( nod );

        int m = ( st + dr ) / 2;
        Node sol;

        if ( st_q <= m && m < dr_q )
        {
            Node a = query( 2 * nod, st, m, st_q, dr_q );
            Node b = query( 2 * nod + 1, m + 1, dr, st_q, dr_q );

            sol.combine( a, b );
        }
        else
        {
            if ( st_q <= m )
                sol = query( 2 * nod, st, m, st_q, dr_q );
            else
                sol = query( 2 * nod + 1, m + 1, dr, st_q, dr_q );
        }

        A[nod].combine( A[2 * nod], A[2 * nod + 1] );

        return sol;
    }
}

int main()
{
    ifstream in("suma5.in");
    ofstream out("suma5.out");

    in >> N >> M;

    for ( int i = 1; i <= N; ++i )
        in >> value[i];

    build( 1, 1, N );

    while ( M-- )
    {
        int tip, x, y, z;

        in >> tip;

        if ( tip == 0 )
        {
            in >> x >> y >> z;
            update( 1, 1, N, x, y, z );
        }
        else
        {
            in >> x >> y;
            out << query( 1, 1, N, x, y ).real_sum_query() << "\n";
        }
    }

    return 0;
}
