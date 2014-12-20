#include <bits/stdc++.h>

using namespace std;

const int Lmax = 100000 + 1;

#define ParOpen  -100
#define ParClose -200

char expression[Lmax];
int stiva[Lmax];
int v[Lmax];

int N;
int top;

void inverseaza( int i, int j )
{
    while ( i < j )
    {
        swap( v[i], v[j] );
        i++;
        j--;
    }
}

int main()
{
    ifstream in("bizar.in");
    ofstream out("bizar.out");

    in.getline( expression, Lmax );
    N = strlen( expression );
    top = 0;

    int nr = 0;
    int exista = 0;

    for ( int i = 0; i < N; ++i )
    {
        if ( expression[i] != ' ' )
        {
            if ( isdigit( expression[i] ) )
            {
                exista = 1;
                nr = nr * 10 + expression[i] - '0';
            }
            else
            {
                if ( expression[i] == '(' )
                {
                    if ( exista )
                    {
                        stiva[ ++top ] = nr;
                        exista = 0;
                        nr = 0;
                    }

                    stiva[ ++top ] = ParOpen;
                }
                else if ( expression[i] == ',' )
                {
                    if ( exista )
                    {
                        stiva[ ++top ] = nr;
                        exista = 0;
                        nr = 0;
                    }
                }
                else if ( expression[i] == ')')
                {
                    if ( exista )
                    {
                        stiva[ ++top ] = nr;
                        exista = 0;
                        nr = 0;
                    }

                    int n = 0;

                    while ( stiva[top] != ParOpen )
                    {
                        v[ ++n ] = stiva[top];
                        top--;
                    }

                    inverseaza( 1, n );

                    top--;

                    int X = stiva[ top-- ] % n;

                    if ( !X ) X = n;

                    stiva[ ++top ] = v[X];
                }
            }
        }
    }

    out << stiva[top] << "\n";

    return 0;
}
