#include <bits/stdc++.h>

using namespace std;

FILE *in, *out;

const int BS = (1 << 16);
char buffer[BS];
int position = BS;

inline char getChar()
{
    if ( position == BS )
    {
        position = 0;
        fread(buffer, BS, 1, in);
    }

    return buffer[ position++ ];
}

inline void citeste(int& nr)
{
    nr = 0;
    char ch;

    do
    {
        ch = getChar();

    } while ( !isdigit(ch) );

    do
    {
        nr = (nr << 3) + (nr << 1) + ch - '0';
        ch = getChar();

    } while ( isdigit(ch) );
}

typedef unsigned long long ull;

const int Nmax = 50000 + 1;
const int Dmax = 10000 + 1;
const int MAX_BITS = 64;

const ull maskOfCarry = 0x8000000000000000L;

char SOL[2 * Nmax + 1];

ull v[2][Nmax / 64 + 1];
int L[Dmax], C[Dmax], V[Dmax];

int N, D;

inline bool test(ull bit[], const size_t position)
{
    return (bit[position >> 6] >> (position & 63)) & 1;
}

inline void flip(ull bit[], const size_t position)
{
    bit[position >> 6] ^= (1ull << (position & 63));
}

inline void setBit(ull bit[], const size_t position, const int value)
{
    bit[position >> 6] &= ~(1ull << (position & 63));
    bit[position >> 6] ^= ((ull)value << (position & 63));
}

int currentBitset[Nmax];
int prevBitset[Nmax];

void bruteSolve();
void generateTests();

void Validare()
{
    ifstream in("beculete.out");

    for ( int k = 0; k < N; ++k )
    {
        int a;
        in >> a;

        assert( a == currentBitset[k] );
    }

    in.close();
}

int main()
{
    ///generateTests();

    in  = fopen("beculete.in", "r");
    out = fopen("beculete.out", "w");

    citeste(N); citeste(D);

    ///assert( 1 <= N && N <= 50000 );
    ///assert( 1 <= D && D <= 10000 );

    for ( int i = 1; i <= D; ++i )
    {
        citeste(L[i]);
        citeste(C[i]);
        citeste(V[i]);

        ///assert( 2 <= L[i] && L[i] <= N );
        ///assert( 1 <= C[i] && C[i] <= L[i] );
        ///assert( 0 <= V[i] && V[i] <= 1 );

        ///if ( L[i] == L[i - 1] )
            ///assert( C[i - 1] <= C[i] );
        ///else
            ///assert( L[i - 1] < L[i] );
    }

    ///bruteSolve();

    v[1][0] = 1;

    int pointer = 1;

    for ( int i = 2; i <= N; ++i )
    {
        int cr = i & 1;
        int pr = cr ^ 1;

        bool carry = false;
        const int Limit = 1 + ((i - 1) >> 6);

        for ( int j = 0; j < Limit; ++j )
        {
            if (carry)
            {
                carry = ((v[pr][j] & maskOfCarry) != 0);
                v[cr][j] = ((v[pr][j] << 1) | 1) ^ v[pr][j];
            }
            else
            {
                carry = ((v[pr][j] & maskOfCarry) != 0);
                v[cr][j] = (v[pr][j] << 1) ^ v[pr][j];
            }
        }

        while ( pointer <= D && L[pointer] == i )
        {
            setBit(v[cr], C[pointer] - 1, V[pointer]);
            pointer++;
        }

        if ( i == N )
        {
            int group = 0;
            int ind = 0;
            int p = 0;

            int P = 0;

            while ( ind < N )
            {
                bool a = (v[cr][group] & (1ull << p));

                SOL[ P++ ] = '0' + a;
                SOL[ P++ ] = ' ';

                p++;
                ind++;

                if ( p == MAX_BITS )
                {
                    p = 0;
                    group++;
                }
            }

            SOL[ P ] = '\0';

            fprintf(out, "%s\n", SOL);
            fclose(out);
        }
    }

    ///Validare();

    return 0;
}

void bruteSolve()
{
    int pointer = 1;

    prevBitset[0] = 1;

    for ( int i = 2; i <= N; ++i )
    {
        currentBitset[0] = prevBitset[0];
        currentBitset[i - 1] = prevBitset[i - 2];

        for ( int j = 1; j < i - 1; ++j )
            currentBitset[j] = prevBitset[j - 1] ^ prevBitset[j];

        while ( pointer <= D && L[pointer] == i )
        {
            currentBitset[ C[pointer] - 1 ] = V[pointer];
            pointer++;
        }

        for ( int j = 0; j < i; ++j )
            prevBitset[j] = currentBitset[j];
    }
}

void generateTests()
{
    srand((time(0)));

    N = 49999; D = 1 + rand() % 10000;

    vector< pair< pair<int, int>, int > > V;

    for ( int i = 1; i <= D; ++i )
    {
        int l, c, v;
        l = min(2 + rand() % N, N);
        c = 1 + rand() % l;
        v = rand() % 2;

        pair< pair<int, int>, int > p;

        p.first.first = l;
        p.first.second = c;
        p.second = v;

        V.push_back( p );
    }

    sort(V.begin(), V.end());

    ofstream out("beculete.in");

    out << N << " " << D << "\n";

    for ( int i = 0; i < D; ++i )
    {
        out << V[i].first.first << " " << V[i].first.second << " " << V[i].second << "\n";
    }

    out.close();
}
