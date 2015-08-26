#include <bits/stdc++.h>

using namespace std;

template <const size_t MAX_SIZE>
class LinearProbing
{
private:

    static const int NIL = -1;
    static const int DELETED = -2;

    int *table;

public:

    LinearProbing() : table(new int [MAX_SIZE]) {

        for (size_t i = 0; i < MAX_SIZE; ++i )
            table[i] = NIL;
    }

    ~LinearProbing()
    {
        delete[] table;
    }

    size_t h(const int key) const
    {
        return hash<int>()(key) % MAX_SIZE;
    }

    void insert(const int key)
    {
        size_t p = h(key);

        while (table[p] != NIL && table[p] != DELETED && table[p] != key)
            p = (p + 1) % MAX_SIZE;

        table[p] = key;
    }

    bool find(const int key) const
    {
        size_t p = h(key);

        while (table[p] != NIL && table[p] != key)
            p = (p + 1) % MAX_SIZE;

        return table[p] == key;
    }

    void erase(const int key)
    {
        size_t p = h(key);

        while (table[p] != NIL && table[p] != key)
            p = (p + 1) % MAX_SIZE;

        if (table[p] == key)
            table[p] = DELETED;
    }
};

int main()
{
    return 0;
}
