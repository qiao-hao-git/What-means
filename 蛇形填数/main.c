#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define maxn    100
int a[maxn][maxn];

int main()
{
    int T,n;
    scanf("%d",&T);
    if(T>=1&&T<=20){
        while(T--){
            scanf("%d",&n);
            memset(a,0,sizeof(a));
            int count=1,x=0,y=n-1;
            a[x][y]=count;
            while(count<n*n){
                while(x+1<n&&!a[x+1][y]){
                    a[++x][y]=++count;
                }
                while(y-1>=0&&!a[x][y-1]){
                    a[x][--y]=++count;
                }
                while(x-1>=0&&!a[x-1][y]){
                    a[--x][y]=++count;
                }
                while(y+1<n&&!a[x][y+1]){
                    a[x][++y]=++count;
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    printf("%4d",a[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
