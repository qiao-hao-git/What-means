#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn    1000050
int a[maxn];


int main()
{
    int T,m,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int t;
        for(int i=1;i<n;i++){
            for(int j=1;j<=n-i;j++){
                if(a[j]>a[j-1]){
                    t=a[j];
                    a[j]=a[j-1];
                    a[j-1]=t;
                }
            }
        }
        for(int i=0;i<m;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
