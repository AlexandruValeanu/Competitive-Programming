#include <bits/stdc++.h>

using namespace std;

typedef unsigned ull;

const int BASE1 = 137;
const int BASE2 = 29989;
const int MOD = 1e9 + 7;

const int Nmax = 1000;

ull base1[Nmax + 1], base2[Nmax + 1];
ull hashes[Nmax + 1];
char S[Nmax + 1][Nmax + 1], T[Nmax + 1][Nmax + 1];
int N, M;
int P, Q;

void init()
{
    base1[0] = base2[0] = 1;

    for ( int i = 1; i <= Nmax; ++i )
    {
        base1[i] = base1[i - 1] * BASE1;
        base2[i] = base2[i - 1] * BASE2;
    }
}

void Rabin_Karp()
{
    ull hashPattern, hashText;

    for ( int j = 1; j <= M; ++j )
        for ( int i = 1; i <= P; ++i )
            hashes[j] = hashes[j] * BASE1 + T[i][j];

    hashPattern = 0;

    for ( int j = 1; j <= Q; ++j )
    {
        ull code = 0;

        for ( int i = 1; i <= P; ++i )
            code = code * BASE1 + S[i][j];

        hashPattern = hashPattern * BASE2 + code;
    }

    ofstream out("fotografie.out");

    for ( int i = 1; i + P - 1 <= N; ++i )
    {
        hashText = 0;

        for ( int j = 1; j <= Q; ++j )
            hashText = hashText * BASE2 + hashes[j];

        if ( hashText == hashPattern )
            out << i - 1 << " " << 0 << "\n";

        for ( int j = Q + 1; j <= M; ++j )
        {
            hashText = ( hashText * BASE2 + hashes[j] - base2[Q] * hashes[j - Q] );

            if ( hashText == hashPattern )
                out << i - 1 << " " << j - Q << "\n";
        }

        for ( int j = 1; j <= M; ++j )
            hashes[j] = ( hashes[j] * BASE1 + T[i + P][j] - base1[P] * T[i][j] );
    }
}

int main()
{
    ifstream in("fotografie.in");

    ios_base::sync_with_stdio( false );

    in >> N >> M;

    for ( int i = 1; i <= N; ++i )
        in >> ( T[i] + 1 );

    in >> P >> Q;

    for ( int i = 1; i <= P; ++i )
        in >> ( S[i] + 1 );

    init();
    Rabin_Karp();

    return 0;
}
