#include <iostream>
#include <fstream>
#include <cstring>
#include <bitset>

using namespace std;

const int Nmax = 5e5 + 2;
const int LgMax = 20;

bitset <( 1 << LgMax ) + 1> vis;
char S[Nmax];
string s;
int N, posR;

void add( int lg )
{
    for ( int i = 1; i + lg - 1 <= N; ++i )
    {
        int sum = 1;

        for ( int j = 1; j <= lg; ++j )
        {
            sum = sum * 2 + ( S[i + j - 1] - 'a' );
        }

        vis[sum] = 1;
    }
}

int valid( int l )
{
    for ( int i = posR; i <= ( 1 << ( l + 1 ) ) - 1; ++i )
    {
        if ( vis[i] == 0 )
        {
            int apar = 0;

            for ( int j = 31; j >= 0; j-- )
            {
                if ( i & ( 1 << j ) )
                {
                    if ( apar )
                        s += "b";

                    apar = 1;
                }
                else
                {
                    if ( apar )
                        s += "a";
                }
            }

            return 1;
        }
    }

    posR = ( 1 << ( l + 1 ) );

    return 0;
}

int main()
{
    ifstream in("string.in");
    ofstream out("string.out");

    in.sync_with_stdio( false );

    in >> N >> ( S + 1 );

    posR = 2;

    for ( int lg = 1, l = 1; lg <= N; lg *= 2, l++ )
    {
        add( l );

        if ( valid( l ) )
            break;
    }

    out << s.size() << "\n";
    out << s << "\n";

    return 0;
}
