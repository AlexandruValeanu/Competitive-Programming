#include <bits/stdc++.h>

using namespace std;

const int Lmax = 55;
const int BASE = 10;

struct Huge
{
    int digits[Lmax];

    Huge()
    {
        for ( int i = 0; i < Lmax; ++i )
            digits[i] = 0;
    }
};

void sterge(Huge& A)
{
    memset(A.digits, 0, sizeof(A.digits));
}

void initWithNumber(Huge& A, int x)
{
    sterge(A);

    while (x)
    {
        A.digits[ ++A.digits[0] ] = x % BASE;
        x /= BASE;
    }
}

void copiere(Huge& A, const Huge& B)
{
    for ( int i = 0; i <= B.digits[0]; ++i )
        A.digits[i] = B.digits[i];
}

void multiply(Huge& A, const int x)
{
    int carry = 0;

    for ( int i = 1; i <= A.digits[0]; ++i )
    {
        long long nr = (1LL * A.digits[i] * x) + carry;
        carry = nr / BASE;
        A.digits[i] = nr % BASE;
    }

    while (carry)
    {
        A.digits[ ++A.digits[0] ] = carry % BASE;
        carry /= BASE;
    }
}

int compare(const Huge& A, const Huge& B)
{
    if ( A.digits[0] < B.digits[0] )
        return -1;

    if ( A.digits[0] > B.digits[0] )
        return 1;

    for ( int i = A.digits[0]; i >= 1; i-- )
    {
        if ( A.digits[i] < B.digits[i] )
            return -1;

        if ( A.digits[i] > B.digits[i] )
            return 1;
    }

    return 0;
}

void printHuge(const Huge& A)
{
    freopen("2i3j5k.out", "w", stdout);

    printf("%d", A.digits[ A.digits[0] ]);

    for (int i = A.digits[0] - 1; i >= 1; i--)
        printf("%d", A.digits[i]);

    printf("\n");
}


///----------------------------------------------------------------------------------------
/**
const int Nmax = 8500;

struct Queue
{
    Huge v[Nmax];
    int st, dr;

    explicit Queue()
    {
        st = 1;
        dr = 0;
    }

    void push(Huge& key)
    {
        if ( ++dr >= Nmax ) dr = 0;

        copiere(v[dr], key);
    }

    const Huge& front() const
    {
        return v[st];
    }

    void pop()
    {
        if ( ++st >= Nmax ) st = 0;
    }
};

void solveSmart(int N)
{
    Queue Q2, Q3, Q5;

    Huge nr, aux;
    initWithNumber(nr, 1);

    for ( int i = 1; i < N; ++i )
    {
        copiere(aux, nr);
        multiply(aux, 2);
        Q2.push(aux);

        copiere(aux, nr);
        multiply(aux, 3);
        Q3.push(aux);

        copiere(aux, nr);
        multiply(aux, 5);
        Q5.push(aux);

        copiere(nr, Q2.front());

        if ( compare(nr, Q3.front()) == 1 )
            copiere(nr, Q3.front());

        if ( compare(nr, Q5.front()) == 1 )
            copiere(nr, Q5.front());

        if ( compare(nr, Q2.front()) == 0 ) Q2.pop();
        if ( compare(nr, Q3.front()) == 0 ) Q3.pop();
        if ( compare(nr, Q5.front()) == 0 ) Q5.pop();
    }

    printHuge(nr);
}
**/
///----------------------------------------------------------------------------------------

const double EPS = 1e-10;
const double LOG2 = 1;
const double LOG3 = 1.58496250072;
const double LOG5 = 2.32192809489;

struct Triple
{
    short i, j, k;

    Triple() : i(0), j(0), k(0) {
    }

    Triple(const short a, const short b, const short c) : i(a), j(b), k(c) {
    }
};

double modul(double a)
{
    if (a > EPS)
        return a;
    else
        return -a;
}

bool equals(const Triple& A, const Triple& B)
{
    if ( A.i != B.i || A.j != B.j || A.k != B.k )
        return false;

    return true;
}

double getValue(const Triple& A)
{
    return 1.0 * A.i * LOG2 + 1.0 * A.j * LOG3 + 1.0 * A.k * LOG5;
}

int compare(const Triple& A, const Triple& B)
{
    if ( equals(A, B) )
        return 0;

    double a = getValue(A);
    double b = getValue(B);

    if ( a < b )
        return -1;
    else
        return 1;
}

queue<Triple> Q2, Q3, Q5;

void solveEfficient(int N)
{
    Triple nr(0, 0, 0);

    int m = 0;

    for ( int p = 1; p < N; ++p )
    {
        short i = nr.i;
        short j = nr.j;
        short k = nr.k;

        Q2.push( Triple(i + 1, j, k) );
        Q3.push( Triple(i, j + 1, k) );
        Q5.push( Triple(i, j, k + 1) );

        nr = Q2.front();

        if ( compare(nr, Q3.front()) == 1 )
            nr = Q3.front();

        if ( compare(nr, Q5.front()) == 1 )
            nr = Q5.front();

        if ( compare(nr, Q2.front()) == 0 ) Q2.pop();
        if ( compare(nr, Q3.front()) == 0 ) Q3.pop();
        if ( compare(nr, Q5.front()) == 0 ) Q5.pop();
    }

    Huge sol;
    initWithNumber(sol, 1);

    while ( nr.i-- )
        multiply(sol, 2);

    while ( nr.j-- )
        multiply(sol, 3);

    while ( nr.k-- )
        multiply(sol, 5);

    printHuge(sol);
}

int main()
{
    FILE *in = fopen("2i3j5k.in", "r");

    int N;

    fscanf(in, "%d", &N);
    solveEfficient(N);

    return 0;
}
