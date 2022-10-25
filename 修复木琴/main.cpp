#include <iostream>
#include <algorithm>
#define maxn 1000005
using namespace std;
int a[maxn],b[maxn],c[maxn];
int n,q;
int l,r;
int main()
{
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]]=i;
        c[i]=a[i];
    }
    while(q--){
        scanf("%d%d",&l,&r);
        for(i=1;i<=n;i++){
            if(b[i]>=l&&b[i]<=r){
                c[i]=-1;
            }
            sort(c,n);
        }
    }
    return 0;
}
