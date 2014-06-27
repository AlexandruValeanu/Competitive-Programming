#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
const ull BASE = 137;

const int Nmax = 1e5 + 1;

vector <int> Ind[Nmax];
unordered_map <int, int> INDEX;
vector < pair<int,int> > VP;

ull H[Nmax], Hpow[Nmax];
int A[Nmax];
bool erased[Nmax];
int N;

void pregen()
{
    Hpow[0] = 1;

    for ( int i = 1; i <= N; ++i )
        Hpow[i] = Hpow[i - 1] * BASE;

    for ( int i = 1; i <= N; ++i )
        H[i] = H[i - 1] * BASE + A[i];
}

ull getHash( int i, int j )
{
    return H[j] - H[i - 1] * Hpow[j - i + 1];
}

int cmp( const pair<int,int> &x, const pair<int,int> &y )
{
    int lg1 = x.second - x.first + 1;
    int lg2 = y.second - y.first + 1;

    if ( lg1 != lg2 )
        return lg1 < lg2;
    else
        return x.first < y.first;
}

int main()
{
    ///ifstream cin("data.in");

    cin.sync_with_stdio( false );

    cin >> N;

    int P = 0;

    for ( int i = 1; i <= N; ++i )
    {
        cin >> A[i];

        if ( INDEX[ A[i] ] == 0 )
            INDEX[ A[i] ] = ++P;

        Ind[ INDEX[ A[i] ] ].push_back( i );
    }

    pregen();

    for ( int elem = 1; elem <= P; ++elem )
    {
        for ( int i = 0; i < Ind[elem].size(); ++i )
            for ( int j = i + 1; j < Ind[elem].size(); ++j )
            {
                int p1 = Ind[elem][i];
                int p2 = Ind[elem][j];
                int lg = p2 - p1;

                if (  p1 + lg - 1 <= N && p2 + lg - 1 <= N && getHash( p1, p1 + lg - 1 ) == getHash( p2, p2 + lg - 1 ) )
                {
                    VP.push_back( make_pair( p1, p2 + lg - 1 ) );
                }
            }
    }

    sort( VP.begin(), VP.end(), cmp );

    int start = 0;

    for ( int i = 0; i < VP.size(); ++i )
    {
        int x = VP[i].first;
        int y = VP[i].second;
        int lg = y - x + 1;

        int m = x + lg / 2 - 1;

        if ( x >= start + 1 )
        {
            start = m;
        }
    }

    cout << N - start << "\n";

    for ( int i = start + 1; i <= N; ++i )
        cout << A[i] << " ";

    cout << "\n";

    return 0;
}
