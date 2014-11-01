#include <bits/stdc++.h>

using namespace std;

template <typename Type1, typename Type2, Type2 MOD>
class FibonacciSolver
{
public:

    FibonacciSolver()
    {
        F.clear();
        F[0] = F[1] = 1;
    }

    Type2 solve( Type1 n )
    {
        return f(n);
    }

private:

    map <Type1, Type2> F;

    Type2 f( Type1 n )
    {
        if ( F.count( n ) )
            return F[n];

        Type1 k = n >> 1;

        if ( n % 2 == 0 )
            return F[n] = ( 1LL * f(k - 1) * f(k - 1) + 1LL * f(k) * f(k) ) % MOD;
        else
            return F[n] = ( 1LL * f(k - 1) * f(k) + 1LL * f(k) * f(k + 1) ) % MOD;
    }
};

int main()
{
    return 0;
}
