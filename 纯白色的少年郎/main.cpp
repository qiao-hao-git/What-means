
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
const int maxm=1e5+10;
const int inf=0x3f3f3f3f;
int head[maxn];
long long dis[maxn];
int vis[maxn],cnt,n,m,s,a,b,k;
long long c;
struct Edge
{
	int before;
	int to;
	long long w;
}edge[maxm];
void add(int u,int v,long long w)
{
	edge[k].to=v;
	edge[k].w=w;
	edge[k].before=head[u];
	head[u]=k++;
}
int main()
{
	k=0;
	memset(dis,inf,sizeof dis);
	memset(head,-1,sizeof head);
	memset(vis,0,sizeof vis);
	cin>>n>>m>>s;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		add(a,b,c);
	}
	typedef pair<int,int> dui;
	priority_queue<dui,vector<dui> ,greater<dui> > q;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		long long distance=q.top().first;
		int dot=q.top().second;
		q.pop();
		if(vis[dot])
		continue;
		vis[dot]=1;
		for(int i=head[dot];i!=-1;i=edge[i].before)
		{
			if(dis[edge[i].to]>dis[dot]+edge[i].w)
			{
				dis[edge[i].to]=dis[dot]+edge[i].w;
				q.push(make_pair(dis[edge[i].to],edge[i].to));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==inf)
		{
			cout<<-1<<endl;
		}
        else{
            cout<<dis[i]<<endl;
        }
	}
	return 0;
}


