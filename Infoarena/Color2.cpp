#include <bits/stdc++.h>

using namespace std;

const int Nmax = 16000 + 1;

int sons[Nmax][2];

bool winUp[Nmax];
bool winDown[Nmax];
int nodes[Nmax];

int N;

void dfsDown(int nod)
{
    if ( sons[nod][0] == 0 )
        winDown[nod] = true;
    else
    {
        dfsDown(sons[nod][0]);
        dfsDown(sons[nod][1]);

        winDown[nod] = 1 ^ (winDown[ sons[nod][0] ] | winDown[ sons[nod][1] ]);
    }
}

void dfsUp(int nod, int father, int brother)
{
    if ( nod == 1 )
    {
        winUp[1] = true;

        if ( sons[1][0] )
        {
            dfsUp(sons[1][0], 1, sons[1][1]);
            dfsUp(sons[1][1], 1, sons[1][0]);
        }
    }
    else
    {
        winUp[nod] = winDown[brother] | (1 ^ winUp[father]);

        if ( sons[nod][0] )
        {
            dfsUp(sons[nod][0], nod, sons[nod][1]);
            dfsUp(sons[nod][1], nod, sons[nod][0]);
        }
    }

}

int main()
{
    ifstream in("color2.in");
    ofstream out("color2.out");

    ios_base::sync_with_stdio(false);

    in >> N;

    for ( int i = 1; i < N; ++i )
    {
        int a, b;
        in >> a >> b;

        if ( sons[a][0] )
            sons[a][1] = b;
        else
            sons[a][0] = b;
    }

    dfsDown(1);
    dfsUp(1, 0, 0);

    for ( int i = 1; i <= N; ++i )
        if ( winDown[i] & winUp[i] )
            nodes[ ++nodes[0] ] = i;

    out << nodes[0] << "\n";

    for ( int i = 1; i <= nodes[0]; ++i )
        out << nodes[i] << " ";

    out << "\n";

    return 0;
}
