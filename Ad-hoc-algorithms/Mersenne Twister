#include <bits/stdc++.h>

using namespace std;

class MersenneTwister
{
public:

    MersenneTwister(const unsigned seed = 0)
    {
        this->reset(seed);
    }

    void reset(const unsigned seed)
    {
        pos = 0;
        MT[0] = seed;

        for (int i = 1; i < MT_N; ++i)
            MT[i] = 1812433253U * (MT[i - 1] ^ (MT[i - 1] >> 30)) + i;
    }

    unsigned rand()
    {
        if (pos == 0)
            generate_numbers();

        unsigned y = MT[pos];
        y = y ^ (y >> 11);
        y = y ^ ((y << 7) & 2636928640U);
        y = y ^ ((y << 15) & 4022730752U);
        y = y ^ (y >> 18);

        if (++pos == MT_N)
            pos = 0;

        return y;
    }

    void generate_numbers()
    {
        for (int i = 0; i < MT_N; ++i)
        {
            unsigned y = (MT[i] & 0x80000000U) + (MT[(i + 1) % MT_N] & 0x7FFFFFFFU);

            MT[i] = MT[(i + 397) % MT_N] ^ (y >> 1);

            if (y & 1)
                MT[i] = MT[i] ^ 2567483615U;
        }
    }

    /// integer in range [0...n-1]
    int nextInt(const int n)
    {
        if (n == 1)
            return 0;
        else
            return rand() % n;
    }

    /// integer in range [x...y]
    int nextInt(const int x, const int y)
    {
        if (x == y)
            return x;
        else
            return x + nextInt(y - x + 1);
    }

private:

    static const int MT_N = 624;

    unsigned MT[MT_N];
    int pos;
};

int main()
{
    return 0;
}
