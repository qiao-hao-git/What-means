#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn  10004
#define INF 1000000000
int graph[maxn][maxn];
int len[maxn];
int temp[maxn];
int main()
{
    int n,m,s,i,j,u,v,w,a,b;
    scanf("%d%d%d",&n,&m,&s);
    memset(temp,0,sizeof(temp));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                graph[i][j]=INF;
            }
        }
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        u--;
        v--;
        graph[u][v]=graph[v][u]=w;
    }
    for(i=0;i<n;i++){
        if(i==s-1){
            len[i]=0;
            continue;
        }
        len[i]=graph[s-1][i];
    }
    temp[s-1]=1;
    for(i=0;i<n;i++){
        a=-1;
        b=INF;
        for(j=0;j<n;j++){
            if(j==s-1){
                continue;
            }
            if(temp[j]==0&&len[j]<b){
                b=len[j];
                a=j;
            }
        }
        if(a==-1){
            break;
        }
        if(a==n-1){
            break;
        }
        if(b==INF){
            break;
        }
        for(j=0;j<n;j++){
            if(j==s-1){
                continue;
            }
            if(temp[j]==0&&b+graph[a][j]<len[j]){
                len[j]=b+graph[a][j];
            }
        }
    }
    for(i=0;i<n;i++){
        if(i==s-1){
            printf("0\n");
            continue;
        }
        else{
            if(len[i]==INF){
                printf("-1\n");
            }
            else{
                printf("%d\n",len[i]);
            }
        }
    }
    return 0;
}
