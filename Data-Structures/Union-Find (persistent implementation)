#include <bits/stdc++.h>

using namespace std;

class Persistent_UnionFind
{
public:

    Persistent_UnionFind() : parent(), sizeComp(), stiva(), nrComp(0), N(0) {
    }

    Persistent_UnionFind(const int n) : parent(vector<int>(n + 1)),
        sizeComp(vector<unsigned int>(n + 1)),
        stiva(vector<pair<int,int>>(8)), nrComp(n), N(n) {

        this->reset();
    }

    void reset()
    {
        for (int i = 1; i <= N; ++i)
            MakeSet(i);
    }

    int Find(int x) const
    {
        assert(1 <= x && x <= N);

        if (parent[x] != x)
            return Find(parent[x]);
        else
            return parent[x];
    }

    void Union(int x, int y)
    {
        assert(1 <= x && x <= N);
        assert(1 <= y && y <= N);

        x = Find(x);
        y = Find(y);

        pair<int,int> op{-1, -1};

        if (x != y)
        {
            if (sizeComp[x] < sizeComp[y])
                swap(x, y);

            /// append y to x
            sizeComp[x] += sizeComp[y];
            parent[y] = x;

            this->nrComp--;
            assert(this->nrComp >= 1);
            op = {x, y}; ///x-root, y-son
        }

        stiva.push_back(op);
    }

    void rollback()
    {
        assert(stiva.size() > 0);

        pair<int,int> op = stiva.back();
        stiva.pop_back();

        if (op.first != -1)
            disconnect(op.first, op.second);
    }

    bool connected(int x, int y) const
    {
        return Find(x) == Find(y);
    }

    unsigned int sizeComponent(int x) const
    {
        return sizeComp[Find(x)];
    }

    unsigned int numberOfComponents() const
    {
        return this->nrComp;
    }

private:

    vector<int> parent;
    vector<unsigned int> sizeComp;
    vector<pair<int,int>> stiva;

    unsigned int nrComp;
    int N;

    void MakeSet(const int x)
    {
        assert(1 <= x && x <= N);

        parent[x] = x;
        sizeComp[x] = 1;
    }

    void disconnect(int x, int y) /// disconned y from x
    {
        assert(1 <= x && x <= N);
        assert(1 <= y && y <= N);

        if (parent[y] == x)
        {
            parent[y] = y;
            sizeComp[x] -= sizeComp[y];

            this->nrComp++;
            assert(this->nrComp <= static_cast<unsigned int>(N));
        }
    }
};

int main()
{
    return 0;
}
