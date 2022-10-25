#include <stdio.h>
#include <stdlib.h>

int fab(int a,int   b,int   n){
    if(n==1){
        return  a;
    }
    else    if(n==2){
        return  b;
    }
    else{
        return  fab(a,b,n-1)+fab(a,b,n-2);
    }
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int s;
        if(n==1){
            printf("1\n");
        }
        else{
            s=fab(1,2,n);
            printf("%d\n",s);
        }
    }
    return 0;
}
