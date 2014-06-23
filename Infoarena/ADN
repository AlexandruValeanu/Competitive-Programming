#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Nmax = 18;
const int Lmax = 3e4 + 2;
const int inf = 0x3f3f3f3f;

/// Cost[i][j] = cel mai lung sufix al lui sir[i] care este prefix al lui sir[i]
/// C[i][j] = cate caractere adaug de la j daca sunt in i
/// C[i][j] = strlen( sir[j] ) - Cost[i][j]
/// D[i][j] = lungimea unei secvente ce se termina in sir[j] si contine toate sirurile ce au bitul 1 in reprezentare binara a lui i ca subsecvente

char S[Nmax][Lmax];
int C[Nmax][Nmax];
int Cost[Nmax][Nmax];
int D[1 << Nmax][Nmax];
int tata[1 << Nmax][Nmax];
int pi[Lmax];
int sol[Lmax];
int N, NP;

void build_prefix( char s[] )
{
    int lgprefix = 0;
    int n = strlen( s + 1 );

    pi[1] = 0;

    for ( int i = 2; i <= n; ++i )
    {
        while ( lgprefix && s[i] != s[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( s[i] == s[lgprefix + 1] )
                lgprefix++;

        pi[i] = lgprefix;
    }
}

int KMP_cost( char patt[], char text[] )
{
    int n = strlen( patt + 1 );
    int m = strlen( text + 1 );

    int lgprefix = 0;

    for ( int i = 1; i <= m; ++i )
    {
        while ( lgprefix && text[i] != patt[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( text[i] == patt[lgprefix + 1] )
                lgprefix++;

        if ( lgprefix == n )
                return n;
    }

    return lgprefix;
}

void hamintonian_path()
{
    for ( int i = 0; i < ( 1 << N ); ++i )
            for ( int j = 0; j < N; ++j )
                D[i][j] = inf,
                tata[i][j] = -1;

    for ( int i = 0; i < N; ++i )
            D[1 << i][i] = strlen( S[i] + 1 );

    for ( int i = 1; i < ( 1 << N ); ++i )
        for ( int j = 0; j < N; ++j )
        {
            if ( D[i][j] != inf )
                    continue;

            if ( i & ( 1 << j ) )
            {
                for ( int k = 0; k < N; ++k )
                    if ( j != k && ( i & ( 1 << k ) ) )
                    {
                        if ( D[i][j] > D[i ^ ( 1 << j )][k] + C[k][j] )
                        {
                            D[i][j] = D[i ^ ( 1 << j )][k] + C[k][j];
                            tata[i][j] = k;
                        }
                    }
            }
        }
}

void gen_path( int stare, int current )
{
    if ( stare == 0 )
            return;

    gen_path( stare ^ ( 1 << current ), tata[stare][current] );

    sol[NP++] = current;
}

int main()
{
    ifstream in("adn.in");
    ofstream out("adn.out");

    in >> N;

    for ( int i = 0; i < N; ++i )
    {
        in >> ( S[i] + 1 );
    }

    for ( int i = 0; i < N; ++i )
    {
        build_prefix( S[i] );

        for ( int j = 0; j < N; ++j )
        {
            if ( i != j )
            {
                int kmp = KMP_cost( S[i], S[j] );

                if ( kmp == strlen( S[i] + 1 ) )
                {
                    memcpy( S[i], S[N - 1], sizeof( S[N - 1] ) );
                    memset( S[N - 1], 0, sizeof( S[N - 1] ) );

                    N--;
                    i--;
                    break;
                }
            }
        }
    }

    for ( int i = 0; i < N; ++i )
    {
        build_prefix( S[i] );

        for ( int j = 0; j < N; ++j )
                if ( i != j )
                    Cost[j][i] = KMP_cost( S[i], S[j] );
    }

    for ( int i = 0; i < N; ++i )
            for ( int j = 0; j < N; ++j )
                if ( i != j )
                    C[i][j] = strlen( S[j] + 1 ) - Cost[i][j];

    hamintonian_path();

    int best = 0;

    for ( int i = 0; i < N; ++i )
    {
        if ( D[( 1 << N ) - 1][best] > D[( 1 << N ) - 1][i] )
                best = i;
    }

    gen_path( ( 1 << N ) - 1, best );

    for ( int i = 0; i < N - 1; ++i )
    {
        int cat = strlen( S[ sol[i] ] + 1 ) - Cost[ sol[i] ][ sol[i + 1] ];

        for ( int j = 1; j <= cat; ++j )
                out << S[ sol[i] ][j];
    }

    for ( int i = 1; i <= strlen( S[ sol[N - 1] ] + 1 ); ++i )
            out << S[ sol[N - 1] ][i];

    out << "\n";

    in.close();
    out.close();

    return 0;
}
