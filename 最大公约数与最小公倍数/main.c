#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,a,b;
    scanf("%d",&T);
    if(T>0&&T<=100){
        while(T--){
            scanf("%d%d",&a,&b);
            if(a>0&&b>0){
                int res,m=a,n=b;
                while(n>0){
                    res=m%n;
                    m=n;
                    n=res;
                }
                printf("%d %d\n",m,a*b/m);
            }
        }
    }
    return 0;
}
