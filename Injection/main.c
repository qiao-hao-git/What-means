
#include <stdio.h>
#include <stdlib.h>
int f[5]={1,5,3,2,6};
int m[5]={1,3,5,11,9};

int func(int x){
    int y;
    y=2*x-1;
    return  y;
}

int judge(int a[],int b[],int n,int l){
    int i,j,flag1=0,flag2=1;
    for(i=0;i<n;i++){
        for(j=0;j<l;j++){
            if(b[j]==func(a[i])){
                flag1++;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i]!=a[j]&&func(a[i])==func(a[j])){
                flag2=0;
                break;
            }
        }
    }
    if(flag1==n&&flag2){
        return  1;
    }
    else{
        return  0;
    }
}

int main()
{
    if(judge(f,m,5,5)){
        printf("func is an injection.\n");
    }
    else{
        printf("func is not an injection.\n");
    }
    return 0;
}
