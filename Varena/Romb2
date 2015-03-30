#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

///-------------------------------------
const int BS = (1 << 16);
char buffer[BS];
int position = BS;

char getChar()
{
    if (position == BS)
    {
        position = 0;
        fread(buffer, BS, 1, stdin);
    }

    return buffer[position++];
}

int getNr()
{
    int a = 0;
    int sgn = 1;
    char ch;

    do
    {
        ch = getChar();

    } while (!isdigit(ch) && ch != '-');

    if (ch == '-')
    {
        sgn = -1;
        ch = getChar();
    }

    do
    {
        a = (a << 3) + (a << 1) + (ch - '0');
        ch = getChar();

    } while (isdigit(ch));

    return a * sgn;
}
///-------------------------------------

const int Vmax = 20000;
const int Tmax = 400000;

void genTests()
{
    srand(time(NULL));
    ofstream out("romb2.in");

    int T = Tmax;

    out << T << "\n";

    for (int i = 0; i < T; ++i)
    {
        int a = rand() % Vmax;
        int b = rand() % Vmax;
        int c = rand() % Vmax;
        int d = rand() % Vmax;

        out << -a << " " << b << " " << "30 " << -c << " " << d << "\n";
    }

    out.close();
}

#define Type double

Type dx, dy, Cx, Cy;
Type dir1, dir2;
Type slope;
int T, k;
long long sol;

inline int semn()
{
    slope = dy / dx;

    if (-slope * Cx < Cy)
    {
        if (+slope * Cx < Cy)
            return 1;
        else
            return 4;
    }
    else
    {
        if (+slope * Cx < Cy)
            return 2;
        else
            return 3;
    }
}

void divide()
{
    sol = 1;

    while (k--)
    {
        dx /= 2;
        dy /= 2;

        int op = semn();

        if (op == 1)
        {
            sol = (sol << 2) - 3;
            Cy -= dy;

            continue;
        }

        if (op == 2)
        {
            sol = (sol << 2) - 2;
            Cx += dx;

            continue;
        }

        if (op == 3)
        {
            sol = (sol << 2) - 1;
            Cy += dy;

            continue;
        }

        sol = (sol << 2);
        Cx -= dx;
    }
}

int main()
{
    ///genTests();

    freopen("romb2.in", "r", stdin);
    freopen("romb2.out", "w", stdout);

    T = getNr();

    while (T--)
    {
        dx = getNr(); dy = getNr();
        k = getNr();
        Cx = getNr(); Cy = getNr();

        divide();

        printf("%lld\n", sol);
    }

    return 0;
}
