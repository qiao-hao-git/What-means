#include <iostream>
#include <vector>
#define maxn 200005
int n;
using namespace std;
int fa[maxn];
int d[maxn];
int a[maxn],b[maxn],c[maxn];
int vis[maxn];
void dfs(int k){
    vis[k]=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs[i];
            if(d[i]<d[k]){
                a[k]++;
            }
            else    if(d[i]==d[k]){
                b[k]++;
            }
            else{
                c[k]++;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<=n-1;i++){
        scanf("%d",&fa[i+1]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&d[i]);
    }
    for(i=1;i<=n;i++){
        dfs[i];
        printf("%d %d %d\n",a[i],b[i],c[i]);
    }
    return 0;
}
