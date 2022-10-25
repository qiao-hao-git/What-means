#include <iostream>
#include <string.h>
#include <stack>
#define maxn 200010
using namespace std;
int n,m,u,v,x,y;
int tot,cnt,top,color_cnt;
int vis[maxn];
int dfn[maxn],low[maxn],color[maxn],head[maxn];
struct edge{
    int to,next;
}e[maxn];
void add(int u,int v){
    e[++tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
}
void tarjan(int u){
    int i;
    vis[u]=1;
    low[u]=dfn[u]=++cnt;
    s.push(u);
    for(i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        color_cnt++;
        int u1=-1;
        while(u1!=u){
            u1=s.top();
            s.pop();
            vis[u1]=0;
            color[u1]=color_cnt;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=m;i++){
        scanf("%d%d%d%d",&u,&x,&v,&y);
        add(u+n*(x^1),v+n*y);
        add(v+n*(y^1),u+n*x);
    }
    for(i=1;i<=2*n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(i=1;i<=n;i++){
        if(color[i]==color[i+n]){
            printf("NO\n");
            return  0;
        }
    }
    printf("YES\n");
    return 0;
}
