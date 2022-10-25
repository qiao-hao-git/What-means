#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,a,b,c;
    int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int e[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    scanf("%d",&T);
    if(T>=1&&T<=200){
        while(T--){
            scanf("%d%d%d",&a,&b,&c);
            int t;
            if(a%4==0){
                if(a%100==0){
                    if(a%400==0){
                        t=1;
                    }
                    else{
                        t=0;
                    }
                }
                else{
                    t=1;
                }
            }
            else{
                t=0;
            }
            int sum=0;
            if(t==0){
                if(b>=1&&b<=12&&c<=d[b]){
                    for(int i=0;i<b;i++){
                        sum+=d[i];
                    }
                    printf("%d\n",sum+c);
                }
            }
            else{
                if(b>=1&&b<=12&&c<=e[b]){
                    for(int i=0;i<b;i++){
                        sum+=e[i];
                    }
                    printf("%d\n",sum+c);
                }
            }
        }
    }
    return 0;
}
