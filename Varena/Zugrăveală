#include <bits/stdc++.h>

using namespace std;

FILE *in, *out;

///-----------------------------------------------------------------
const int BS = (1 << 16);
char buffer[BS];
int position = BS;

inline char StopMafiaTemelor()
{
    if ( position == BS )
    {
        position = 0;
        fread(buffer, BS, 1, in);
    }

    return buffer[position++];
}

inline char getChar()
{
    char ch;

    do
    {
        ch = StopMafiaTemelor();

    } while ( !isdigit(ch) && !isalpha(ch) );

    return ch;
}
///-----------------------------------------------------------------

const int Nmax = 100000 + 1;
const int SIGMA = 128;

struct Query
{
    char tip;
    char X, Y;
};

Query Q[Nmax];

char str[Nmax];
int N;

char mapped[SIGMA];

/**
char bruteString[Nmax];
void brute()
{
    int p = 0;

    for ( int i = 0; i < N; ++i )
    {
        if ( Q[i].tip == '1' )
            bruteString[ p++ ] = Q[i].X;
        else
        {
            for ( int j = 0; j < p; ++j )
                if ( bruteString[j] == Q[i].X )
                    bruteString[j] = Q[i].Y;
        }
    }

    bruteString[p] = '\0';
}

void genTest()
{
    srand(time(0));
    const int L = 20001;

    ofstream out("zugraveala.in");

    out << L << "\n";

    for ( int i = 1; i <= L; ++i )
    {
        int tip = 1 + rand() % 2;

        out << tip << " ";

        if ( tip == 1 )
            out << char('a' + rand() % 26) << "\n";
        else
            out << char('a' + rand() % 26) << " " << char('a' + rand() % 26) << "\n";
    }

    out.close();
}
**/

int main()
{
///    genTest();

     in = fopen("zugraveala.in", "r");
    out = fopen("zugraveala.out", "w");

    fscanf(in, "%d", &N);
    ///assert( 1 <= N && N <= 100000 );

    for ( int i = 0; i < N; ++i )
    {
        Q[i].tip = getChar();
        Q[i].X = getChar();

        if ( Q[i].tip == '2' )
            Q[i].Y = getChar();

        /**assert( '1' <= Q[i].tip && Q[i].tip <= '2' );
        assert( 'a' <= Q[i].X && Q[i].tip <= 'z' );

        if ( Q[i].tip == '2' )
            assert( 'a' <= Q[i].Y && Q[i].Y <= 'z' );
        **/
    }

    for ( int i = 0; i < SIGMA; ++i )
        mapped[i] = i;

    ///brute();

    int pointer = 0;

    for ( int i = 0; i < N; ++i )
        if ( Q[i].tip == '1' )
            str[ pointer++ ] = Q[i].X;

    str[ pointer ] = '\0';

    for ( int i = N - 1, p = pointer - 1; i >= 0; i-- )
    {
        if ( Q[i].tip == '2' )
        {
            mapped[ Q[i].X - 'a' ] = mapped[ Q[i].Y - 'a' ];
        }
        else
        {
            str[p--] = mapped[ Q[i].X - 'a' ] + 'a';
        }
    }

    ///for ( int i = 0; i < pointer; ++i )
        ///assert( bruteString[i] == str[i] );

    ///fprintf(stderr, "%s\n", bruteString);

    fprintf(out, "%s\n", str);

    return 0;
}
