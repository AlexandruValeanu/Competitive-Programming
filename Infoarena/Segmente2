#include <bits/stdc++.h>

using namespace std;

#define Point pair<double,double>
#define x first
#define y second

const int Nmax = 5000 + 2;

Point P[Nmax];
int apart[Nmax], special[Nmax];
int N, K;

double dist( const Point A, const Point B)
{
    return ( A.x - B.x ) * ( A.x - B.x ) + ( A.y - B.y ) * ( A.y - B.y );
}

class class_cmp
{
public:

    bool operator () ( const pair<int,int> &A, const pair<int,int> &B ) const
    {
        return dist( P[A.first], P[A.second] ) < dist( P[B.first], P[B.second] );
    }
};

priority_queue < pair<int,int> , vector< pair<int,int> >, class_cmp> MinHeap;

int main()
{
    ifstream in("segmente2.in");
    ofstream out("segmente2.out");

    in >> N >> K;

    for ( int i = 1; i <= N; ++i )
        in >> P[i].x >> P[i].y;

    int c = 0;

    for ( int i = 1; i <= N; ++i )
        for ( int j = i + 1; j <= N; ++j )
        {
            if ( c < K )
            {
                MinHeap.push( pair<int,int>( i, j ) );
                c++;
            }
            else
            {
                pair<int,int> p = MinHeap.top();

                if ( dist( P[p.first], P[p.second] ) > dist( P[i], P[j] ) )
                {
                    MinHeap.pop();
                    MinHeap.push( pair<int,int>( i, j ) );
                }
            }
        }

    double sum = 0;
    int sol = 0;

    pair<int,int> p = MinHeap.top();

    double d = dist( P[p.first], P[p.second] );

    for ( int i = 1; i <= N; ++i )
        for ( int j = i + 1; j <= N; ++j )
        {
            if ( d == dist( P[i], P[j] ) )
            {
                sol++;
                special[i]++;
                special[j]++;
            }
        }

    vector <int> v;
    vector <int> a;
    c = 0;

    while ( MinHeap.size() )
    {
        pair<int,int> p = MinHeap.top();
        MinHeap.pop();

        sum += sqrt( dist( P[p.first], P[p.second] ) );

        v.push_back( p.first );
        v.push_back( p.second );

        if ( dist( P[p.first], P[p.second] ) == d )
        {
            c++;
            v.push_back( p.first );
            v.push_back( p.second );
        }
        else
        {
            a.push_back( p.first );
            a.push_back( p.second );
        }
    }

    if ( sol == c )
    {
        for ( auto x: v )
            apart[x] = 1;
    }
    else
    {
        for ( int i = 1; i <= N; ++i )
        {
            int cate_nu_apare = sol - special[i];

            if ( cate_nu_apare < c )
                apart[i] = 1;
        }
    }

    for ( auto x: a )
        apart[x] = 1;

    out << fixed << setprecision( 10 ) << sum << "\n";

    for ( int i = 1; i <= N; ++i )
        if ( apart[i] )
            out << i - 1 << "\n";

    return 0;
}
