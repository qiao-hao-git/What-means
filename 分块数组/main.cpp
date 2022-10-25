#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5 + 5;
int n,block,belog[maxn],l,r,m;
int a[maxn],t[maxn],really[maxn];
int dp[2005][2005];
vector<int> v[maxn];
int num[maxn];

void init(int x){
    int Max_num=0;
    memset(num,0,sizeof(num));
    int mode=0;
    for(int i=(x-1)*block+1;i<=n;i++){
        int t=belog[i];
        num[a[i]]++;
        if(num[a[i]]>Max_num){
            Max_num=num[a[i]];
            mode=a[i];
        }
        if (Max_num==num[a[i]]&&mode>a[i])
            mode=a[i];
        dp[x][t]=mode;
    }
}
int solve(int l,int r,int a) {
    vector<int>::iterator x=upper_bound(v[a].begin(),v[a].end(),r);
    vector<int>::iterator y=lower_bound(v[a].begin(),v[a].end(),l);
    return x-y;
}
int query(int l, int r) {
    int t1=belog[l];
    int t2=belog[r];
    int mode=dp[t1+1][t2-1];
    int Max_num=solve(l,r,mode);
    for (int i=l;i<=min(r,t1*block);i++) {
        int t=solve(l,r,a[i]);
        if (Max_num<t||(Max_num==t&&mode>a[i])){
            Max_num=t;
            mode=a[i];
        }
    }
    if (t1!=t2){
        for(int i=(t2-1)*block+1;i<=r;i++){
            int t=solve(l,r,a[i]);
            if (Max_num<t||(Max_num==t&&mode>a[i])){
                Max_num=t;
                mode=a[i];
            }
        }
    }
    return mode;
}
int main(){
    scanf("%d",&n);
    block=50;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[i]=a[i];
        belog[i]=(i-1)/block+1;
    }
    sort(t+1,t+1+n);
    m=unique(t+1,t+1+n)-t-1;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(t+1,t+1+m,a[i])-t;
    }
    for (int i=1;i<=n;i++){
        v[a[i]].push_back(i);
    }
    for(int i=1;i<=belog[n];i++){
        init(i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        printf("%d\n",t[query(l,r)]);
    }
    return 0;
}
