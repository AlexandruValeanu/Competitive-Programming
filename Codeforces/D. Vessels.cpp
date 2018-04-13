#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 1;

int capacity[Nmax];
int flow[Nmax];

set<int> Set;

int N, Q;

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> capacity[i];

    for (int i = 1; i <= N; ++i)
        Set.insert(i);

    cin >> Q;

    while (Q--)
    {
        int tip, p, x;

        cin >> tip;

        if (tip == 1)
        {
            cin >> p >> x;

            auto it = Set.lower_bound(p);
            vector<int> toErase;

            if (it == Set.end())
                continue;

            while (true)
            {
                int delta = min(capacity[*it] - flow[*it], x);

                flow[*it] += delta;
                x -= delta;

                if (flow[*it] == capacity[*it])
                    toErase.push_back(*it);

                it++;

                if (it == Set.end() || !x) break;
            }

            for (auto x: toErase)
                Set.erase(x);
        }
        else
        {
            cin >> p;
            cout << flow[p] << "\n";
        }
    }

    return 0;
}
