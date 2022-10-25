#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,max_len=0,l,sum=0,flag=0;
    scanf("%d",&n);
    if(n<3){
        printf("-1\n");
    }
    else{
        for(i=1;i<=n;i++){
            scanf("%d",&l);
            if(l>max_len){
                sum+=max_len;
                max_len=l;
            }
            else{
                sum+=l;
            }
            if(max_len<sum&&i>2){
                flag=1;
                printf("%d\n",i);
                break;
            }
        }
        if(flag==0){
            printf("-1\n");
        }
    }
    return 0;
}
