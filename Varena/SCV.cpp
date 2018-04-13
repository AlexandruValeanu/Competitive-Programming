#include <bits/stdc++.h>

using namespace std;

int C, T, M, X;

int findDays( int nrKg, int nrRobots )
{
    if ( nrKg >= X )
        return 0;

    int d = ( X - nrKg ) / ( nrRobots * M );

    if ( ( X - nrKg ) % ( nrRobots * M ) )
        d++;

    return d;
}

int greedy()
{
    int nrKg = 0;
    int nrRobots = 1;
    int day = 0;

    while( nrKg < X )
    {
        if ( nrKg < C )
        {
            day++;
            nrKg += nrRobots * M;
        }
        else /// 2 optiuni
        {
            int limita = min( 1LL * ( 1LL * nrKg - 1LL * C + 1LL * T * M * nrRobots ), 1LL * X );

            int c1 = findDays( nrKg, nrRobots );
            int c2 = T + findDays( limita, nrRobots + 1 );

            if ( c1 < c2 )
            {
                day++;
                nrKg += nrRobots * M;
            }
            else
            {
                day += T;
                nrKg = limita;
                nrRobots++;
            }
        }
    }

    return day;
}

int main()
{
    ifstream in("scv.in");
    ofstream out("scv.out");

    ios_base::sync_with_stdio( false );

    in >> C >> T >> M >> X;
    out << greedy() << "\n";

    in.close();
    out.close();

    return 0;
}
