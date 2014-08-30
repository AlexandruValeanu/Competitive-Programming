#include <bits/stdc++.h>

using namespace std;

long long T, R, K;

int vis[30];

int main()
{
    ///ifstream cin("data.in");

    string s;

    getline( cin, s );

    for ( auto x: s )
    {
        if ( !isalpha( x ) ) continue;

        vis[ tolower( x ) - 'a' ]++;
    }

    int valid = 1;

    for ( int i = 0; i < 26; ++i )
        if ( vis[i] == 0 )
        {
            valid = 0;
        }

    if ( valid )
        cout << "pangram";
    else
        cout << "not pangram";

    return 0;
}
