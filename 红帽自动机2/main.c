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
    int flag;
    while(1){
        flag=0;
        for(i=1;i<=n;i++){
            if(i==x){
                continue;
            }
            if(b[i]>=b[x]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            break;
        }
        for(i=1;i<=n;i++){
            b[i]++;
        }
        for(i=1;i<=n;i++){
            if(i==x){
                continue;
            }
            if(b[i]>=b[x]){
                b[i]--;
                break;
            }
        }
        count++;
    }
    printf("%d\n",count);
    return 0;
}
