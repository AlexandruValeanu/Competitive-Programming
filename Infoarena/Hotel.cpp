#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
public:

    SegmentTree(){}

    SegmentTree( const int _N )
    {
        N = _N;

        best = vector <int>( 4 * N );
        prefix = vector <int>( 4 * N );
        suffix = vector <int>( 4 * N );

        build( 1, 1, N );
    }

    void update( int x, int y, int v )
    {
        update( 1, 1, N, x, y, v );
    }

    int query()
    {
        return best[1];
    }

private:

    vector <int> best, prefix, suffix;
    int N;

    void build( int nod, int st, int dr )
    {
        best[nod] = suffix[nod] = prefix[nod] = dr - st + 1;

        if ( st != dr )
        {
            int m = ( st + dr ) / 2;

            build( 2 * nod, st, m );
            build( 2 * nod + 1, m + 1, dr );
        }
    }

    void reinit( int nod, int val )
    {
        prefix[nod] = suffix[nod] = best[nod] = val;
    }

    void lazy_update( int nod, int st, int dr )
    {
        if ( best[nod] == 0 )
        {
            reinit( 2 * nod, 0 );
            reinit( 2 * nod + 1, 0 );
        }

        if ( best[nod] == dr - st + 1 )
        {
            int m = ( st + dr ) / 2;

            reinit( 2 * nod, m - st + 1 );
            reinit( 2 * nod + 1, dr - m );
        }
    }

    void update( int nod, int st, int dr, int st_q, int dr_q, int val )
    {
        if ( st_q <= st && dr <= dr_q )
        {
            reinit( nod, ( dr - st + 1 ) * val );
        }
        else
        {
            lazy_update( nod, st, dr );

            int m = ( st + dr ) / 2;

            if ( st_q <= m ) update( 2 * nod, st, m, st_q, dr_q, val );
            if ( m < dr_q )  update( 2 * nod + 1, m + 1, dr, st_q, dr_q, val );

            prefix[nod] = prefix[2 * nod];

            if ( prefix[2 * nod] == m - st + 1 )
                prefix[nod] += prefix[2 * nod + 1];

            suffix[nod] = suffix[2 * nod + 1];

            if ( suffix[2 * nod + 1] == dr - m )
                suffix[nod] += suffix[2 * nod];

            best[nod] = max( best[2 * nod], best[2 * nod + 1] );
            best[nod] = max( best[nod], suffix[2 * nod] + prefix[2 * nod + 1] );
        }
    }
};

int N, P;

int main()
{
    ifstream in("hotel.in");
    ofstream out("hotel.out");

    in.sync_with_stdio( false );

    in >> N >> P;

    SegmentTree S( N );

    while ( P-- )
    {
        int c, i, M;

        in >> c;

        if ( c == 1 )
        {
            in >> i >> M;

            S.update( i, i + M - 1, 0 );
        }

        if ( c == 2 )
        {
            in >> i >> M;

            S.update( i, i + M - 1, 1 );
        }

        if ( c == 3 )
        {
            out << S.query() << "\n";
        }
    }

    return 0;
}
