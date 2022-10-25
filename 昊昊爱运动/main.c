#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  a[2002];
int  ans[2002][2002];
int  b[2002];
int main()
{
    int n,m,q,l,r,ANS=0;
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        ANS=0;
        for(int j=i;j<=n;j++){
            if(b[a[j]]==0){
                ANS++;
                b[a[j]]++;
            }
            ans[i][j]=ANS;
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%d\n",ans[l][r]);
    }
    return 0;
}
