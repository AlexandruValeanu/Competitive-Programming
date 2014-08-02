#include <bits/stdc++.h>

using namespace std;

string s;
int vis[300];

int main()
{
    cin >> s;

    for ( auto x: s )
        vis[x]++;

    for ( int i = 250; i >= 0; i-- )
    {
        if ( vis[i] )
        {
            while ( vis[i] )
            {
                cout << char( i );
                vis[i]--;
            }

            break;
        }
    }

    return 0;
}
