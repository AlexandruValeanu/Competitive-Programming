#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

const int Nmax = 100000;
const int MOD = 100003;

pair<int,int> pisteV[Nmax + 1], pisteO[Nmax + 1];

int xParc, yParc, xG, yG, xPr, yPr;
int nrVertical, nrOrizontal;
long long distX, distY;
int stX, drX;
int stY, drY;

void rotateIfNecessary()
{
    if ( xG > xPr )
    {
        xG = xParc - xG;
        xPr = xParc - xPr;

        for ( int i = 1; i <= nrVertical; ++i )
        {
            pisteV[i].first = xParc - pisteV[i].first;
            pisteV[i].second = xParc - pisteV[i].second;
        }
    }

    if ( yG > yPr )
    {
        yG = yParc - yG;
        yPr = yParc - yPr;

        for ( int i = 1; i <= nrOrizontal; ++i )
        {
            pisteO[i].first = yParc - pisteO[i].first;
            pisteO[i].second = yParc - pisteO[i].second;
        }
    }

    for ( int i = 1; i <= nrVertical; ++i )
    {
        if ( pisteV[i].first > pisteV[i].second )
            swap( pisteV[i].first, pisteV[i].second );
    }

    for ( int i = 1; i <= nrOrizontal; ++i )
    {
        if ( pisteO[i].first > pisteO[i].second )
            swap( pisteO[i].first, pisteO[i].second );
    }
}

void sortingAndReducing()
{
    sort( pisteV + 1, pisteV + nrVertical + 1 );
    sort( pisteO + 1, pisteO + nrOrizontal + 1 );

    /**int n = 0;

    for ( int i = 1; i <= nrVertical; ++i )
    {
        int j = i;

        while ( j + 1 <= nrVertical && pisteV[j].second == pisteV[j + 1].first ) j++;

        pisteV[ ++n ] = pair<int,int>( pisteV[i].first, pisteV[j].second );
        i = j;
    }

    nrVertical = n;

    n = 0;

    for ( int i = 1; i <= nrOrizontal; ++i )
    {
        int j = i;

        while ( j + 1 <= nrOrizontal && pisteO[j].second == pisteO[j + 1].first ) j++;

        pisteO[ ++n ] = pair<int,int>( pisteO[i].first, pisteO[j].second );
        i = j;
    }

    nrOrizontal = n;**/
}

long long Sqrt( long long nr )
{
    int p = 31;
    long long sol = 0;

    while ( p >= 0 )
    {
        long long x = sol + ( 1LL << p );

        if ( x * x <= nr )
            sol = x;

        p--;
    }

    return sol;
}

long long getDistance()
{
    long long dx = 0, dy = 0;

     for ( int i = 1; i <= nrVertical; ++i )
     {
        if ( xG <= pisteV[i].first && pisteV[i].second <= xPr )
        {
            dx += 1LL * ( pisteV[i].second - pisteV[i].first );

            if ( !stX ) stX = i;
                        drX = i;
        }
     }

    for ( int i = 1; i <= nrOrizontal; ++i )
    {
        if ( yG <= pisteO[i].first && pisteO[i].second <= yPr )
        {
            dy += 1LL * ( pisteO[i].second - pisteO[i].first );

            if ( !stY ) stY = i;
                        drY = i;
        }
    }

    distX = 1LL * ( xPr - xG ) - dx;
    distY = 1LL * ( yPr - yG ) - dy;

    return ( dx + dy + Sqrt( distX * distX + distY * distY ) );
}

int printNrSolutions()
{
    long long distanceToTrackVert = pisteV[stX].first - xG;
    long long distanceToTrackOriz = pisteO[stY].first - yG;

    int nrSol = 1;

    while ( stX <= drX && stY <= drY )
    {
        if ( distanceToTrackVert * distY == distanceToTrackOriz * distX )
        {
            nrSol *= 2;

            if ( nrSol >= MOD )
                nrSol -= MOD;

            stX++;
            distanceToTrackVert += 1LL * ( pisteV[stX].first - pisteV[stX - 1].second );

            stY++;
            distanceToTrackOriz += 1LL * ( pisteO[stY].first - pisteO[stY - 1].second );
        }
        else
        {
            if ( distanceToTrackVert * distY > distanceToTrackOriz * distX )
            {
                stY++;
                distanceToTrackOriz += 1LL * ( pisteO[stY].first - pisteO[stY - 1].second );
            }
            else
            {
                stX++;
                distanceToTrackVert += 1LL * ( pisteV[stX].first - pisteV[stX - 1].second );
            }
        }
    }

    return nrSol;
}

int modul( int a )
{
    if ( a > 0 )
        return a;
    else
        return -a;
}

int main()
{
    ifstream in("parc.in");
    ofstream out("parc.out");

    ios_base::sync_with_stdio( false );

    in >> xParc >> yParc >> xG >> yG >> xPr >> yPr;

    if ( xG == xPr || yG == yPr )
    {
        out << modul( xG - xPr ) + modul( yG - yPr ) << "\n";
        out << "1\n";

        return 0;
    }

    in >> nrVertical;

    for ( int i = 1; i <= nrVertical; ++i )
        in >> pisteV[i].first >> pisteV[i].second;

    in >> nrOrizontal;

    for ( int i = 1; i <= nrOrizontal; ++i )
        in >> pisteO[i].first >> pisteO[i].second;

    rotateIfNecessary();
    sortingAndReducing();

    out << getDistance() << "\n";
    out << printNrSolutions() << "\n";

    in.close();
    out.close();

    return 0;
}
