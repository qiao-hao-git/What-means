#include<iostream>
#include<string.h>
#define maxn 500010
int fa[maxn][22],depth[maxn],lg[maxn];
struct edge{
    int t;
    int next;
}e[maxn*2];
int head[maxn],tot;
int n,m,u,v,a,b;
using namespace std;
void add(int u, int v){
    tot++;
    e[tot].t=v;
    e[tot].next=head[u];
    head[u]=tot;
}
void dfs(int now,int fath){
    fa[now][0]=fath;
    depth[now]=depth[fath]+1;
    for(int i=1;i<=lg[depth[now]];i++){
        fa[now][i]=fa[fa[now][i-1]][i-1];
    }
    for(int i=head[now];i;i=e[i].next){
        if(e[i].t!=fath) {
            dfs(e[i].t,now);
        }
    }
}
int LCA(int x,int y){
    if(depth[x]<depth[y]){
        swap(x,y);
    }
    while(depth[x]>depth[y]){
        x=fa[x][lg[depth[x]-depth[y]]-1];
    }
    if(x==y){
        return  x;
    }
    for(int k=lg[depth[x]]-1;k>=0;k--){
        if(fa[x][k]!=fa[y][k]){
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return  fa[x][0];
}
int main()
{
    scanf("%d%d",&n,&m);
    tot=0;
    int i,k;
    for(i=0;i<=n;i++){
        head[i]=-1;
    }
    for(i=1;i<=n-1;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(i=1;i<=n;i++){
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    }
    dfs(1,0);
    while(m--){
        scanf("%d%d",&a,&b);
        k=LCA(a,b);
        printf("%d\n",depth[a]+depth[b]-2*depth[k]);
    }
    return 0;
}
