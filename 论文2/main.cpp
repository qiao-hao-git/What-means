#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;


int main()
{
     string a;
    string b;
    int T,N,M,i,flag,flag2;
    scanf("%d",&T);
    while(T--){

        M=0;
        scanf("%d",&N);
        getchar();
       getline(cin,b);
        for(i=0;i<N;i++){

            getline(cin,a);
            if(a.length()<b.length()){
                flag2=0;
                continue;
            }
            flag=0;
            int i,j;
            for(i=0;i<=a.length()-b.length();i++){
                flag2=1;
                for(j=0;j<b.length();j++){
                    if(i==0){
                        if(a[i+j]!=b[j]){
                            break;
                        }
                    }
                    else    if(i+j==a.length()){
                        if(a[i-1]==' '){
                            break;
                        }
                    }
                    else    if(a[i+j]!=b[j]||a[i-1]!=' '){
                        break;
                    }
                }
                if(i+j==a.length()){
                    if(j==b.length()){
                        flag=1;
                    }
                }
                else    if((j==b.length())&&(a[i+j]==' ')){
                    flag=1;
                }
            }
            if(flag){
                M++;
            }
        }
        if(flag2==0){
            printf("Do not find\n");
        }
        else    if(M==0){
            printf("Do not find\n");
        }
        else{
            printf("%d\n",M);
        }
        printf("\n");
    }
    return 0;
}
