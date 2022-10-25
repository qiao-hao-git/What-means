#include <stdio.h>
#include <stdlib.h>


int main()
{
    int T,a,b,c,t;
    int s[3]={0};
    scanf("%d",&T);
    if(T>0&&T<=10){
        while(T--){
            scanf("%d %d %d",&a,&b,&c);
            s[0]=a;
            s[1]=b;
            s[2]=c;
            for(int i=0;i<2;i++){
                for(int j=0;j<2-i;j++){
                    if(s[j]>s[j+1]){
                      t=s[j];
                      s[j]=s[j+1];
                      s[j+1]=t;
                    }
                }
            }
            if(a!=b&&a!=c&&b!=c){
                printf("%d\t",s[1]);
            }
            else    if(a==b||a==c||b==c){
                printf("%d\t",s[2]);
            }
            else{
                printf("%d\t",s[1]);
            }
        }
    }
    return 0;
}
