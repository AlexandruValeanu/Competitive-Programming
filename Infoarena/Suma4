#include <iostream>
#include <fstream>

using namespace std;

#define Nmax 60

int mat[Nmax][Nmax][Nmax];
int cost[Nmax][Nmax][Nmax];

int N, M;

void citire(){

    freopen("suma4.in", "r", stdin);

    scanf("%d", &N);

    while(N){

        M++;

        for(int i = 1; i <= M; i++)
            for(int j = 1; j <= M; j++, N--)
                scanf("%d", &mat[M][i][j]);
    }
}

int minim(int a, int b, int c, int d){

    return min( min(a, b), min(c, d) );
}

void dinamica(){

    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= M; j++)
            cost[M][i][j] = mat[M][i][j];

    for(int k = M-1; k >= 1; k--)
        for(int i = 1; i <= k; i++)
            for(int j = 1; j <= k; j++)
                cost[k][i][j] = mat[k][i][j] + minim(cost[k+1][i][j], cost[k+1][i][j+1],
                                                    cost[k+1][i+1][j], cost[k+1][i+1][j+1]);
}

void drum(){

    int suma = cost[1][1][1];
    int i = 1, j = 1, k = 1, niv = 0;

    freopen("suma4.out", "w", stdout);

    printf("%d %d \n1 ", M, suma);

    do{

        niv += k*k;
        suma -= mat[k][i][j];
        k++;

        if(suma){

            if(cost[k][i][j] == suma);
            else
                if(cost[k][i][j+1] == suma)
                    j++;
                else
                    if(cost[k][i+1][j] == suma)
                        i++;
                    else
                        i++,
                        j++;

            printf("%d ", niv + (i-1)*k + j);
        }

    }while(suma);

}

int main(){

    citire();
    dinamica();
    drum();

    return 0;
}
