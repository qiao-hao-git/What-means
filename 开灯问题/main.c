#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define maxn    1001
int a[maxn];

int main()
{
    int T,n,k;
    scanf("%d",&T);
    if(T>0&&T<=100){
        while(T--){
            memset(a,0,sizeof(a));
            scanf("%d%d",&n,&k);
            for(int i=1;i<=k;i++){
                for(int j=1;j<=n;j++){
                    if(j%i==0){
                        a[j]++;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(a[i]%2!=0){
                    printf("%d ",i);
                }
            }
        }
    }
    return 0;
}
