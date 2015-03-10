#include <bits/stdc++.h>

using namespace std;

FILE *in, *out;

///----------------------------------------------------
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

    return buffer[position++];
}

inline int getNr()
{
    int a = 0;
    char ch;
    int sgn = 1;

    do
    {
        ch = getChar();

    } while ( !isdigit(ch) && ch != '-' );

    if ( ch == '-' )
    {
        sgn = -1;
        ch = getChar();
    }

    do
    {
        a = (a << 3) + (a << 1) + ch - '0';
        ch = getChar();

    } while ( isdigit(ch) );

    return a * sgn;
}
///----------------------------------------------------

const int Nmax = 1e6 + 1;

unsigned aib[Nmax];
unsigned totalSum;
int N, Q;

inline int lsb(int x)
{
    return x & (-x);
}

void update(int pos, int value)
{
    for ( int i = pos; i <= N; i += lsb(i) )
        aib[i] += value;
}

unsigned query(int pos)
{
    unsigned sum = 0;

    for ( int i = pos; i >= 1; i -= lsb(i) )
        sum += aib[i];

    return sum;
}

/// log^2(N)
int queryBrute()
{
    int st = 1, dr = N, k = 0;

    while ( st <= dr )
    {
        int m = (st + dr) / 2;

        unsigned valQuery = query(m);

        if ( 2U * valQuery >= totalSum )
        {
            k = m;
            dr = m - 1;
        }
        else
            st = m + 1;
    }

    return k;
}

/// log(N)
int querySmart()
{
    int k = 0;
    unsigned sumCurrent = 0;

    for ( int pw = (1 << 19); pw; pw >>= 1 )
    {
        if ( k + pw <= N )
        {
            if ( 2U * ( sumCurrent + aib[k + pw] ) < totalSum )
            {
                sumCurrent += aib[k + pw];
                k += pw;
            }
        }
    }

    return k + 1;
}

void gen_operatii()
{
    ofstream out("hotdogs.in");

    srand(time(NULL));
    const int L = 1000000;
    const int Q_L = 100000;

    out << L << " " << Q_L << "\n";

    for ( int k = 1; k <= Q_L; ++k )
    {
        int a = 1 + rand() % L;
        int b = 1 + rand() % 50000;

        out << a << " " << b << "\n";
    }

    out.close();
}

int main()
{
     in = fopen("hotdogs.in", "r");
    out = fopen("hotdogs.out", "w");

    N = getNr(); Q = getNr();

    for ( int k = 1; k <= Q; ++k )
    {
        int a = getNr();
        int b = getNr();

        totalSum += b;

        update(a, b);
        fprintf(out, "%d\n", querySmart());
        ///assert(queryBrute() == querySmart());
    }

    return 0;
}
