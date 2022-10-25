#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 305
#define inf 0x3f3f3f3f
int p[maxn][maxn],dis[maxn],ord[maxn],n,m,a,b,res,s,t;
bool vis[maxn],bin[maxn];
int sch(int x){
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    int i,j,maxc;
    dis[0]=-1;
    for(i=1;i<=n-x+1;i++){
        int maxc=0;
        for(j=1;j<=n;j++){
            if(!bin[j]&&!vis[j]&&dis[j]>dis[maxc]){
                maxc=j;
            }
        }
        vis[maxc]=true;
        ord[i]=maxc;
        for(j=1;j<=n;j++){
            if(!bin[j]&&!vis[j]){
                dis[j]+=p[maxc][j];
            }
        }
    }
    s=ord[n-x];
    t=ord[n-x+1];
    return dis[t];
}
int sw(){
    res=inf;
    int i,j;
    for(i=1;i<n;i++){
        res=min(res,sch(i));
        bin[t]=true;;
        for(j=1;j<=n;j++){
            p[s][j]+=p[t][j];
            p[j][s]+=p[j][t];
        }
    }
    return  res;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(p,0,sizeof(p));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        p[a][b]++;
        p[b][a]++;
    }
    printf("%d\n",sw());
    return 0;
}
