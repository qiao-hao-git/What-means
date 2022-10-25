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
    int i,j,flag1=0,flag2=0;
    for(i=0;i<l;i++){
        for(j=0;j<l;j++){
            if(b[i]!=b[j]){
                flag1++;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<l;j++){
            if(b[j]==func(a[i])){
                flag2++;
            }
        }
    if(flag1==(flag2*(flag2-1))){
        return  1;
    }
    else{
        return  0;
    }
}

int main()
{
    if(judge(f,m,5,5)){
        printf("func is a surjection.\n");
    }
    else{
        printf("func is not a surjection.\n");
    }
    return 0;
}
