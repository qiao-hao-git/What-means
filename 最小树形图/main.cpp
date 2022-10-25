#include <iostream>
#include<bits/stdc++.h>

const int maxm=10010;
const int maxn=110;
const int inf=1e9;
using namespace std;
struct edge{
    int u,v,w;
}e[maxm];
int cnt,ans,n,m,r;
int dis[maxn],fa[maxm],ac[maxm],t[maxn];
int zl(){
    while(1){
        for(int i=1;i<=n;i++){
            dis[i]=inf;
            ac[i]=0;
            t[i]=0;
            fa[i]=0;
        }
        for(int i=1,v,w;i<=m;i++){
            if(e[i].u!=e[i].v&&(w=e[i].w)<dis[v=e[i].v]){
				dis[v]=w;
				fa[v]=e[i].u;
			}
        }
        dis[r]=0;
        for(int i=1;i<=n;i++){
            ans+=dis[i];
            if(dis[i]==inf){
                return -1;
            }
        }
        for(int i=1,j=1;i<=n;i++,j=i){
            while(j!=r&&ac[j]!=i&&!t[j]){
                ac[j]=i;
                j=fa[j];
            }
            if(j!=r&&!t[j]){
                t[j]=++cnt;
                for(int k=fa[j];k!=j;k=fa[k]){
                    t[k]=cnt;
                }
            }
        }
        if(!cnt){
            return ans;
        }
        for(int i=1;i<=n;i++){
            if(!t[i]){
                t[i]=++cnt;
            }
        }
        for(int i=1;i<=m;i++){
            e[i].w-=dis[e[i].v];
            e[i].u=t[e[i].u];
            e[i].v=t[e[i].v];
        }
        r=t[r];
        n=cnt;
        cnt=0;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&r);
    int u,v,w;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        e[i].u=u;
        e[i].v=v;
        e[i].w=w;
    }
    printf("%d\n",zl());
    return 0;
}
