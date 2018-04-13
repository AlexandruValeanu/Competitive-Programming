#include <fstream>
#include <algorithm>
#include <cstring>
#include <iostream>
 
using namespace std ;
 
#define Nmax 100005
 
char s[Nmax];
int N, k = -1 , virg = 1, SUMA;
int st[Nmax];
 
void citire(){
 
    ifstream f("expresie2.in");
 
    while( f >> s[N++] );
 
    N--;
}
 
int suma(){
 
    int maxim = st[k], S = max(st[k], 0);
 
    k-- ;
 
    while(st[k] != 10000){
 
        S += st[k] ;
 
        if(S > maxim)
            maxim = S;
 
        if(S < 0)
            S = 0 ;
 
        k-- ;
    }
 
    return maxim ;
}
 
int mediana(){
 
    int i = k, cop;
 
    while (st[i] != 20000)
        i--;
 
    sort(st + i + 1, st + k + 1);
 
    cop = (k + i + 1) >> 1 ;
 
    k = i ;
 
    return st[cop] ;
}
 
void rezolva(){
 
    int semn, x;
 
    for (int i=0; i < N; ){
 
        if(s[i] == '(')
            st[++k] = 10000,
            i++;
        else
            if(s[i] == '[')
                st[++k] = 20000,
                i++;
 
            else
                if(s[i] == ')')
                    x = suma(),
                    st[k] = x,
                    i++;
 
                else
                    if(s[i] == ']')
                        x = mediana(),
                        st[k] = x,
                        i++;
 
                    else
                        if(s[i] != ','){
 
                            semn = 1;
 
                            if (s[i] == '-')
                                semn = -1,
                                i++;
 
                            x = 0 ;
 
                            while(i < N && isdigit(s[i]))
                                x = x * 10 + (s[i] - '0'),
                                i++;
 
                            x *= semn;
                            st[++k] = x;
                    }
                    else
                        i++,
                        virg++;
    }
 
    for(int i=0 ; i <= k ; i++)
        SUMA += st[i] ;
}
 
void afis(){
 
    ofstream g("expresie2.out");
 
    g << virg << "\n";
    g << SUMA <<"\n";
}
 
 
int main(){
 
    citire();
    rezolva();
    afis();
 
    return 0 ;
}
