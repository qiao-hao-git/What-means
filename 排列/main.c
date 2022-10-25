#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define maxn    101

int main()
{
    int T;
    char    a[maxn],b[maxn];
    int c[maxn],d[maxn];
    scanf("%d",&T);
    if(T>=1&&T<=200){
        while(T--){
            scanf("%s%s",a,b);
            memset(c,0,sizeof(c));
            memset(d,0,sizeof(d));
            for(int i=0;i<strlen(a);i++){
                c[a[i]-'0']++;
            }
            for(int i=0;i<strlen(b);i++){
                d[b[i]-'0']++;
            }
            int judge=1;
            for(int i=1;i<10;i++){
                if(c[i]!=d[i]){
                    judge=0;
                    break;
                }
            }
            if(judge==1){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return  0;
}

