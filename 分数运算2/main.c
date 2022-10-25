#include<stdio.h>
#include<math.h>
int main(){
     int    T,a,b,c,d,f,x,y;
     char e;
     scanf("%d",&T);
     if(T>=1&&T<=100){
        while(T--){
            scanf("%d %d %d %d %c",&a,&b,&c,&d,&e);
            if(a>0&&b>0&&c>0&&d>0){
                if(e=='+'){
                    x=a*d+b*c;
                    y=b*d;
                }
                else    if(e=='-'){
                    x=a*d-b*c;
                    y=b*d;
                }
                else    if(e=='*'){
                    x=a*c;
                    y=b*d;
                }
                else    if(e=='/'){
                    x=a*d;
                    y=b*c;
                }
                if(x%y==0){
                    printf("%d/%d%c%d/%d=%d\n",a,b,e,c,d,x/y);
                }
                else{
                     if(x>=0){
                        f=1;
                    }
                    else{
                        f=0;
                        x=-x;
                    }
                    int res,m=x,n=y;
                    while(n>0){
                        res=m/n;
                        m=n;
                        n=res;
                    }
                    x=x/n;
                    y=y/n;
                    if(f==1){
                        printf("%d/%d%c%d/%d=%d/%d\n",a,b,e,c,d,x,y);
                    }
                    else{
                        printf("%d/%d%c%d/%d=%d/%d\n",a,b,e,c,d,-x,y);
                    }
                }

            }
        }
     }

}
