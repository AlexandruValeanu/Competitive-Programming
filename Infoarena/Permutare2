#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

int P;
int L[Nmax];
int N, M;

int main()
{
    ifstream in("permutare2.in");
    ofstream out("permutare2.out");

    ios_base::sync_with_stdio( false );

    in >> N >> M;

    for ( int i = 1; i <= N; ++i )
        in >> P;

    L[1]++;

    for ( int i = 1; i < M; ++i )
    {
        in >> P;

        if ( ++P > N ) P -= N;

        L[P]++;
    }

    long long best = ( 1LL << 60 );
    long long sumSt = 0, sumDr = 0;

    int sum_L_st = 0, sum_L_dr = 0;
    int nrSt = N / 2;
    int nrDr = N / 2 - ( N % 2 == 0 );
    int p = nrSt + 1;

    for ( int i = 1; i <= p; ++i )
    {
        sumSt += 1LL * L[i] * ( i - 1 );
        sum_L_st += L[i];
    }

    sum_L_st -= L[1];

    for ( int i = p + 1; i <= N; ++i )
    {
        sumDr += 1LL * L[i] * ( N - i + 1 );
        sum_L_dr += L[i];
    }

    best = min(best, sumSt + sumDr);

    for ( int i = 2; i <= N; ++i )
    {
        if ( ++p > N ) p -= N;

        sumSt -= sum_L_st;

        sum_L_st += L[p];
        sum_L_st -= L[i];

        sumSt += L[p] * nrSt;

        sum_L_dr -= L[p];
        sum_L_dr += L[i - 1];

        sumDr += sum_L_dr;
        sumDr -= L[p] * nrDr;

        best = min(best, sumSt + sumDr);
    }

    out << best << "\n";

    return 0;
}
