#include <bits/stdc++.h>

using namespace std;

char *str;
int N;

int main()
{
    ifstream in("numar3.in");
    ofstream out("numar3.out");

    in >> N;

    char last;
    int highInversionPos = 0;
    char ch;

    in >> last;

    for ( int i = 2; i <= N; ++i )
    {
        in >> ch;

        if ( ch > last )
            highInversionPos = i - 1;

        last = ch;
    }

    in.close();
    in.open("numar3.in");

    in >> N;
    int dim = 0;

    str = new char[N - highInversionPos + 2];

    for ( int i = 1; i < highInversionPos; ++i )
    {
        in >> ch;
        out << ch;
    }

    for ( int i = highInversionPos; i <= N; ++i )
    {
        in >> ch;
        str[dim++] = ch;
    }

    next_permutation(str, str + dim);

    str[dim] = '\0';
    out << str;

    return 0;
}
