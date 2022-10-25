#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)==1){
        if(n==0){
            printf("no\n");
        }
        else{
            if(n%8==2||n%8==6){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
    }
    return 0;
}
