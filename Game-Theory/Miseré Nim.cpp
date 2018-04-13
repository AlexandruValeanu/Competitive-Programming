#include <bits/stdc++.h>

using namespace std;

/**
    Name: Miseré Nim
    Description: There are a finite number of heaps.
                 The two players alternate taking any number of objects from any single one of the heaps.
                 The one that removes the last object loses.

    Strategy: If all piles have one object each. If the number of heaps is even the first wins.
              If there is exactly one heap with more than 1 object, the first wins.
              If there are more: => Nim( who wins in normal Nim wins in Miseré Nim ).
**/

const int Nmax = 100;

int heap[Nmax];
int NumberOfHeaps;

int main()
{
    cin >> NumberOfHeaps;

    int xorsum = 0;
    int nrOne = 0;
    int nrMoreThanOne = 0;

    for ( int i = 0; i < NumberOfHeaps; ++i )
    {
        cin >> heap[i];

        if ( heap[i] == 1 )
            nrOne++;

        if ( heap[i] > 1 )
            nrMoreThanOne++;

        xorsum ^= heap[i];
    }

    if ( nrOne == NumberOfHeaps )
    {
        if ( nrOne % 2 == 0 )
            cout << "First";
        else
            cout << "Second";
    }
    else
    {
        if ( nrMoreThanOne == 1 )
            cout << "First";
        else
        {
            if ( xorsum > 0 )
                cout << "First";
            else
                cout << "Second";
        }
    }

    return 0;
}
