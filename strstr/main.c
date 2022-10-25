#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int find(char* str1,char* str2){
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(strstr(str1,str2)!=NULL){
        int len3=strlen(strstr(str1,str2));
        if(len1==len3){
            if(str1[len1-len3+len2]=='\0'||str1[len1-len3+len2]==' '){
                return  1;
            }
        }
        else{
            if(str1[len1-len3-1]==' '&&(str1[len1-len3+len2]=='\0'||str1[len1-len3+len2]==' ')){
                return  1;
            }
        }
    }
    else{
         return 0;
    }
    return  0;
}

int main()
{
    char* a="abcdsad fiber";
    char* b="fiber";
    if(find(a,b)==1){
        printf("1\n");
    }
    return  0;
}
