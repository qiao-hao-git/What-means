#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn    1000002

int a[maxn];

int main()
{
    memset(a,0,sizeof(a));
    int n,m,i,h;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&h);
        a[h]++;
    }
    for(i=maxn-3;i>=1;i--){
        if(a[i+1]!=0){
            a[i]+=a[i+1];
        }
    }
    for(i=0;i<m;i++){
        scanf("%d",&h);
        printf("%d\n",a[h]);
    }
    return 0;
}
