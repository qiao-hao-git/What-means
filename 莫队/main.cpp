#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#define maxn 100010
#define maxm 2030
using namespace std;
int n,l,r,block;
int a[maxn],bl[maxn];
int raw[maxn],cnt[maxn];
int mode[maxm][maxm];
vector<int> pos[maxn];
void discrete(){
    sort(raw+1,raw+n+1);
    int sz=unique(raw+1,raw+n+1)-raw-1;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(raw+1,raw+sz+1,a[i])-raw;
    }
}
int solve(int l,int r,int a) {
    vector<int>::iterator x=upper_bound(pos[a].begin(),pos[a].end(),r);
    vector<int>::iterator y=lower_bound(pos[a].begin(),pos[a].end(),l);
    return x-y;
}
int query(int l,int r){
    int L=bl[l],R=bl[r];
    int ans=mode[L+1][R-1];
    int Max=solve(l,r,ans);
    for(int i=l;i<=min(r,L*block);i++){
        int tot=solve(l,r,a[i]);
        if(tot>Max||(tot==Max&&a[i]<ans)){
            Max=tot;
            ans=a[i];
        }
    }
    if(L!=R){
        for(int i=(R-1)*block+1;i<=r;i++){
            int tot=solve(l,r,a[i]);
            if(tot>Max||(tot==Max&&a[i]<ans)){
                Max=tot;
                ans=a[i];
            }
        }
    }
    return  raw[ans];
}
int main(){
    scanf("%d",&n);
    int i,j;
    block=50;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        raw[i]=a[i];
        bl[i]=(i-1)/block+1;
    }
    discrete();
    for(i=1;i<=n;i++){
        pos[a[i]].push_back(i);
    }
    for(i=1;i<=bl[n];i++){
        int Max=0;
        memset(cnt,0,sizeof(cnt));
        int x=0;
        for(j=block*(i-1)+1;j<=n;j++){
            int t=bl[j];
            cnt[a[j]]++;
            if(cnt[a[j]]>Max){
                Max=cnt[a[j]];
                x=a[j];
            }
            if(Max==cnt[a[j]]&&x>a[j]){
                x=a[j];
            }
            mode[i][t]=x;
        }
    }
    for(i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return  0;
}
