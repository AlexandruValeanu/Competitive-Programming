#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 1;

char S[MAX_N];

int SA[MAX_N], auxSA[MAX_N];
int group[MAX_N], auxGroup[MAX_N];
int pos[MAX_N];

int lcp[MAX_N];
int invSA[MAX_N];

int N;

bool cmp(const int x, const int y)
{
    return S[x] < S[y];
}

void SuffixSort()
{
    for (int i = 0; i < N; ++i)
        SA[i] = i;

    sort(SA, SA + N, cmp);

    int nrGroup = 0;
    pos[0] = 0;

    for (int i = 1; i < N; ++i)
    {
        if (S[ SA[i] ] != S[ SA[i - 1] ])
        {
            nrGroup++;
            pos[nrGroup] = i;
        }

        group[ SA[i] ] = nrGroup;
    }

    for (int d = 1; d < N; d *= 2)
    {
        for (int i = 0; i < N; ++i)
            if (SA[i] >= d)
                auxSA[ pos[ group[ SA[i] - d ] ]++ ] = SA[i] - d;

        for (int i = N - d; i < N; ++i)
            auxSA[ pos[ group[i] ]++ ] = i;

        nrGroup = 0;
        SA[0] = auxSA[0];

        auxGroup[ SA[0] ] = 0;
        pos[0] = 0;

        for (int i = 1; i < N; ++i)
        {
            if(group[ auxSA[i] ] != group[ auxSA[i - 1] ] || auxSA[i] >= N - d ||
               auxSA[i - 1] >= N - d || group[ auxSA[i] + d ] != group[ auxSA[i - 1] + d ])
            {
                nrGroup++;
                pos[nrGroup] = i;
            }

            SA[i] = auxSA[i];
            auxGroup[ SA[i] ] = nrGroup;
        }

        for (int i = 0; i < N; ++i)
            group[i] = auxGroup[i];
    }
}

void LCP()
{
    for ( int i = 0; i < N; ++i )
        invSA[ SA[i] ] = i;

    int l = 0;

    for ( int i = 0; i < N; ++i )
    {
        if ( invSA[i] )
        {
            int k = invSA[i];
            int j = SA[k - 1];

            while ( S[i + l] == S[j + l] ) l++;

            lcp[k] = l;

            if ( l > 0 )
                l--;
        }
    }
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> S;
    N = strlen(S);

    S[N++] = '$';

    SuffixSort();

    for (int i = 0; i < N - 1; ++i)
        SA[i] = SA[i + 1];

    N--;
    S[N] = '\0';

    for (int i = 0; i < N; ++i)
        cout << SA[i] << "\n";
}
