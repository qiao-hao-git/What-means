#include<bits/stdc++.h>

const int MaxN=500010,MaxM=500010;

struct edge
{
    int to,dis,next;
};

edge e[MaxM];
int head[MaxN],dis[MaxN],cnt;
bool vis[MaxN];
int n,m,a,b;

void add_edge( int u, int v, int d )
{
    cnt++;
    e[cnt].dis=d;
    e[cnt].to=v;
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
void dijkstra()
{
    dis[a]=0;
    q.push((node){0,a});
    while(!q.empty())
    {
        node tmp=q.top();
        q.pop();
        int x=tmp.pos,d=tmp.dis;
        if(vis[x])
            continue;
        vis[x]=1;
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].dis)
            {
                dis[y]=dis[x]+e[i].dis;
                if(!vis[y])
                {
                    q.push((node){dis[y],y});
                }
            }
        }
    }
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,1);
        add_edge(v,u,1);
    }

    while(m--){
        memset(vis,0,sizeof(vis));
        memset(dis,0x3f3f3f3f,sizeof(dis));
        scanf("%d%d",&a,&b);
        dijkstra();
        printf("%d\n",dis[b]);
    }
    return 0;
}
