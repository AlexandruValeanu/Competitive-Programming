#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Lmax = 1e5 + 2;

char S[Lmax];
int SA[Lmax];
int N;

int cmp( int i, int j )
{
    return strcmp( S + i, S + j ) < 0;
}

void buildSuffixArray()
{
    for ( int i = 0; i < N; ++i )
            SA[i] = i;

    sort( SA, SA + N, cmp );
}

int main()
{
    cin.sync_with_stdio( false );

    cin >> S;

    N = strlen( S );

    buildSuffixArray();

    for ( int i = 0; i < N; ++i )
            cout << SA[i] << "\n";

    return 0;
}
