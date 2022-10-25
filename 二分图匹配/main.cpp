#include <iostream>
#include <string.h>
#define maxn 210
bool tu[maxn][maxn],vis[maxn];
int link[maxn];
int m,n,u,v;
using namespace std;
bool find(int x){
    for(int i=1;i<=m;i++){
        if(!vis[i]&&tu[x][i]){
            vis[i]=1;
            if(link[i]==0||find(link[i])){
                link[i]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(tu,0,sizeof(tu));
    memset(link,0,sizeof(link));
    for(int i=1;i<=m;i++){
       scanf("%d%d",&u,&v);
       tu[u][v]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(find(i)){
            ans++;
        }
    }
    printf("%d\n",n-ans);
    return 0;
}
