#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int Nmax = 5001;

int N, S;

double YES[3][Nmax];
double NO[3][Nmax];

int main()
{
    ///ifstream cin("date.in");

    cin >> N >> S;

    int Yes = S - 2 * N;
    int No = N - Yes;

    for ( int i = 0; i <= Yes; ++i )
    {
        for ( int j = 0; j <= No; ++j )
        {
            if ( i >= 1 )
            {
                YES[i % 2][j] = YES[(i - 1) % 2][j] * i / ( i + j ) * 1.0;
                NO[i % 2][j] = ( 1 + YES[(i - 1) % 2][j] ) * i / ( i + j ) * 1.0;
            }

            if ( j >= 1 )
            {
                NO[i % 2][j] += NO[i % 2][j - 1] * j / ( i + j ) * 1.0;
                YES[i % 2][j] += ( 1 + NO[i % 2][j - 1] ) * j / ( i + j ) * 1.0;
            }
        }
    }

    cout << fixed << setprecision( 10 );
    cout << YES[Yes % 2][No]<<endl;
}
