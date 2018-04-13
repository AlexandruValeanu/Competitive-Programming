#include <bits/stdc++.h>

using namespace std;

class Timer
{
public:

    double start;

    Timer() : start(clock()) {
    }

    void reset()
    {
        start = clock();
    }

    double getTime() const
    {
        return (clock() - start) / CLOCKS_PER_SEC;
    }
};

int main()
{
    return 0;
}
