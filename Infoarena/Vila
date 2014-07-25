#include <bits/stdc++.h>

using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int Nmax = 129;

int A[Nmax][Nmax];
int C[Nmax][Nmax];

int NRC, sum;
int area[Nmax * Nmax];
int N, M;

void rec( int i, int j )
{
    C[i][j] = NRC;
    sum++;

    for ( int k = 0; k < 4; ++k )
    {
        int x = i + dx[k];
        int y = j + dy[k];

        if ( A[x][y] == 1 && C[x][y] == 0 )
            rec( x, y );
    }
}

int main()
{
    ifstream in("vila.in");
    ofstream out("vila.out");

    in >> N >> M;

    for ( int i = 1; i <= N; ++i )
    {
        string str;
        in >> str;

        for ( int j = 0; j < M; ++j )
        {
            if ( str[j] == '-' )
                A[i][j + 1] = 1;
        }
    }

    int maxim = 0;

    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            if ( A[i][j] == 1 && C[i][j] == 0 )
            {
                sum = 0;
                NRC++;
                rec( i, j );
                area[NRC] = sum;
                maxim = max( maxim, sum );
            }



    int x = 1e9, y = 1e9;
    int best = 0;

    for ( int i = 1; i <= N; i++ )
        for ( int j = 1; j <= M; ++j )
        {
            if ( A[i][j] == 0 )
            {
                set <int> S;

                for ( int k = 0; k < 4; ++k )
                {
                    int xx = i + dx[k];
                    int yy = j + dy[k];

                    if ( A[xx][yy] == 1 )
                        S.insert( C[xx][yy] );
                }

                int newArea = 1;

                for ( auto x: S )
                    newArea += area[x];

                if ( newArea > best )
                {
                    best = newArea;
                    x = i;
                    y = j;
                }
                else
                {
                    if ( best == newArea )
                    {
                        if ( x > i )
                        {
                            x = i;
                            y = j;
                        }
                        else
                        {
                            if ( x == i )
                            {
                                if ( y > j )
                                    y = j;
                            }
                        }
                    }
                }
            }
        }

    out << NRC << "\n";
    out << maxim << "\n";
    out << x << " " << y << " " << best << "\n";

    return 0;
}
