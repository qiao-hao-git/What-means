#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,a,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        a=n%10;
        if(a==0||a==1||a==5||a==6||a==9){
           m=a;
        }
        else    if(a==2){
            if(n%4==0){
                m=6;
            }
            else{
                m=4;
            }
        }
        else    if(a==3){
            if(n%4==1){
                m=3;
            }
            else{
                m=7;
            }
        }
        else    if(a==4){
            m=6;
        }
        else    if(a==7){
            if(n%4==1){
                m=7;
            }
            else{
                m=3;
            }
        }
        else    if(a==8){
            if(n%4==2){
                m=4;
            }
            else{
                m=6;
            }
        }
        printf("%d\n",m);
    }
    return 0;
}
