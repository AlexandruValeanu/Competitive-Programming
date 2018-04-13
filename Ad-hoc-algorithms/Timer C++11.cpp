#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

class Timer
{
public:

    high_resolution_clock::time_point start;

    Timer() : start(high_resolution_clock::now()) {
    }

    void reset()
    {
        start = high_resolution_clock::now();
    }

    double getTime() const
    {
        high_resolution_clock::time_point finish = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(finish - start);

        return time_span.count();
    }
};

int main()
{
    return 0;
}
