#include <iostream>
#include <string.h>
const long long maxn=1e5+10;
const long long mod=998244353;
using namespace std;
long long n,m,k,opt,L,R;
long long cnt[maxn];
struct node{
    int l,r;
    long long value;
    long long lazy1,lazy2;
}rt[maxn<<2];
void pushup(long long k){
    rt[k].value=(rt[k<<1].value+rt[k<<1|1].value)%mod;
}
void pushdown(long long k){
    rt[k<<1].value=(rt[k<<1].value*rt[k].lazy1+(rt[k<<1].r-rt[k<<1].l+1)*rt[k].lazy2)%mod;
    rt[k<<1|1].value=(rt[k<<1|1].value*rt[k].lazy1+(rt[k<<1|1].r-rt[k<<1|1].l+1)*rt[k].lazy2)%mod;
    rt[k<<1].lazy1=(rt[k<<1].lazy1*rt[k].lazy1)%mod;
    rt[k<<1|1].lazy1=(rt[k<<1|1].lazy1*rt[k].lazy1)%mod;
    rt[k<<1].lazy2=(rt[k].lazy1*rt[k<<1].lazy2+rt[k].lazy2)%mod;
    rt[k<<1|1].lazy2=(rt[k].lazy1*rt[k<<1|1].lazy2+rt[k].lazy2)%mod;
    rt[k].lazy1=1;
    rt[k].lazy2=0;
}
void build(long long k,long long l,long long r){
    rt[k].l=l;
    rt[k].r=r;
    rt[k].lazy1=1;
    rt[k].lazy2=0;
    if(l==r){
        rt[k].value=cnt[l]%mod;
    }else{
        long long mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        pushup(k);
    }
}
void update(long long x,long long l,long long r,long long opt,long long k){
    if(rt[x].l>r||rt[x].r<l){
        return;
    }
    if(rt[x].l>=l&&rt[x].r<=r&&opt==1){
        rt[x].value=(rt[x].value*k)%mod;
        rt[x].lazy1=(rt[x].lazy1*k)%mod;
        //rt[x].lazy2=(rt[x].lazy2*k)%mod;
        return;
    }
    if(rt[x].l>=l&&rt[x].r<=r&&opt==2){
        rt[x].value=(rt[x].value+k*(rt[x].r-rt[x].l+1))%mod;
        rt[x].lazy2=(rt[x].lazy2+k)%mod;
        return;
    }
    pushdown(x);
    long long mid=(rt[x].l+rt[x].r)>>1;
    if(l<=mid){
        update(x<<1,l,r,opt,k);
    }
    if(r>mid){
        update(x<<1|1,l,r,opt,k);
    }
    rt[x].value=(rt[x<<1].value+rt[x<<1|1].value)%mod;
}

long long quiry(long long x,long long L,long long R){
    if(L<=rt[x].l&&R>=rt[x].r){
        return rt[x].value%mod;
    }
    pushdown(x);
    long long mid=(rt[x].l+rt[x].r)>>1;
    long long ans=0;
    if(R>mid){
        ans+=quiry(x<<1|1,L,R);
    }
    ans%=mod;
    if(L<=mid){
        ans+=quiry(x<<1,L,R);
    }
    ans%=mod;
    return ans;
}
int main(){
    scanf("%lld%lld",&n,&m);
    long long i;
    for(i=1;i<=n;i++){
        scanf("%lld",&cnt[i]);
    }
    build(1,1,n);
    for(i=1;i<=m;i++){
        scanf("%lld",&opt);
        if(opt==1||opt==2){
            scanf("%lld%lld%lld",&L,&R,&k);
            update(1,L,R,opt,k);
        }
        if(opt==3){
            scanf("%lld%lld",&L,&R);
            printf("%lld\n",quiry(1,L,R));
        }
    }
	return 0;
}
