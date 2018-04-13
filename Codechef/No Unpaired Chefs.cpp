#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100;

int M[Nmax][Nmax];
int dist[Nmax];
bool visited[Nmax];

int T, N;

int main()
{
   // ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

	cin >> T;

	while(T--)
	{
		cin >> N;

		for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> M[i][j];

		if(N == 1)
		{
			if (M[0][0])
                cout << M[0][0] << "\n";
            else
                cout << "-1\n";

            continue;
		}

		for (int i = 0; i < N; ++i)
		{
			dist[i] = M[0][i];
			visited[i] = false;
		}

		long long sol = 0;
		visited[0] = true;
		bool valid = 1;

		for (int i = 1; i < N; ++i)
		{
			int k = -1;

			for (int j = 0; j < N; ++j)
			{
				if (visited[j] == false && dist[j] != 0)
				{
					if (k == -1 || dist[k] > dist[j])
                        k = j;
				}
			}

			if (k == -1)
            {
                valid = 0;
                break;
            }

			sol += dist[k];
			visited[k] = true;

			for (int j = 0; j < N; ++j)
			{
				if(visited[j] == false && M[k][j] != 0)
				{
					if (dist[j] == 0 || dist[j] > M[k][j])
                        dist[j] = M[k][j];
				}
			}
		}

		if (valid)
            cout << 2LL * sol << "\n";
        else
            cout << "-1\n";
	}
	return 0;
}
