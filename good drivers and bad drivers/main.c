#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn    100001
char    a[maxn];

int main()
{
    int n,m1=0,m2=0;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    fgets(a,n,stdin);
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(a[i]!='1'){
                m1++;
            }
        }
        else{
            if(a[i]!='0'){
                m1++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(a[i]!='0'){
                m2++;
            }
        }
        else{
            if(a[i]!='1'){
                m2++;
            }
        }
    }
    if(m2>m1){
        printf("%d\n",m1);
    }
    else{
        printf("%d\n",m2);
    }
    return 0;
}
