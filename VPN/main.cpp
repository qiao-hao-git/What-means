#include <iostream>
#include <string.h>
using namespace std;
char a[260];
char b[260];
char c[260];
int find_1(char *a){
    int i;
    int n=strlen(a);
    for(i=0;i<n;i++){
        if(a[i]=='/'&&(a[i+1]!='/'&&a[i-1]!='/')){
            return  i;
        }
    }
    return  0;
}
int judge(char *b){
    int i;
    int n=strlen(b);
    for(i=0;i<n;i++){
        if(b[i]==':'){
            return 1;
        }
    }
    return 0;
}
int main()
{
    int T;
    int i;
    int j;
    scanf("%d",&T);
    while(T--){
        scanf("%s",a);
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int n=strlen(a);
        if(find_1(a)){
            for(i=find_1(a),j=0;i<n;i++,j++){
                c[j]=a[i];
            }
            if(a[4]=='s'){
                for(i=8,j=0;i<find_1(a);i++,j++){
                    b[j]=a[i];
                }
                if(judge(b)){
                    b[j]='-';
                    b[j+1]='p';
                    j+=2;
                }
                b[j]='-';
                b[j+1]='s';
            }
            else{
                for(i=7,j=0;i<find_1(a);i++,j++){
                    b[j]=a[i];
                }
                if(judge(b)){
                    b[j]='-';
                    b[j+1]='p';
                }
            }
            int n1=strlen(b);
            for(i=0;i<n1;i++){
                if(b[i]=='.'||b[i]==':'){
                    b[i]='-';
                }
            }
            printf("http://%s.vpn.uestc.edu.cn:8118%s\n",b,c);
        }
        else{
            if(a[4]=='s'){
                for(i=8,j=0;i<n;i++,j++){
                    b[j]=a[i];
                }
                if(judge(b)){
                    b[j]='-';
                    b[j+1]='p';
                    j+=2;
                }
                b[j]='-';
                b[j+1]='s';
            }
            else{
                for(i=7,j=0;i<n;i++,j++){
                    b[j]=a[i];
                }
                if(judge(b)){
                    b[j]='-';
                    b[j+1]='p';
                }
            }
            int n1=strlen(b);
            for(i=0;i<n1;i++){
                if(b[i]=='.'||b[i]==':'){
                    b[i]='-';
                }
            }
            printf("http://%s.vpn.uestc.edu.cn:8118\n",b);
        }
    }
    return 0;
}
