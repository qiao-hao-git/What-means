#include <stdio.h>
#include <stdlib.h>
int b[100002];
int main()
{
    int n,x,i,count=0;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(i=1;i<=n;i++){
        if(b[i]<b[x]||i==x){
            continue;
        }
        else{
            count+=b[i]-b[x]+1;
        }
    }
    printf("%d\n",count);
    return 0;
}
