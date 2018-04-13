#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("subset2.in");
    ofstream out("subset2.out");

    int N, K;

    in >> N >> K;

    if ( K & 1 )
    {
        out << 1 + min( K / 2, N % K ) * ( N / K + 1 ) + ( K / 2 - min( K / 2, N % K ) ) * ( N / K );
    }
    else
    {
        out << 2 + min( K / 2 - 1, N % K ) * ( N / K + 1 ) + ( K / 2 - 1 - min( K / 2 - 1, N % K ) ) * ( N / K );
    }

    return 0;
}
