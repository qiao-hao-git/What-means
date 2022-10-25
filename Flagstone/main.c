#include <stdio.h>
#include <stdlib.h>
int a[100001];
int b[100001];
int main()
{
    int T,n,i;
    double l,r,ll,rr;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<n;i++){
            scanf("%d",&b[i]);
        }
        l=a[1]+b[1];
        r=a[1]+b[1]+a[2];
        int s=0;
        for(i=1;i<n;i++){
            s+=a[i]+b[i];
            ll=(double)(s/i);
            rr=(double)((s+a[i+1])/i);
            if(ll>l){
                l=ll;
            }
            if(rr<r){
                r=rr;
            }
        }
        if(r>=l){
            printf("%.2lf\n",l);
        }
        else{
            printf("impossible\n");
        }
    }
    return 0;
}
