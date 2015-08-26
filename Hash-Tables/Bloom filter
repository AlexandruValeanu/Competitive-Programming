#include <bits/stdc++.h>

using namespace std;

class BloomFilter
{
private:

    class Bitset
    {
    private:

        unsigned long long *b;

    public:

        Bitset() : b(nullptr) {
        }

        Bitset(const int _size) : b(new unsigned long long[1 + (_size >> 6)]) {

            memset(b, 0, sizeof(b));
        }

        void set(const int p)
        {
            b[p >> 6] |= (1ULL << (p & 63));
        }

        bool test(const int p) const
        {
            return (b[p >> 6]  >> (p & 63)) & 1;
        }
    };

    int N;
    vector<int> primes;

    Bitset *filter;

public:

    BloomFilter() : N(0), primes(vector<int>()), filter(nullptr) {
    }

    BloomFilter(const vector<int> &v) : N(v.size()), primes(v), filter(new Bitset[v.size()]) {

        for (int i = 0; i < N; ++i)
            filter[i] = Bitset(primes[i]);
    }

    inline void insert(const int key)
    {
        for (int i = 0; i < N; ++i)
            filter[i].set(key % primes[i]);
    }

    inline bool find(const int key) const
    {
        for (int i = 0; i < N; ++i)
            if (filter[i].test(key % primes[i]) == false)
                return false;

        return true;
    }
};

int main()
{
    return 0;
}
