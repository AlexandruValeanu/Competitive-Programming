#include <bits/stdc++.h>

using namespace std;

vector<int> prefix( const string &str )
{
    string a = " " + str;

    int N = a.size() - 1;
    int k = 0;

    vector <int> pi( N + 1, 0 );

    for ( int i = 2; i <= N; ++i )
    {
        while ( k && a[k + 1] != a[i] ) k = pi[k];

        if ( a[k + 1] == a[i] )
            k++;

        pi[i] = k;
    }

    return pi;
}

int main()
{
    ifstream in("prefixe.in");
    ofstream out("prefixe.out");

    int Z;
    string str;

    in >> Z;

    while ( Z-- )
    {
        in >> str;

        vector <int> pi = prefix( str );

        for ( int i = 1; i <= (int)str.size(); ++i )
            out << pi[i] << " ";

        out << "\n";
    }

    return 0;
}
