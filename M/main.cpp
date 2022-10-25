#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int a[200003]={0},b[200003]={0},c[200003]={0};
vector<vector<int> >map;
int num[200003];
int vis[200003];
void dfs(int root,int son){
    if(vis[son]){
        return;
    }
    if(num[root]>num[son]){
        a[root]++;
    }
    else    if(num[root]==num[son]){
        b[root]++;
    }
    else    if(num[root]<num[son]){
        c[root]++;
    }
    for(int i=0;i<map[son].size();i++){
        if(!vis[map[son][i]]){
            dfs(root,map[son][i]);
        }
    }
}
int main()
{
	int n;
	scanf("%d",&n);
	map.resize(n+1);
	int input;
	for(int i=1;i<=n-1;++i)
	{
		scanf("%d",&input);
		map[input].push_back(i+1);
	}
	for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
	}
	for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        dfs(i,map[i][0]);
        printf("%d %d %d\n",a[i],b[i],c[i]);
	}
	return 0;
}
