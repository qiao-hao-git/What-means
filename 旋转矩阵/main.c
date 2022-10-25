#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char    a[101][101];
char    b[101][101];
int main()
{
    int  T,n;
    scanf("%d",&T);
    if(T>0&&T<=100){
        while(T--){
            scanf("%d",&n);
            memset(a,0,sizeof(a));
            memset(b,0,siezof(b));
            for(int i=0;i<n;i++){
                getchar();
                for(int j=0;j<n;j++){

                    scanf("%c",&a[i][j]);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    b[j][n-i-1]=a[i][j];
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    printf("%c",b[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
