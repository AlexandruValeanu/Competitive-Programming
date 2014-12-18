#include <bits/stdc++.h>
 
using namespace std;
 
const int Nmax = 100000 + 1;
const int Vmax = 1000000 + 1;
 
int A[Nmax];
int B[Nmax];
int P[Vmax];
pair<int,int> posDim[Nmax];
int N, M;
 
int main()
{
    ifstream in("secvmin.in");
    ofstream out("secvmin.out");
 
    in >> N >> M;
 
    for ( int i = 1; i <= N; ++i )
        in >> A[i];
 
    for ( int j = 1; j <= M; ++j )
    {
        in >> B[j];
        P[ B[j] ] = j;
    }
 
    int best = 1e9;
 
    for ( int i = 1; i <= N; ++i )
    {
        if ( P[ A[i] ] != 0 ) /// apare in B
        {
            int d = P[ A[i] ];
 
            if ( d == 1 )
                posDim[1] = pair<int,int>( i, i );
            else
            {
                if ( posDim[d - 1].first != 0 )
                {
                    posDim[d] = pair<int,int>( posDim[d - 1].first, i );
 
                    if ( d == M )
                        best = min( best, i - posDim[d].first + 1 );
                }
            }
        }
    }
 
    if ( best > N )
        out << "-1";
    else
        out << best;
 
    return 0;
}
