#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
const int maxn=5e5+5;
const int INF=1e9+5;
const int maxm=5e5+5;
struct  edge{
    int to;
    int dis;
    edge(int _to=0,int _dis=0):to(_to),dis(_dis){}
};
vector<edge> e[maxm];
bool vis[maxn];
int dis[maxn],i;

void add(int u,int v,int w){
    e[u].push_back(edge(v,w));
    e[v].push_back(edge(u,w));
}
struct node
{
    int first;
    int second;
    bool operator <( const node &x )const
    {
        return x.first < second;
    }
};
std::priority_queue<node> q;
void dijkstra(int n,int s){
    for(i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    q.push(node{0,s});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(i=0;i<e[u].size();i++){
            int v=e[u][i].to;
            if(dis[v]>dis[u]+e[u][i].dis){
                dis[v]=dis[u]+e[u][i].dis;
            }
            if(!vis[v]){
                q.push(node{dis[v],v});
            }
        }
    }
}
int main()
{
    int n,m,u,v,a,b,s=1;
    memset(e,0,sizeof(e));
    scanf("%d%d",&n,&m);
    for(i=1;i<=n-1;i++){
        scanf("%d%d",&u,&v);
        add(u,v,1);
    }
    while(m--){
        scanf("%d%d",&a,&b);
        memset(vis,0,sizeof(vis));
        dijkstra(n,a);
        printf("%d\n",dis[b]);
    }
    return 0;
}
