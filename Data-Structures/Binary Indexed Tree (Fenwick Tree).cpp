#include <bits/stdc++.h>

using namespace std;

template <const size_t MAX_SIZE>
class BinaryIndexedTree ///1-based
{
private:

    int bit[MAX_SIZE + 1];
    int MAX_STEP;

    int lsb(int x) const
    {
        return x & (-x);
    }

    int query(size_t position) const
    {
        int sum = 0;

        while (position > 0)
        {
            sum += bit[position];
            position -= lsb(position);
        }

        return sum;
    }

public:

    BinaryIndexedTree() : MAX_STEP(1) {

        while (MAX_STEP < MAX_SIZE)
            MAX_STEP <<= 1;
    }

    void update(size_t position, const int value)
    {
        assert(1 <= position);
        assert(position <= MAX_SIZE);

        while (position <= MAX_SIZE)
        {
            bit[position] += value;
            position += lsb(position);
        }
    }

    int query(size_t start, size_t finish) const
    {
        assert(1 <= start);
        assert(start <= finish);
        assert(finish <= MAX_SIZE);

        return query(finish) - query(start - 1);
    }

    int binary_search(const int sum) const
    {
        size_t step = MAX_STEP;
        int tmpSum = sum;
        size_t position = 0;

        while (step > 0)
        {
            if (position + step <= MAX_SIZE)
            {
                if (bit[position + step] < tmpSum)
                {
                    tmpSum -= bit[position + step];
                    position += step;
                }
            }

            step >>= 1;
        }

        if (query(position + 1) == sum)
            return position + 1;
        else
            return -1;
    }

    void clear()
    {
        for (int i = 0; i <= MAX_SIZE; ++i)
            bit[i] = 0;
    }
};

int main()
{
    return 0;
}
