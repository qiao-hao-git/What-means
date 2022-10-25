#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a=4,i,count=2;
    if(n==1){
        printf("1\n");
    }
    else    if(n==2||n==3||n==4){
        printf("2\n");
    }
    else{
        for(i=4;i<n;i++){
            if(i=2*a+1){
                a=3*a+1;
                count++;
                if(a>=n){
                    break;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
