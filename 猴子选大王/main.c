#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[202];

int main()
{
    int T,m,n;
    scanf("%d",&T);
    if(T>=1&&T<=100){
        while(T--){
            scanf("%d%d",&m,&n);
            memset(a,0,sizeof(a));
            int out=0,num=0,i=1;
            while(out!=m-1){
                if(a[i]==0){
                    num++;
                }
                if(num==n){
                    num=0;
                    a[i]=1;
                    out++;
                }
                i++;
                if(i==m+1){
                    i=1;
                }

            }
            for(int j=1;j<=m;j++){
                if(a[j]==0){
                    printf("%d\n",j);
                    break;
                }
            }
        }
    }
    return 0;
}
