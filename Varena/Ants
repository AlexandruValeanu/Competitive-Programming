#include <bits/stdc++.h>

using namespace std;

const int Nmax = 50000 + 1;
const int Mmax = 100000 + 1;

struct node
{
    long long sum;
    long long lazy;

    node *st, *dr;

    node()
    {
        sum = lazy = 0;
        st = dr = NULL;
    }
};

node *Arb[Nmax];
long long A[Mmax];
int N, M;
int P, X, Y, V, Z, T;
int L, R, I, J;
long long S;

node* build( int st, int dr )
{
    node *ans = new node();

    if ( st == dr )
    {
        ans->sum = A[st];
    }
    else
    {
        int m = ( st + dr ) / 2;

        ans->st = build( st, m );
        ans->dr = build( m + 1, dr );

        ans->sum = ans->st->sum + ans->dr->sum;
    }

    return ans;
}

node* createArb( node *root, int st, int dr, int st_q, int dr_q, int v )
{
    node *ans = new node();

    if ( st_q <= st && dr <= dr_q )
    {
        ans->sum = root->sum + v * ( dr - st + 1 );
        ans->lazy = root->lazy + v;
        ans->st = root->st;
        ans->dr = root->dr;
    }
    else
    {
        ans->lazy = root->lazy;

        int m = ( st + dr ) / 2;

        if ( st_q <= m )
            ans->st = createArb( root->st, st, m, st_q, dr_q, v );
        else
            ans->st = root->st;

        if ( m < dr_q )
            ans->dr = createArb( root->dr, m + 1, dr, st_q, dr_q, v );
        else
            ans->dr = root->dr;

        ans->sum = ans->st->sum + ans->dr->sum + ans->lazy * ( dr - st + 1 );
    }

    return ans;
}

long long query( node *root, int st, int dr, int st_q, int dr_q )
{
    if ( st_q <= st && dr <= dr_q )
    {
        return root->sum;
    }
    else
    {
        int m = ( st + dr ) / 2;
        long long sol = 0;

        if ( st_q <= m )
            sol += query( root->st, st, m, st_q, dr_q );

        if ( m < dr_q )
            sol += query( root->dr, m + 1, dr, st_q, dr_q );

        int l = max( st_q, st );
        int r = min( dr, dr_q );

        sol += root->lazy * ( r - l + 1 );

        return sol;
    }
}

int main()
{
    ifstream in("ants.in");
    ofstream out("ants.out");

    in >> N >> M;

    for ( int i = 1; i <= M; ++i )
        in >> A[i];

    Arb[1] = build( 1, M );

    for ( int i = 2; i <= N; ++i )
    {
        in >> P >> X >> Y >> V >> Z >> T;

        L = ( ( X + S ) % M ) + 1;
        R = ( ( Y + S ) % M ) + 1;
        I = ( ( Z + S ) % M ) + 1;
        J = ( ( T + S ) % M ) + 1;

        Arb[i] = createArb( Arb[P], 1, M, L, R, V );

        S = query( Arb[i], 1, M, I, J );

        out << S << "\n";

        S %= M;
    }

    return 0;
}
