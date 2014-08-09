#include <bits/stdc++.h>

using namespace std;

/**
    Name: Nim
    Description: There are a finite number of heaps.
                 The two players alternate taking any number of objects from any single one of the heaps.
                 The goal is to be the last to take an object.
**/

const int Nmax = 100;

int heap[Nmax];
int NumberOfHeaps;

int main()
{
    cin >> NumberOfHeaps;

    int xorsum = 0;

    for ( int i = 0; i < NumberOfHeaps; ++i )
    {
        cin >> heap[i];

        xorsum ^= heap[i];
    }

    if ( xorsum == 0 )
    {
        cout << "Second wins!\n";
        return 0;
    }

    cout << "First wins!\n";

    for ( int i = 0; i < NumberOfHeaps; ++i )
        if ( heap[i] >= ( heap[i] ^ xorsum ) )
        {
            cout << "Move " << ( heap[i] - ( heap[i] ^ xorsum ) ) << " stones from " << i << " heap!\n";
            break;
        }

    return 0;
}
