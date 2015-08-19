#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
}

pair<int,int> floyd_cycle_detection(const int x0)
{
    int slow = f(x0);
    int fast = f(f(x0));

    while (slow != fast)
    {
        slow = f(slow);
        fast = f(f(fast));
    }

    int start = 0;
    fast = x0;

    while (slow != fast)
    {
        slow = f(slow);
        fast = f(fast);
    }

    int length = 1;
    fast = f(slow);

    while (slow != fast)
    {
        fast = f(fast);
        length++;
    }

    return {start, length};
}

int main()
{
    return 0;
}
