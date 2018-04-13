#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
long long infinit = (long long)60000 * 100000;
 
typedef long long Type;
 
class Node
{
public:
 
    Type value, lazy, sum;
    unsigned position;
 
    Node()
    {
        value = Type();
        lazy = Type();
        sum = Type();
        position = infinit;
    }
 
    Node( Type _value, Type _sum, unsigned _position )
    {
        value = _value;
        sum = _sum;
        position = _position;
    }
};
 
class SegmentTree
{
public:
 
    SegmentTree( const unsigned _N, const vector <Type> &v )
    {
        N = _N;
 
        Arb = vector <Node> ( 4 * N );
 
        build( 1, 0, N - 1, v );
    }
 
    void update_interval( unsigned x, unsigned y, Type val )
    {
        update_interval( 1, 0, N - 1, x, y, val );
    }
 
    void update_position( unsigned pos, Type val )
    {
        update_position( 1, 0, N - 1, pos, val );
    }
 
    Node query( unsigned x, unsigned y )
    {
        return query( 1, 0, N - 1, x, y );
    }
 
private:
 
    vector <Node> Arb;
    unsigned N;
 
    unsigned LeftSon( unsigned node )
    {
        return 2 * node;
    }
 
    unsigned RightSon( unsigned node )
    {
        return 2 * node + 1;
    }
 
    void lazy_update( unsigned node )
    {
        if ( Arb[node].lazy != Type() )
        {
            Arb[LeftSon( node )].lazy += Arb[node].lazy;
            Arb[LeftSon( node )].value += Arb[node].lazy;
 
            Arb[RightSon( node )].lazy += Arb[node].lazy;
            Arb[RightSon( node )].value += Arb[node].lazy;
 
            Arb[node].lazy = Type();
        }
    }
 
    void update_minim( unsigned node )
    {
        if ( Arb[LeftSon( node )].value <= Arb[RightSon( node )].value )
        {
            Arb[node].value = Arb[LeftSon( node )].value;
            Arb[node].position = Arb[LeftSon( node )].position;
        }
        else
        {
            Arb[node].value = Arb[RightSon( node )].value;
            Arb[node].position = Arb[RightSon( node )].position;
        }
    }
 
    Type real_value( unsigned node, unsigned dim )
    {
        return Arb[node].sum + Arb[node].lazy * ( dim );
    }
 
    void build( unsigned node, unsigned st, unsigned dr, const vector<Type> &v )
    {
        Arb[node].lazy = Type();
        Arb[node].value = Type();
        Arb[node].sum = Type();
        Arb[node].position = infinit;
 
        if ( st == dr )
        {
            Arb[node].value = v[st];
            Arb[node].sum = v[st];
            Arb[node].position = st;
        }
        else
        {
            unsigned m = ( st + dr ) / 2;
 
            build( LeftSon( node ), st, m, v );
            build( RightSon( node ), m + 1, dr, v );
 
            update_minim( node );
            Arb[node].sum = real_value( 2 * node, m - st + 1 ) + real_value( 2 * node + 1, dr - m );
        }
    }
 
    void update_interval( unsigned node, unsigned st, unsigned dr, unsigned st_q, unsigned dr_q, Type val )
    {
        if ( st_q <= st && dr <= dr_q )
        {
            Arb[node].value += val;
            Arb[node].lazy += val;
        }
        else
        {
            unsigned m = ( st + dr ) / 2;
 
            lazy_update( node );
 
            if ( st_q <= m ) update_interval( LeftSon( node ), st, m, st_q, dr_q, val );
            if (  m < dr_q ) update_interval( RightSon( node ), m + 1, dr, st_q, dr_q, val );
 
            update_minim( node );
            Arb[node].sum = real_value( 2 * node, m - st + 1 ) + real_value( 2 * node + 1, dr - m );
        }
    }
 
    void update_position( unsigned node, unsigned st, unsigned dr, unsigned pos, Type val )
    {
        if ( st == dr )
        {
            Arb[node].value = val;
            Arb[node].lazy = 0;
        }
        else
        {
            lazy_update( node );
 
            unsigned m = ( st + dr ) / 2;
 
            if ( pos <= m ) update_position( LeftSon( node ), st, m, pos, val );
            else            update_position( RightSon( node ), m + 1, dr, pos, val );
 
            update_minim( node );
            Arb[node].sum = real_value( 2 * node, m - st + 1 ) + real_value( 2 * node + 1, dr - m );
        }
    }
 
    Node query( unsigned node, unsigned st, unsigned dr, unsigned st_q, unsigned dr_q )
    {
        if ( st_q <= st && dr <= dr_q )
        {
            return Node( Arb[node].value, real_value( node, dr - st + 1 ), Arb[node].position );
        }
        else
        {
            lazy_update( node );
 
            Node sol( infinit, infinit, infinit );
 
            unsigned m = ( st + dr ) / 2;
 
            Type totalSum = Type();
 
            if ( st_q <= m )
            {
                Node p = query( LeftSon( node ), st, m, st_q, dr_q );
 
                if ( p.value < sol.value )
                    sol = p;
 
                totalSum += p.sum;
            }
 
            if ( m < dr_q )
            {
                Node p = query( RightSon( node ), m + 1, dr, st_q, dr_q );
 
                if ( p.value < sol.value )
                   sol = p;
 
                totalSum += p.sum;
            }
 
            return Node( sol.value, totalSum, sol.position );
        }
    }
};
 
unsigned N;
vector <long long> v;
 
int main()
{
    ifstream in("biscuiti.in");
    ofstream out("biscuiti.out");
 
    in.sync_with_stdio( false );
 
    in >> N;
 
    long long initSum = 0, finalSum = 0;
 
    for ( unsigned i = 0, a; i < N; ++i )
    {
        in >> a;
        initSum += a;
        v.push_back( a );
    }
 
    SegmentTree ST( N, v );
 
    unsigned n = N;
 
    for ( unsigned k = 1; k <= n; ++k )
    {
        Node p = ST.query( 0, N - 1 );
 
        finalSum += p.value;
 
        ST.update_position( p.position, infinit );
 
        if ( p.position != 0 )
            ST.update_interval( 0, p.position - 1, k );
    }
 
    out << finalSum - initSum << "\n";
 
    return 0;
}
