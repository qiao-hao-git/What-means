#include<bits/stdc++.h>

const int MaxN=200010,MaxM=200010;
const long long int inf=1e15;
struct edge
{
    long long to,next;
    long long dis;
};

edge e[MaxM];
long long head[MaxN],cnt;
long long dis[MaxN];
bool vis[MaxN];
long long n,m,s;

void add_edge(long long u,long long v,long long d)
{
    cnt++;
    e[cnt].dis=d;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}

struct node
{
    long long dis;
    long long pos;
    bool operator<(const node &x)const
    {
        return x.dis<dis;
    }
};

std::priority_queue<node> q;
void dijkstra()
{
    dis[s]=0;
    q.push((node){0,s});
    while(!q.empty())
    {
        node tmp=q.top();
        q.pop();
        long long x=tmp.pos;
        if(vis[x]){
            continue;
        }
        vis[x]=1;
        for(long long i=head[x];i;i=e[i].next)
        {
            long long y=e[i].to;
            if(!vis[y]&&dis[y]>dis[x]+e[i].dis)
            {
                dis[y]=dis[x]+e[i].dis;
                q.push((node){dis[y],y});
            }
        }
    }
}


int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(long long i=0;i<m;i++)
    {
        long long u,v;
        long long w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add_edge(u,v,w);
    }

        memset(vis,0,sizeof(vis));
        for(long long i=1;i<=n;i++){
            dis[i]=inf;
        }
        dijkstra();
    for(long long i=1;i<=n;i++){
        if(dis[i]==inf){
            printf("-1\n");
        }
        else{
            printf("%lld\n",dis[i]);
        }
    }
    return 0;
}
