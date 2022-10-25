#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    a[101];
char    b[21];

int find(char* str1,char* str2){
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len2>len1){
        return  0;
    }
    if(strstr(str1,str2)!=NULL){
        int len3=strlen(strstr(str1,str2));
        if(len1==len3){
            if(str1[len2]=='\0'||str1[len2]==' '){
                return 1;
            }
            else{
                return  0;
            }
        }
        else{
            if(str1[len1-len3-1]==' '&&(str1[len1-len3+len2+1]=='\0'||str1[len1-len3+len2+1]==' ')){
                return  1;
            }
            else{
                return  0;
            }
        }
    }
    else{
        return  0;
    }
}

int main()
{
    int T,N,M,i;
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
            if(find(a,b)){
                M++;
            }
        }
        if(M){
            printf("%d\n\n",M);
        }
        else{
            printf("Do not find\n\n");
        }
    }
    return 0;
}
