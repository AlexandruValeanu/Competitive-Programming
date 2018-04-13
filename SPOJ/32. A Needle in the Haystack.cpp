#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
 
using namespace std;
 
 
int main()
{
    long long n, contor, P, T;
 
    while ( cin >> n )
    {
        int *L = new int[n + 1];
        vector <int> poz;
 
        memset( L, 0, sizeof ( L ) );
 
        string Pattern, Text;
 
        cin >> Pattern >> Text;
 
        Pattern.insert( Pattern.begin(), ' ' );
        Text.insert( Text.begin(), ' ' );
 
        P = Pattern.length() - 1;
        T = Text.length() - 1;
 
        L[1] = 0;
        int k = 0;
 
        for ( int i = 2; i <= P; ++i )
        {
            while ( k && Pattern[k + 1] != Pattern[i] )
                    k = L[k];
 
            if ( Pattern[k + 1] == Pattern[i] )
                    k++;
 
            L[i] = k;
        }
 
        k = 0;
 
        for ( int i = 1; i <= T; ++i )
        {
            while ( k && Pattern[k + 1] != Text[i] )
                    k = L[k];
 
            if ( Pattern[k + 1] == Text[i] )
                    k++;
 
            if ( k == P )
            {
                poz.push_back( i - P );
                k = L[k];
            }
        }
 
        if ( poz.size() == 0 )
        {
            cout << "\n\n";
        }
        else
        {
            for ( unsigned i = 0; i < poz.size(); ++i )
                    cout << poz[i] << "\n";
        }
    }
 
 
    return 0;
}
 
