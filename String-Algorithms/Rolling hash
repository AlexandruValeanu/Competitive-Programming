#include <bits/stdc++.h>

using namespace std;

template <const int MOD, const int BASE>
class RollingHash
{
    /**
        MOD * BASE < INT.MAX_VALUE
        BASE * BASE < INT.MAX_VALUE
        MOD * SIGMA < INT.MAX_LALUE
    **/

public:

    int code;
    int base;

    RollingHash(const int length = 0) : code(0), base(1) {

        for (int i = 1; i < length; ++i)
            base = (base * BASE) % MOD;
    }

    void pop_front(const char ch)
    {
        code = (code - (base * ch) % MOD + MOD) % MOD; ///POSSIBLE OVERFLOW
    }

    void push_back(const char ch)
    {
        code = (code * BASE) % MOD; ///POSSIBLE OVERFLOW
        code = (code + ch) % MOD;
    }

    bool operator == (const RollingHash& R) const
    {
        return this->code == R.code;
    }

    bool operator != (const RollingHash& R) const
    {
        return this->code != R.code;
    }
};

int main()
{
    return 0;
}
