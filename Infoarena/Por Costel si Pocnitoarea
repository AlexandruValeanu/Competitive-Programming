#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 1000;
const int MOD = 1e7 + 3;

int X[MOD / LIMIT + 1];

int N, A, B;
int X1;
int Q, Q1;

void preprocess()
{
    X[0] = X1;
    int solution = X1;

    for ( int i = 1; i < MOD; ++i )
    {
        solution = (1LL * i * solution + A) % N;

        if ( i % LIMIT == 0 )
            X[i / LIMIT] = solution;
    }
}

int query(int timp)
{
    if( timp % LIMIT == 1 )
        return X[timp / LIMIT] ;

    int where = timp / LIMIT;

    if ( timp % LIMIT == 0 )
        where--;

    int solutie = X[where];

    for(int i = where * LIMIT + 1; i < timp; ++i)
        solutie = (1LL * i * solutie + A) % N ;

    return solutie ;
}

int main()
{
    ifstream in("pocnitoare.in");
    ofstream out("pocnitoare.out");

    in >> N >> A >> B >> X1 >> Q >> Q1;

    preprocess();

    for ( int i = 1; i <= Q; ++i )
    {
        int s = query(Q1);
        Q1 = (1LL * i * s + B) % MOD + 1;
        out << s << "\n";
    }

    return 0;
}
