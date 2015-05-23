#include <bits/stdc++.h>

using namespace std;

#define Point pair<int,int>
#define x first
#define y second

const int Nmax = 5000 + 1;
const int MOD = 100003;

int X[Nmax], Y[Nmax];
Point P[Nmax];
int N;

int aib[Nmax];

int lsb(int x)
{
    return x & (-x);
}

void update(int aib[], int p, int v)
{
    while (p <= N)
    {
        aib[p] += v;
        p += lsb(p);
    }
}

int query(int aib[], int p)
{
    int sum = 0;

    while (p)
    {
        sum += aib[p];
        p -= lsb(p);
    }

    return sum;
}

void normalizare(int V[])
{
    static int aux[Nmax];

    for (int i = 1; i <= N; ++i)
        aux[i] = V[i];

    sort(aux + 1, aux + N + 1);

    for (int i = 1; i <= N; ++i)
        V[i] = lower_bound(aux + 1, aux + N + 1, V[i]) - aux;
}

int main()
{
    freopen("gps.in", "r", stdin);
    freopen("gps.out", "w", stdout);

    scanf("%d", &N);

    for ( int i = 1; i <= N; ++i )
    {
        scanf("%d %d", X + i, Y + i);
    }

    normalizare(X);
    normalizare(Y);

    for (int i = 1; i <= N; ++i)
        P[i] = {X[i], Y[i]};

    sort(P + 1, P + N + 1);

    int solution = 0;

    for (int i = 1; i <= N; ++i)
    {
        memset(aib, 0, sizeof(aib));
        update(aib, P[i].y, 1);

        int lessI = 0;
        int greaterI = 0;

        for (int j = i + 1; j <= N; ++j)
        {
            int total = (j - i + 1);
            int mic = 0;
            int mare = 0;

            update(aib, P[j].y, 1);

            if (P[i].y < P[j].y)
            {
                mic = lessI + 1;
                mare = total - query(aib, P[j].y - 1);

                greaterI++;
            }
            else
            {
                mic = query(aib, P[j].y);
                mare = greaterI + 1;

                lessI++;
            }

            solution += (1LL * mic * mare) % MOD;

            if (solution >= MOD)
                solution -= MOD;
        }
    }

    printf("%d\n", (solution + N + 1) % MOD);

    return 0;
}
