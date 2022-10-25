#include <stdio.h>
#include <stdlib.h>
int a[101];

int min(int x,int y){
    if(x>y){
        return  y;
    }
    else if(x<=y){
        return  x;
    }
}
int main()
{
    int t,n,F,f;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&F);
        f=0;
        for(int i=1;i<=n;i++){
            a[i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f+=min(a[i],a[j]);
            }
        }
        if(f>F){
            printf("-1\n");
        }
        else{
            for(int i=1;i<n;i++){
                printf("%d ",a[i]);
            }
            printf("%d\n",a[n]+F-f);
        }
    }
    return 0;
}
