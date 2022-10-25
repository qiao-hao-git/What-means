#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 50005
struct node{
	int v;
	int w=1;
};
int n,m;
vector<node>G[MAXN*2];
int dis[MAXN],dep[MAXN],f[MAXN][20];
void Init()
{
	for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            if(f[i][j-1]!=-1){
                f[i][j]=f[f[i][j-1]][j-1];
            }
        }
	}
	return ;
}

void dfs(int u,int p,int d)
{
	dep[u]=d;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].v,w=G[u][i].w;
		if(v==p) continue;
		f[v][0]=u;
		dis[v]=dis[u]+w;
		dfs(v,u,d+1);
	}
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]){
        swap(u,v);
	}
	int k=0;
	while((1<<k)<=dep[u]){
        k++;
	}
	k--;
	for(int j=k;j>=0;j--){
        if(dep[u]-(1<<j)==dep[v]){
            u=f[u][j];
        }
	}
	while(dep[u]>dep[v]){
        u=f[u][0];
	}
	if(u==v) return u;
	for(int j=k;j>=0;j--)
	{
		if(f[u][j]!=f[v][j]&&f[u][j]!=-1&&f[v][j]!=-1){
            u=f[u][j],v=f[v][j];
		}
	}
	return f[u][0];
}
int ans(int u,int v)
{
	return dis[u]+dis[v]-2*dis[LCA(u,v)];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1 ;i++)
	{
		int u,v ;
		scanf("%d%d%d",&u,&v);
		node t;t.v=v,t.w=1;
		G[u].push_back(t);
		t.v=u,G[v].push_back(t);
	}
	memset(f,-1,sizeof(f));
	dfs(1,-1,0);
	Init();
	while(m--)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		printf("%d\n",ans(u,v));
	}
	return 0;
}
