#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        if((n>2&&k==1)||k==0||n==1){
            printf("0\n");
        }
        else    if(k<n-1){
            printf("%d\n",n*k/2);
        }
        else    if(k>=n-1){
            printf("%d\n",n*(n-1)/2);
        }
    }
    return 0;
}

