#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    a[101];
char    b[20];
char    c[20];
int judge(char*a){
    int n=strlen(a);
    int pos=n-1;
    while(a[pos]!=' '){
        pos--;
    }
    a[pos]='\0';
    int npos=pos-1;
    while(a[npos]!=' '){
        npos--;
    }
    if(strcmp(a+npos+1,"no")==0){
        return  0;
    }
    else{
        return 1;
    }
}

int main()
{
    int n,k,t,score1,score2,i;
    while(scanf("%d",&n)!=EOF&&n!=0){
        score1=0;
        score2=0;
        k=1;
        t=n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        while(n--){
            getchar();
            fgets(a,100,stdin);
            if(judge(a)){
                b[k]='O';
            }
            else{
                b[k]='X';
            }
            k++;
        }
        if(t%2==0){
            for(i=1;i<=t;i++){
                if(i%2==1&&b[i]=='O'){
                    score1++;
                }
                if(i%2==0&&b[i]=='O'){
                    score2++;
                }
            }
            for(i=2;i<=t;i+=2){
                printf("%d ",i/2);
            }
            printf("Score\n");
            for(i=1;i<=t;i+=2){
                printf("%c ",b[i]);
            }
            printf("%d\n",score1);
            for(i=2;i<=t;i+=2){
                printf("%c ",b[i]);
            }
            printf("%d",score2);
        }
        else{
            b[t+1]='-';
            for(i=1;i<=t;i++){
                if(i%2==1&&b[i]=='O'){
                    score1++;
                }
                if(i%2==0&&b[i]=='O'){
                    score2++;
                }
            }
            for(i=2;i<=t+1;i+=2){
                printf("%d ",i/2);
            }
            printf("Score\n");
            for(i=1;i<=t+1;i+=2){
                printf("%c ",b[i]);
            }
            printf("%d\n",score1);
            for(i=2;i<=t+1;i+=2){
                printf("%c ",b[i]);
            }
            printf("%d\n",score2);
        }
    }
    return 0;
}
