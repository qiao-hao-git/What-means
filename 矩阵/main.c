#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    if(k==-1&&(n+m)%2){
        printf("0\n");
    }
    else{
        printf("%d\n",1<<((n-1)*(m-1)));
    }
    return 0;
}
