#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn    500002
#define INF 1000000

int graph[maxn][maxn][maxn];

int min(int a,int b){
    if(a>b){
        return  b;
    }
    else{
        return  a;
    }
}

int main()
{
    int n,m,i,j,a,b,u,v,k,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                graph[0][i][j]=0;
            }
            else{
                graph[0][i][j]=INF;
            }
        }
    }
    t=n-1;
    while(t--){
        scanf("%d%d",&u,&v);
        graph[0][u][v]=graph[0][v][u]=1;
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                graph[k][i][j]=min(graph[k-1][i][j],graph[k-1][i][k]+graph[k-1][k][j]);
            }
        }
    }
    while(m--){
        scanf("%d%d",&a,&b);
        printf("%d\n",graph[n][a][b]);
    }
    return 0;
}
