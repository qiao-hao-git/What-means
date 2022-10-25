#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char    a[100001];

int main()
{
   int  T,x,y,t,i,m,n,time;
   scanf("%d",&T);
   while(T--){
        m=0;
        n=0;
        time=0;
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&x,&y,&t);
        getchar();
        scanf("%s",a);
        if(x!=0||y!=0){
            for(i=0;i<t;i++){
                if(a[i]=='U'){
                    time++;
                    if(abs(y-n)>abs(y-1-n)){
                        n++;
                        if(m==x&&n==y){
                            break;
                        }
                    }
                }
                else    if(a[i]=='D'){
                    time++;
                    if(abs(y-n)>abs(y+1-n)){
                        n--;
                        if(m==x&&n==y){
                            break;
                        }
                    }
                }
                else    if(a[i]=='L'){
                    time++;
                    if(abs(x-m)>abs(x+1-m)){
                        m--;
                        if(m==x&&n==y){
                            break;
                        }
                    }
                }
                else    if(a[i]=='R'){
                    time++;
                    if(abs(x-m)>abs(x-1-m)){
                        m++;
                        if(m==x&&n==y){
                            break;
                        }
                    }
                }
            }
        }

        if(m==x&&n==y){
            printf("%d\n",time);
        }
        else{
            printf("-1\n");
        }
   }
   return   0;
}
