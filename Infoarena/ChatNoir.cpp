#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("chatnoir.in");
    ofstream out("chatnoir.out");

    int T, N, M, X, Y;

    in >> T;

    while ( T-- )
    {
        in >> N >> M >> X >> Y;

        if ( min( min( X - 1, Y - 1 ), min( N - X, M - Y ) ) <= 4 )
            out << "DA\n";
        else
            out << "NU\n";
    }

    return 0;
}
