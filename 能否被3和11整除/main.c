#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char    a[210];

int main()
{
    int T;
    scanf("%d",&T);
    if(T>=1&&T<=200){
        while(T--){
            memset(a,0,sizeof(a));
            scanf("%s",a);
            int n=strlen(a);
            if(a[0]-'0'==0){
                printf("\nYes Yes");
            }
            else{
                int sum=0,sum1=0,sum2=0,t1,t2;
                for(int i=0;i<n;i++){
                    sum+=(a[i]-'0');
                }
                if(sum%3==0){
                    t1=1;
                }
                else{
                    t1=0;
                }
                int count=0;
                for(int i=n-1;i>=0;i--){
                    count++;
                    if(count%2==0){
                        sum2+=(a[i]-'0');
                    }
                    else{
                        sum1+=(a[i]-'0');
                    }
                }
                if((sum1-sum2)%11==0){
                    t2=1;
                }
                else{
                    t2=0;
                }
                if(t1==1&&t2==1){
                    printf("\nYes Yes");
                }
                else    if(t1==1&&t2==0){
                    printf("\nYes No");
                }
                else    if(t1==0&&t2==1){
                    printf("\nNo Yes");
                }
                else{
                    printf("\nNo No");
                }
            }
        }
    }
    return 0;
}
