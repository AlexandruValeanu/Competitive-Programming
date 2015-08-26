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

    size_t h(const int key, const size_t i) const
    {
        return (hash<int>()(key) + i) % MAX_SIZE;
    }

    void insert(const int key)
    {
        size_t i = 0;
        size_t j;

        do
        {
            j = h(key, i);

            if (table[j] == NIL || table[j] == DELETED)
            {
                table[j] = key;
                break;
            }

            i++;

        } while (i < MAX_SIZE);
    }

    bool find(const int key) const
    {
        size_t i = 0;
        size_t j;

        do
        {
            j = h(key, i);

            if (table[j] == key)
                return true;

            i++;

        } while (table[j] != NIL && i < MAX_SIZE);

        return false;
    }

    void erase(const int key)
    {
        size_t i = 0;
        size_t j;

        do
        {
            j = h(key, i);

            if (table[j] == key)
            {
                table[j] = DELETED;
                break;
            }

            i++;

        } while (table[j] != NIL && i < MAX_SIZE);
    }
};

int main()
{
    return 0;
}
