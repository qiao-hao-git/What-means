#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
const   int maxn=5005;
const   int INF=0x3f3f3f3f;
typedef pair<int,int>Edge;
vector<Edge> e[maxn];
int vis[maxn];
int dis[maxn],in[maxn];
int n,m;
bool spfa(int u){
    memset(vis,0,sizeof(vis));
    vis[u]=1;
    memset(dis,INF,sizeof(dis));
    dis[u]=0;
    memset(in,0,sizeof(in));
    in[u]=1;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i].first;
            int w=e[u][i].second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;

                    if(++in[v]==n){
                        return  false;
                    }
                }
            }
        }
    }
    return  true;
}
int main()
{
    int u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        e[0].push_back(Edge(i,0));
    }
    while(m--){
        scanf("%d%d%d",&v,&u,&w);
        e[u].push_back(Edge(v,w));
    }
    if(!spfa(0)){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    return 0;
}
