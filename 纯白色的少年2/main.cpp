#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
const int M = 2e5 + 5;
typedef pair<int, int> P;
struct Edge {
    int next, to, w;
}edge[M];
int n,m,s,cnt;
int head[N];
long long dis[N];
bool vis[N];
void init()
{
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(dis,INF,sizeof(dis));
    memset(vis,false,sizeof(vis));
}
void add(int u,int v,int w)
{
    edge[cnt].w=w;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void Dijkstra()
{
    priority_queue<P,vector<P>,greater<P> > q;
    dis[s]=0;
    q.push({0,s});
    while(q.size()) {
        P now=q.top();
        q.pop();
        int u=now.second;
        if(vis[u]){
            continue;
        }
        vis[u]=true;
        for(int i=head[u];~i;i=edge[i].next) {
            int v = edge[i].to;
            if(!vis[v]&&dis[v]>dis[u]+edge[i].w) {
                dis[v]=dis[u]+edge[i].w;
                q.push({dis[v],v});
            }
        }
    }
}

int main()
{
    int u,v,w;
    init();
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1; i<=m;i++) {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    Dijkstra();
    for(int i=1; i<=n;i++) {
        if(dis[i]==INF){
            printf("-1\n");
        }
        else{
            printf("%d\n",dis[i]);
        }
    }
    return 0;
}
