#include <bits/stdc++.h>

const int Nmax = 1e5 + 2;

using namespace std;

int Left[Nmax], Right[Nmax], Parent[Nmax], Cost[Nmax], Maxim[Nmax], Revert[Nmax];

void lazy( int x )
{
    if ( Revert[x] )
    {
        Revert[x] = 0;
        swap( Left[x], Right[x] );

        if ( Left[x] != 0 ) Revert[ Left[x] ] ^= 1;
        if ( Right[x] != 0 ) Revert[ Right[x] ] ^= 1;
    }
}

void update( int p )
{
    Maxim[p] = Cost[p];
    if ( Left[p] ) Maxim[p] = max( Maxim[p], Maxim[ Left[p] ] );
    if ( Right[p] ) Maxim[p] = max( Maxim[p], Maxim[ Right[p] ] );
}

bool isRoot( int p )
{
    return ( !Parent[p] || ( Left[ Parent[p] ] != p && Right[ Parent[p] ] != p ) );
}

void Zig( int p )
{
    int q = Parent[p];
    int r = Parent[q];

    if ( ( Left[q] = Right[p] ) != 0 )
        Parent[ Left[q] ] = q;

    Right[p] = q;
    Parent[q] = p;

    if ( ( Parent[p] = r ) != 0 )
    {
        if ( Left[r] == q )
            Left[r] = p;
        else
            if ( Right[r] == q )
                Right[r] = p;
    }

    update( q );
}

void Zag( int p )
{
    int q = Parent[p];
    int r = Parent[q];

    if ( ( Right[q] = Left[p] ) != 0 )
        Parent[ Right[q] ] = q;

    Left[p] = q;
    Parent[q] = p;

    if ( ( Parent[p] = r ) != 0 )
    {
        if ( Left[r] == q )
            Left[r] = p;
        else
            if ( Right[r] == q )
                Right[r] = p;
    }

    update( q );
}

void splay( int p )
{
    while ( !isRoot( p ) )
    {
        int q = Parent[p];
        int r = Parent[q];

        if ( isRoot( q ) )
        {
            lazy( q );
            lazy( p );

            if ( Left[q] == p )
                Zig( p );
            else
                Zag( p );
        }
        else
        {
            lazy( r );
            lazy( q );
            lazy( p );

            if ( ( p == Left[q] ) == ( q == Left[r] ) )
            {
                if ( p == Left[q] )
                {
                    Zig( q );
                    Zig( p );
                }
                else
                {
                    Zag( q );
                    Zag( p );
                }
            }
            else
            {
                if ( p == Left[q] )
                    Zig( p );
                else
                    Zag( p );

                if ( p == Left[r] )
                    Zig( p );
                else
                    Zag( p );
            }
        }
    }

    lazy( p );
    update( p );
}

int expose( int p )
{
    int last = 0;

    for ( int x = p; x != 0; x = Parent[x] )
    {
        splay( x );
        Left[x] = last;
        last = x;
    }

    splay( p );

    return last;
}

void makeroot( int p )
{
    expose( p );
    Revert[p] ^= 1;
}

bool connected( int x, int y )
{
    if ( x == y )
        return true;

    expose( x );
    expose( y );

    return Parent[x] != 0;
}

int lca( int x, int y )
{
    expose( x );
    return expose( y );
}

void link( int x, int y )
{
    makeroot( x );
    Parent[x] = y;
}

void cut( int x, int y )
{
    makeroot( x );
    expose( y );
    Parent[ Right[y] ] = 0;
    Right[y] = 0;
}

int queryPath( int x, int y )
{
    makeroot( x );
    expose( y );

    return Maxim[y];
}

void updatePath( int x, int y, int value )
{
    makeroot( x );
    expose( y );
    Cost[y] = Maxim[y] = value;
}

int main()
{
    return 0;
}
