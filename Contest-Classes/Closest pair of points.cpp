#include <bits/stdc++.h>

using namespace std;

class ClosestPair
{
public:

    ClosestPair(const vector< pair<int,int> >& a)
    {
        Points.resize( a.size() );
        tmp.resize( a.size() );

        for ( int i = 0; i < a.size(); ++i )
            Points[i] = a[i];

        sort( Points.begin(), Points.end() );
    }

    double solve()
    {
        return sqrt( rec( 0, Points.size() - 1 ) );
    }

private:

    typedef long long i64;

    vector < pair<int,int> > Points, tmp;

    i64 distance( const pair<int,int>& a, const pair<int,int>& b ) const
    {
        return 1LL * ( a.first - b.first ) * ( a.first - b.first ) +
               1LL * ( a.second - b.second ) * ( a.second - b.second );
    }

    i64 rec( int st, int dr )
    {
        if ( st >= dr )
            return 1e18;

        if ( st + 1 == dr )
        {
            if ( Points[st].second > Points[dr].second )
                swap( Points[st], Points[dr] );

            return distance( Points[st], Points[dr] );
        }
        else
        {
            int m = ( st + dr ) / 2;
            int mid = Points[m].first;
            i64 d1 = rec( st, m );
            i64 d2 = rec( m + 1, dr );
            i64 d = min( d1, d2 );

            int i = st, j = m + 1, k = st;

            while ( i <= m && j <= dr )
            {
                if ( Points[i].second <= Points[j].second )
                    tmp[ k++ ] = Points[ i++ ];
                else
                    tmp[ k++ ] = Points[ j++ ];
            }

            while ( i <= m ) tmp[ k++ ] = Points[ i++ ];
            while ( j <= dr ) tmp[ k++ ] = Points[ j++ ];

            for ( int i = st; i <= dr; ++i )
                Points[i] = tmp[i];

            int nr = 0;

            for ( int i = st; i <= dr; ++i )
            {
                if ( abs( Points[i].first - mid ) <= d )
                    tmp[ nr++ ] = Points[i];
            }

            for ( int i = 0; i < nr; ++i )
                for ( int j = i - 1, k = 8; j >= 0 && k > 0; j--, k-- )
                    d = min( d, distance( tmp[i], tmp[j] ) );

            return d;
        }
    }
};

int main()
{
    return 0;
}
