#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char    a[1001];
    scanf("%s",a);
    char    t;
    for(int i=0;i<strlen(a)-1;i++){
        for(int j=0;j<strlen(a)-i-1;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("%s\n",a);
    return 0;
}
