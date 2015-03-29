#include <bits/stdc++.h>

using namespace std;

const int Nmax = 10000 + 1;
const long long LIMIT = numeric_limits<long long>::max() / 4LL;

typedef unsigned long long ull;

int X[Nmax];
int posTribe[Nmax];
ull Y[Nmax];
ull Q[Nmax];
ull R[Nmax];

int T, N, nrTribes;
int distMax;

ull sumaY;

bool valid(ull nrOameni)
{
    int indiceTribe = 1;
    int indiceDish = 1;

    ull sumaRamasa = sumaY;

    while (true)
    {
        if (nrOameni == 0)
            return false;

        if (nrOameni > sumaRamasa)
            return true;

        if (indiceDish <= N && indiceTribe <= nrTribes)
        {
            if (posTribe[indiceTribe] <= X[indiceDish])
            {
                if (nrOameni >= Q[indiceTribe])
                {
                    nrOameni += R[indiceTribe];
                }

                indiceTribe++;
            }
            else
            {
                if (Y[indiceDish] < nrOameni)
                {
                    nrOameni -= Y[indiceDish];
                    sumaRamasa -= Y[indiceDish];
                    indiceDish++;
                }
                else
                    return false;
            }
        }
        else if (indiceDish <= N) /// nu mai am triburi
        {
            if (Y[indiceDish] <= nrOameni)
            {
                nrOameni -= Y[indiceDish];
                indiceDish++;
            }
            else
                return false;
        }
        else
        {
            return (nrOameni >= 1);
        }
    }

    assert(true == false);
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> T;

    while (T--)
    {
        cin >> distMax;
        cin >> N;
        sumaY = 0;

        for (int i = 1; i <= N; ++i)
        {
            cin >> X[i] >> Y[i];
            sumaY += Y[i];
        }

        cin >> nrTribes;

        for (int i = 1; i <= nrTribes; ++i)
            cin >> posTribe[i] >> Q[i] >> R[i];

        ull st = 1, dr = LIMIT, sol = 0;

        while (st <= dr)
        {
            ull m = (st + dr) / 2;

            if (valid(m))
            {
                sol = m;
                dr = m - 1;
            }
            else
                st = m + 1;
        }

        cout << sol << "\n";
    }

    return 0;
}
