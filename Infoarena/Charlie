#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

char str[Nmax];
char stiva[Nmax];
int top = 0;

int main()
{
    ifstream in("charlie.in");
    ofstream out("charlie.out");

    int p;

    in >> p;
    in >> str;

    if (p == 1)
    {
        int lgmax = 0;
        int n = strlen(str);

        for (int i = 0; i < n; ++i)
        {
            int j = i;
            int lg = 0;

            while (j + 2 < n && str[j] > str[j + 1] && str[j + 1] < str[j + 2])
            {
                j += 2;
                lg += 2;
            }

            if (lg)
            {
                lg++;
                i = j - 1;
            }

            lgmax = max(lgmax, lg);
        }

        out << lgmax << "\n";
    }
    else
    {
        int suma = 0;
        int n = strlen(str);

        for (int i = 0; i < n; ++i)
        {
            while (top >= 2 && stiva[top - 2] > stiva[top - 1] && stiva[top - 1] < str[i])
            {
                suma += (max(stiva[top - 2], str[i]) - 'a' + 1);
                top--;
            }

            stiva[top++] = str[i];
        }

        for (int i = 0; i < top; ++i)
            out << stiva[i];

        out << "\n" << suma << "\n";
    }

    return 0;
}
