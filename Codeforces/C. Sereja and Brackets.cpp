#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e6 + 1;

struct Node
{
    int sol;
    int open;
    int closed;
};

Node A[4 * Nmax];
string str;
int N, M;

Node merge(const Node& left, const Node& right)
{
    Node ans = { 0, 0, 0 };

    int t = min( left.open, right.closed );

    ans.sol = left.sol + right.sol + t;
    ans.open = left.open + right.open - t;
    ans.closed = left.closed + right.closed - t;

    return ans;
}

void build(int nod, int st, int dr)
{
    if ( st == dr )
    {
        A[nod].sol = 0;
        A[nod].open = (str[st - 1] == '(');
        A[nod].closed = (str[st - 1] == ')');
    }
    else
    {
        int m = ( st + dr ) / 2;

        build(2 * nod, st, m);
        build(2 * nod + 1, m + 1, dr);

        A[nod] = merge(A[2 * nod], A[2 * nod + 1]);
    }
}

Node query(int nod, int st, int dr, int st_q, int dr_q)
{
    if ( st_q <= st && dr <= dr_q )
    {
        return A[nod];
    }
    else
    {
        int m = ( st + dr ) / 2;
        Node sol = { 0, 0, 0 };

        if ( st_q <= m )
            sol = merge(sol, query(2 * nod, st, m, st_q, dr_q) );

        if ( m < dr_q )
            sol = merge(sol, query(2 * nod + 1, m + 1, dr, st_q, dr_q) );

        return sol;
    }
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio( false );

    cin >> str;
    N = str.size();

    build( 1, 1, N );

    cin >> M;

    while ( M-- )
    {
        int a, b;

        cin >> a >> b;
        cout << 2 * query(1, 1, N, a, b).sol << "\n";
    }

    return 0;
}
