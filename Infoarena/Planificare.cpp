#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000 + 1;

struct Interval
{
    int x, y;

    bool operator < (const Interval& I) const
    {
        return y < I.y;
    }
};

Interval v[Nmax];
multiset<int> MS;
int N, K, sol;

int main()
{
    ifstream in("planificare.in");
    ofstream out("planificare.out");

    in >> N >> K;

    for ( int i = 1; i <= N; ++i )
        in >> v[i].x >> v[i].y;

    sort(v + 1, v + N + 1);

    for ( int i = 1; i <= K; ++i )
        MS.insert(0);

    for ( int i = 1; i <= N; ++i )
    {
        auto it = MS.lower_bound(v[i].x);

        if ( it != MS.end() && *it == v[i].x )
        {
            sol++;
            MS.erase(it);
            MS.insert(v[i].y);
            continue;
        }

        if ( it == MS.begin() )
            continue;

        it--;
        sol++;
        MS.erase(it);
        MS.insert(v[i].y);
    }

    out << sol << "\n";

    return 0;
}
