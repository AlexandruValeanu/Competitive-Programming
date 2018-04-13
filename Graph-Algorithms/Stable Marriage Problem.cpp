#include <bits/stdc++.h>

using namespace std;

vector<int> stableMarriage(const vector<vector<int>> &menPreffs, const vector<vector<int>> &womenPreffs)
{
    const int N = menPreffs.size();

    vector<vector<int>> mapWomanToMan(N);

    for (int i = 0; i < N; ++i)
        mapWomanToMan[i].resize(N);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            mapWomanToMan[i][ womenPreffs[i][j] ] = j;

    vector<int> manMatch(N, -1), womanMatch(N, -1);
    queue<int> bachelors;

    for (int i = 0; i < N; ++i)
        bachelors.push(i);

    while (!bachelors.empty())
    {
        int man = bachelors.front();
        bachelors.pop();

        for (int woman : menPreffs[man])
        {
            if (womanMatch[woman] == -1)
            {
                womanMatch[woman] = man;
                manMatch[man] = woman;
                break;
            }
            else
            {
                int otherMan = womanMatch[woman];

                if (mapWomanToMan[woman][man] < mapWomanToMan[woman][otherMan])
                {
                    manMatch[otherMan] = -1;
                    bachelors.push(otherMan);

                    womanMatch[woman] = man;
                    manMatch[man] = woman;
                    break;
                }
            }
        }
    }

    return manMatch;
}

int main()
{
    return 0;
}
