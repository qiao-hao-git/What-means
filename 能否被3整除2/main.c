#include <stdio.h>
#include <stdlib.h>

int fun(int a,int   b,int   n){
    if(n==0){
        return a;
    }
    else    if(n==1){
        return b;
    }
    else{
        return fun(a,b,n-1)+fun(a,b,n-2);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,m,n;
        scanf("%d%d%d",&a,&b,&m);
        if(a%3==0&&b%3==0){
            while(m--){
                scanf("%d",&n);
                printf("Yes\n");
            }
        }
        else{
            int k;
            for(int i=0;i<50;i++){
                if(fun(a,b,i)%3==0){
                    k=i;
                    break;
                }
            }
            while(m--){
                scanf("%d",&n);
                if((n-k)%4==0){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
