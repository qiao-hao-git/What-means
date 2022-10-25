#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
#define maxn 100010
#define maxm 200010
using namespace std;
int n,m,s,u,v,w;
long long dis[maxn];
int head[maxn],in[maxn],cnt=0;
bool vis[maxn];
struct  edge{
    int to,dis,next;
}e[maxm];
void add(int u,int v,int w){
    cnt++;
    e[cnt].to=v;
    e[cnt].dis=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
struct node
{
    int dis;
    int pos;
    bool operator<( const node &x )const
    {
        return x.dis<dis;
    }
};

std::priority_queue<node> q;
void  dijkstra(){
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    q.push(node{0,s});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int u=tmp.pos;
        if(vis[u]){
            continue;
        }
        vis[u]=true;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].to,w=e[i].dis;
            if(!vis[v]&&dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push(node{dis[v],v});
            }
        }
    }
}
int main(){
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    dijkstra();
    for(int i=1;i<=n;i++){
        if(dis[i]!=INF){
            printf("%d\n",dis[i]);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
