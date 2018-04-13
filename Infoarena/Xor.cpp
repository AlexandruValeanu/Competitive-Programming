#include <bits/stdc++.h>

using namespace std;

///---------------------------------------------------
const int BUFFER_SIZE = (1 << 16);
char buffer[BUFFER_SIZE];
int position = BUFFER_SIZE;

inline char getChar()
{
    if ( position == BUFFER_SIZE )
    {
        position = 0;
        fread(buffer, BUFFER_SIZE, 1, stdin);
    }

    return buffer[position++];
}

inline int getNr()
{
    register int a = 0;
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
///---------------------------------------------------

int T, P;

inline int oneK(int i, int k)
{
    i++;

    int sol = ((i >> (k + 1))) << k;

    if ( (i >> k) & 1 )
        sol += (i & ((1 << k) - 1));

    return sol;
}

inline int zeroK(int i, int k)
{
    return i - oneK(i, k);
}

inline long long arieK(int i, int j, int k)
{
    int a = oneK(i, k);
    int b = oneK(j, k);

    long long sol1 = (1LL * (i - a) * b);
    long long sol2 = (1LL * (j - b) * a);

    return (sol1 + sol2) % P;
}

inline int arie(int i, int j)
{
    long long s = 0;

    for (int k = 0; k <= 30; ++k)
    {
        long long x = (1LL * (1 << k) * arieK(i, j, k));
        s = (s + x);
    }

    return s % P;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    T = getNr(); P = getNr();

    while (T--)
    {
        int x1, x2, y1, y2;
        x1 = getNr(); y1 = getNr();
        x2 = getNr(); y2 = getNr();

        int sol = arie(x2, y2);
        sol = (sol - arie(x1 - 1, y2) + P) % P;
        sol = (sol - arie(x2, y1 - 1) + P) % P;
        sol = (sol + arie(x1 - 1, y1 - 1)) % P;

        printf("%d\n", sol);
    }

    return 0;
}
