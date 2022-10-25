#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    a[101];
char    b[21];


int main()
{
    int T,N,M,i,flag,flag2;
    scanf("%d",&T);
    while(T--){
        memset(b,0,sizeof(b));
        M=0;
        scanf("%d",&N);
        getchar();
        fgets(b,20,stdin);
        for(i=0;i<N;i++){
            memset(a,0,sizeof(a));
            fgets(a,100,stdin);
            if(strlen(a)<strlen(b)){
                flag2=0;
                continue;
            }
            flag=0;
            int i,j;
            for(i=0;i<=strlen(a)-strlen(b);i++){
                flag2=1;
                for(j=0;j<strlen(b);j++){
                    if(i==0){
                        if(a[i+j]!=b[j]){
                            break;
                        }
                    }
                    else    if(i+j==strlen(a)-1){
                        if(a[i-1]==' '){
                            break;
                        }
                    }
                    else    if(a[i+j]!=b[j]||a[i-1]!=' '){
                        break;
                    }
                }
                if(i+j==strlen(a)-1){
                    if(j==strlen(b)-1){
                        flag=1;
                    }
                }
                else    if((j==strlen(b)-1)&&(a[i+j]==' ')){
                    flag=1;
                }
            }
            if(flag){
                M++;
            }
        }
        if(flag2==0){
            printf("Do not find\n");
        }
        else    if(M==0){
            printf("Do not find\n");
        }
        else{
            printf("%d\n",M);
        }
        printf("\n");
    }
    return 0;
}
