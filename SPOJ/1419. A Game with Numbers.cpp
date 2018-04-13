#include <bits/stdc++.h>

using namespace std;

int main()
{
    int heap;

    cin >> heap;

    if ( heap % 10 == 0 )
        cout << "2\n";
    else
        cout << "1\n" << heap % 10 << "\n";

    return 0;
}
