#include <bits/stdc++.h>

using namespace std;

template <const size_t MAX_SIZE>
class QuadraticProbing
{
private:

    static const int NIL = -1;
    static const int DELETED = -2;

    int table[MAX_SIZE];

    inline bool check(const size_t pos, const int key) const
    {
        return table[pos] != NIL && table[pos] != key;
    }

    int supposedPosition(const int key) const
    {
        size_t pos = 0;

        while (check((key + pos * pos) % MAX_SIZE, key) == true)
            pos++;

        return (key + pos * pos) % MAX_SIZE;
    }

public:

    QuadraticProbing()
    {
        for (int i = 0; i < MAX_SIZE; ++i)
            table[i] = NIL;
    }

    void insert(const int key)
    {
        table[supposedPosition(key)] = key;
    }

    bool find(const int key)
    {
        return table[supposedPosition(key)] == key;
    }

    void erase(const int key)
    {
        int pos = supposedPosition(key);

        if (table[pos] == key)
            table[pos] = DELETED;
    }
};

int main()
{
    return 0;
}
