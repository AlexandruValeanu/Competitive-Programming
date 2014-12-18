#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
 
#define pp pair <int,int>
#define ox first
#define oy second
 
#define Nmax 1001
#define inf 2000000
 
using namespace std;
 
int dl[]={ -1, 0, 1, 0};
int dc[]={ 0, 1, 0, -1};
 
int mat[Nmax][Nmax];
int rob1[Nmax][Nmax];
int rob2[Nmax][Nmax];
int viz1[Nmax][Nmax];
int viz2[Nmax][Nmax];
 
int n,k;
int xT, yT;
int xS1, yS1;
int xS2, yS2;
int xR1, yR1;
int xR2, yR2;
 
int r1_s1=inf , r1_s2=inf;
int r2_s1=inf, r2_s2=inf;
 
int maximul=0, nr_pasi;
 
queue <pp> Q1,Q2;
 
void citire(){
 
    FILE *f=fopen("ai.in","r");
 
    int a,b;
 
    fscanf(f,"%d",&n);
    fscanf(f,"%d%d",&xT,&yT);
    fscanf(f,"%d%d",&xS1,&yS1);
    fscanf(f,"%d%d",&xS2,&yS2);
    fscanf(f,"%d%d",&xR1,&yR1);
    fscanf(f,"%d%d",&xR2,&yR2);
    fscanf(f,"%d",&k);
 
    for(int i=1; i<=k; i++){
 
        fscanf(f,"%d%d",&a,&b);
        mat[a][b]=-1;
    }
 
    mat[xT][yT] = -1;
}
 
void bordare(){
 
    for(int i=0; i<=n+1; i++)
        mat[i][0]=mat[i][n+1]=mat[0][i]=mat[n+1][i]=-1;
}
 
void afis(int x[][Nmax]){
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<x[i][j]<<" ";
        cout<<endl;
    }
}
 
int modul(int a){
 
    if(a<0)
        return a*(-1);
    else
        return a;
}
 
int determinant(int x1,int y1, int x2, int y2, int x3, int y3){
 
    return x1*y2 + y1*x3 + x2*y3 - x3*y2 - y3*x1 - x2*y1;
}
 
int intre_1(int i, int j){
 
    if(i==xS1 && j==yS1)
        return 1;
 
    if(i+j > xS1+yS1){
 
        if(i+j>xS1+yS1 && i+j<xT+yT)
            return 1;
    }
    else{
 
        if(i+j>xT+yT && i+j<xS1+yS1)
            return 1;
 
    }
 
    return 0;
}
 
int intre_2(int i, int j){
 
    if(i==xS2 && j==yS2)
        return 1;
 
    if(i+j > xS2+yS2){
 
        if(i+j>xS2+yS2 && i+j<xT+yT)
            return 1;
    }
    else{
 
        if(i+j>xT+yT && i+j<xS2+yS2)
            return 1;
 
    }
 
    return 0;
}
 
 
void initializare(){
 
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
 
            if(determinant(xS1,yS1,i,j,xT,yT)==0 && intre_1(i,j) && mat[i][j]!=-1)
                viz1[i][j]=1;
 
            if(determinant(xS2,yS2,i,j,xT,yT)==0 && intre_2(i,j) && mat[i][j]!=-1)
                viz2[i][j]=1;
        }
}
 
void gaseste(){
 
    int l,p;
 
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(mat[i][j] == -1){
 
                l=j;
                p=i;
 
                while(mat[i][l]==-1 && l<=n)
                    l++;
 
                if((l-j)>maximul)
                    maximul = (l-j);
 
                while(mat[p][j]==-1 && p<=n)
                    p++;
 
                if((p-i)>maximul)
                    maximul = (p-i);
            }
 
}
 
void lee1(){
 
    pp current, vecin;
 
    rob1[xR1][yR1]=0;
 
    Q1.push(make_pair(xR1,yR1));
 
    while(!Q1.empty()){
 
        current = Q1.front();
        Q1.pop();
 
        for(int u=0; u<4; u++){
 
            vecin.ox = current.ox + dl[u];
            vecin.oy = current.oy + dc[u];
 
            if(mat[vecin.ox][vecin.oy]==0 && rob1[vecin.ox][vecin.oy]==0){
 
                rob1[vecin.ox][vecin.oy] = rob1[current.ox][current.oy] + 1;
                Q1.push(make_pair(vecin.ox,vecin.oy));
            }
        }
    }
}
 
void lee2(){
 
    pp current, vecin;
 
    rob2[xR2][yR2]=0;
 
    Q2.push(make_pair(xR2,yR2));
 
    while(!Q2.empty()){
 
        current = Q2.front();
        Q2.pop();
 
        for(int u=0; u<4; u++){
 
            vecin.ox = current.ox + dl[u];
            vecin.oy = current.oy + dc[u];
 
            if(mat[vecin.ox][vecin.oy]==0 && rob2[vecin.ox][vecin.oy]==0){
 
                rob2[vecin.ox][vecin.oy] = rob2[current.ox][current.oy] + 1;
                Q2.push(make_pair(vecin.ox,vecin.oy));
            }
        }
    }
}
 
void cauta_minim(){
 
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
 
            if(rob1[i][j] < r1_s1 && rob1[i][j]!=0 && viz1[i][j]==1)
                r1_s1=rob1[i][j];
 
            if(rob1[i][j] < r1_s2 && rob1[i][j]!=0 && viz2[i][j]==1)
                r1_s2=rob1[i][j];
 
            if(rob2[i][j] < r2_s1 && rob2[i][j]!=0 && viz1[i][j]==1)
                r2_s1=rob2[i][j];
 
            if(rob2[i][j] < r2_s2 && rob2[i][j]!=0 && viz2[i][j]==1)
                r2_s2=rob2[i][j];
        }
}
 
int calc_max(int a, int b){
 
    if(a>b)
        return a;
    else
        return b;
}
 
void pasi(){
 
    int max1=0, max2=0;
 
    max1 = calc_max(r1_s1,r2_s2);
    max2 = calc_max(r1_s2,r2_s1);
 
    if(max1 < max2){
 
        nr_pasi = calc_max(r1_s1,r2_s2);
    }
    else{
 
        nr_pasi = calc_max(r1_s2,r2_s1);
    }
}
 
void scrie(){
 
    FILE *g=fopen("ai.out","w");
 
    fprintf(g,"%d\n%d",maximul,nr_pasi);
 
    fclose(g);
}
 
int main()
{
    citire();
    bordare();
    initializare();
    gaseste();
    lee1();
    lee2();
    cauta_minim();
    pasi();
    scrie();
 
    return 0;
}
