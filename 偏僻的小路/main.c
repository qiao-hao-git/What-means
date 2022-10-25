#include <stdio.h>
#include <stdlib.h>
char    dir[2],sex[2];
int main()
{
    int n,l,v,i,pos;
    double  time,len,c_len;
    while(scanf("%d%d%d",&n,&l,&v)==3){
        if(n==0&&l==0&&v==0){
            break;
        }
        time=0.0;
        c_len=0.0;
        for(i=0;i<n;i++){
            scanf("%d %s %s",&pos, sex, dir);
            if(dir[0]=='W'){
                len=pos;
            }
            else{
                len=l-pos;
            }
            if(len/v>time){
                time=len/v;
            }
            c_len+=len;
        }
        printf("%.2lf %.2lf\n",time,c_len);
    }
    return 0;
}
