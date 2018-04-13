#include <bits/stdc++.h>

using namespace std;

const int Nmax = 30000 + 1;

unordered_set<int> G[Nmax];
queue<int> Q;
int N, M;
int size4, size3;

void countCliques()
{
    size4 = 0; size3 = 0;

    for (int i = 1; i <= N; ++i)
        if (G[i].size() < 6)
            Q.push(i);

    while (Q.empty() == false)
    {
        int nod = Q.front();
        Q.pop();

        for (auto v1 = G[nod].begin(); v1 != G[nod].end(); ++v1)
        {
            for (auto v2 = v1; v2 != G[nod].end(); ++v2)
            {
                if (*v1 != *v2 && G[*v1].count(*v2))
                {
                    size3++;

                    for (auto v3 = v2; v3 != G[nod].end(); ++v3)
                    {
                        if (*v3 != *v2 && G[*v3].count(*v1) && G[*v3].count(*v2))
                        {
                            size4++;
                        }
                    }
                }
            }
        }

        for (int it: G[nod])
        {
            G[it].erase(nod);

            if (G[it].size() < 6)
                Q.push(it);
        }

        G[nod].clear();
    }
}

int main()
{
    ifstream in("count.in");
    ofstream out("count.out");

    ios_base::sync_with_stdio(false);

    in >> N >> M;

    for (int i = 1; i <= M; ++i)
    {
        int a, b;
        in >> a >> b;

        G[a].insert(b);
        G[b].insert(a);
    }

    countCliques();

    if (size4)
        out << "4 " << size4 << "\n";
    else if (size3)
        out << "3 " << size3 << "\n";
    else
        out << "2\n";

    return 0;
}
