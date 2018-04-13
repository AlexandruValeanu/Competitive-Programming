#include <bits/stdc++.h>

using namespace std;

///-------------------------------------
const int BS = (1 << 20);
char buffer[BS];
int position = BS;

inline char getChar()
{
    if ( position == BS )
    {
        position = 0;
        fread(buffer, BS, 1, stdin);
    }

    return buffer[position++];
}

inline int getNr()
{
    int a = 0;
    char ch;

    do
    {
        ch = getChar();

    } while ( !isdigit(ch) );

    do
    {
        a = (a << 3) + (a << 1) + ch - '0';
        ch = getChar();

    } while ( isdigit(ch) );

    return a;
}
///-------------------------------------

const int Nmax = 250000 + 1;

long long sum[Nmax];
long long sum2[Nmax];
int v[Nmax];
int N, M;

inline long long calc(int x, int y, int m)
{
    return (sum2[y] + sum2[x - 1] - 2LL * sum2[m]) + 1LL * m * (2LL * sum[m] - sum[y] - sum[x - 1]);
}

int main()
{
    freopen("cuburi2.in", "r", stdin);
    freopen("cuburi2.out", "w", stdout);

    N = getNr(); M = getNr();

    for ( int i = 1; i <= N; ++i )
    {
        v[i] = getNr();
        sum[i] = sum[i - 1] + v[i];
        sum2[i] = sum2[i - 1] + 1LL * i * v[i];
    }

    while ( M-- )
    {
        int st, dr, gasit, x, y;
        x = getNr(); y = getNr();
        st = x; dr = y;
        gasit = N;

        while ( st <= dr )
        {
            int m = (st + dr) / 2;

            if ( calc(x, y, m) <= calc(x, y, m + 1) )
            {
                gasit = m;
                dr = m - 1;
            }
            else
                st = m + 1;
        }

        printf("%d %lld\n", gasit, calc(x, y, gasit));
    }

    return 0;
}
