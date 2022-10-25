#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int m,n,x;
    scanf("%d%d",&n,&m);
    x=pow(n-1,m)+pow(-1,m)*(n-1);
    printf("%d\n",x/n);
    return 0;
}

