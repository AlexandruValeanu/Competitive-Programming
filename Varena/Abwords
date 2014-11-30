#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("abwords.in");
    ofstream out("abwords.out");

    int N, pw;

    in >> N;

    for ( pw = 1; pw <= N; pw <<= 1 );

    out << "A";

    if ( N % 2 )
        for ( int i = 2; i <= 1 + pw / 2; ++i )
            out << "B";
    else
        for ( int i = 2; i <= 2 + pw / 4; ++i )
            out << "B";

    out << "\n";

    for ( int i = 1; i <= pw - N; ++i )
        out << "2";

    for ( int i = 1; i <= N - pw / 2; ++i )
        out << "21";

    out << "\n";

    in.close();
    out.close();

    return 0;
}
