#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn    100001
char    a[maxn];

int main()
{
    int n,m1=0,m2=0,m3=0,m4=0;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    getchar();
    scanf("%s",a);
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(a[i]=='1'){
                m1++;
            }
            else{
                m3++;
            }
        }
        else{
            if(a[i]=='0'){
                m2++;
            }
            else{
                m4++;
            }
        }
    }
    int sum1,sum2;
    if(m1>m2){
        sum1=m1;
    }
    else{
        sum1=m2;
    }
    if(m3>m4){
        sum2=m3;
    }
    else{
        sum2=m4;
    }
    if(sum2>sum1){
        printf("%d\n",sum1);
    }
    else{
        printf("%d\n",sum2);
    }
    return 0;
}
