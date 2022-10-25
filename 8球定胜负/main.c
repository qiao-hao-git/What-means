#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,len,count,i,flag;
    while(scanf("%d",&n)!=EOF&&n!=0){
        getchar();
        char    a[8];
        scanf("%s",a);
        len=strlen(a)-1;
        count=0;
        if(a[len]=='B'){
            for(i=0;i<len;i++){
                if(a[i]=='R'){
                    count++;
                }
            }
            if(count==7){
                flag=1;
            }
            else{
                flag=0;
            }
        }
        else{
            for(i=0;i<len;i++){
                if(a[i]=='Y'){
                    count++;
                }
            }
            if(count==7){
                flag=0;
            }
            else{
                flag=1;
            }
        }
        if(flag==1){
            printf("Red\n");
        }
        else{
            printf("Yellow\n");
        }
    }
    return 0;
}
