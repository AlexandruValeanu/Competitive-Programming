#include <bits/stdc++.h>

using namespace std;

struct FenwickTree
{
    int N;
    vector<int> aib;

    FenwickTree(){
    }

    FenwickTree(const int n) : N(n), aib(vector<int>(n, 0)) {
    }

    ~FenwickTree()
    {
        aib.clear();
    }

    inline int lsb(int x)
    {
        return x & (-x);
    }

    void update(int pos, int val)
    {
        while (pos <= N)
        {
            aib[pos] += val;
            pos += lsb(pos);
        }
    }

    int query(int pos)
    {
        int sum = 0;

        while (pos >= 1)
        {
            sum += aib[pos];
            pos -= lsb(pos);
        }

        return sum;
    }

    int query(int x, int y)
    {
        return query(y) - query(x);
    }
};

const int Nmax = 2000 + 1;

int A[Nmax];
int dp[Nmax][Nmax];
map<int, int> Map;
int N, Q;

void normalizare()
{
    for (int i = 1; i <= N; ++i)
        Map[ A[i] ]++;

    int nrc = 0;

    for (auto& it: Map)
        it.second = ++nrc;

    for (int i = 1; i <= N; ++i)
        A[i] = Map[ A[i] ];
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    cin >> N >> Q;

    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    normalizare();

    int Limit = *max_element(A + 1, A + N + 1) + 1;

    for (int i = 1; i <= N; ++i)
    {
        FenwickTree BIT_r(Limit);
        FenwickTree BIT_k(Limit); ///decreasing
        FenwickTree BIT_j(Limit);
        FenwickTree BIT_i(Limit); ///decresing

        BIT_i.update(Limit - A[i], +1);

        for (int j = i + 1; j <= N; ++j)
        {
            dp[i][j] = BIT_r.query(A[j] - 1);

            int t1 = BIT_k.query(Limit - A[j] - 1);
            BIT_r.update(A[j], t1);

            int t2 = BIT_j.query(A[j] - 1);
            BIT_k.update(Limit - A[j], t2);

            int t3 = BIT_i.query(Limit - A[j] - 1);
            BIT_j.update(A[j], t3);
        }
    }

    while (Q--)
    {
        int x, y;
        cin >> x >> y;
        cout << dp[x][y] << "\n";
    }

    return 0;
}
