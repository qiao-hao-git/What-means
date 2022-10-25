#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,a,b,c,d;
    char s;
    scanf("%d",&T);
    if(T>=1&&T<=200){
        while(T--){
            scanf("%d %d %d %d %c",&a,&b,&c,&d,&s);

            if(a>0&&b>0&&c>0&&d>0){
                int x,y;
                if(s == '+'){
                    x=a*d+c*b;
                    y=b*d;
                }

                else    if(s == '-'){
                    x=a*d-c*b;
                    y=b*d;
                }

                else    if(s == '*'){
                    x=a*c;
                    y=b*d;
                }

                else    if(s == '/'){
                    x=a*d;
                    y=b*c;
                }
                int f;
                if(x>0){
                    f=1;
                }
                else{
                    f=0;
                    x=-x;
                }
                int res,m=x,n=y;
                while(n>0){
                    res=m%n;
                    m=n;
                    n=res;
                }
                x=x/m;
                y=y/m;
                if(x%y==0){
                    printf("%d/%d%c%d/%d=%d\n",a,b,s,c,d,x/y);

                }
                else{
                    if(f==1){
                        printf("%d/%d%c%d/%d=%d/%d\n",a,b,s,c,d,x,y);
                    }
                    else{
                        printf("%d/%d%c%d/%d=%d/%d\n",a,b,s,c,d,-x,y);
                    }
                }

            }

        }
    }
    return 0;
}
