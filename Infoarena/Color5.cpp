#include <bits/stdc++.h>

using namespace std;

ifstream in("color5.in");
ofstream out("color5.out");

int N;

void printEdge(int x, int y, int c)
{
    out << x << " " << y << " " << c << "\n";
}

int main()
{
    in >> N;

    if ( N == 3 )
    {
        out << "1\n";

        for ( int i = 0; i < N; ++i )
            printEdge(i, N, 1);

        for ( int i = 0; i < N; ++i )
            printEdge(i, (i + 1) % N, 1);
    }

    if ( 4 <= N && N <= 6 )
    {
        out << "2\n";

        for ( int i = 0; i < N; ++i )
            printEdge(i, N, 1 + (i & 1));

        for ( int i = 0; i < N; ++i )
             printEdge(i, (i + 1) % N, 1 + (i & 1));
    }

    if ( N >= 7 )
    {
        out << "3\n";

        for ( int i = 0; i < N; ++i )
            printEdge(i, N, 1 + (i & 1));

        for ( int i = 0; i < N; ++i )
             printEdge(i, (i + 1) % N, 3);
    }

    return 0;
}
