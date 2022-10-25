#include <iostream>
#include <string.h>
#include<vector>
#define maxn 200005
using namespace std;
int n,m,l,r,t,k,cnt;
char c;
char a[maxn];
int g[5][maxn];
int x,y;
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    getchar();
    scanf("%s",a);
    getchar();
    memset(g,0,n+2);
    while(m--){
        scanf("%d",&k);
        if(k==1){
            scanf("%d%d",&l,&r);
            getchar();
            scanf("%c",&c);
            if(c=='E'){
                g[1][l-1]++;
                g[1][r-1]++;
            }
            else    if(c=='S'){
                g[2][l-1]++;
                g[2][r-1]++;
            }
            else    if(c=='N'){
                g[3][l-1]++;
                g[3][r-1]++;
            }
            else    if(c=='W'){
                g[4][l-1]++;
                g[4][r-1]++;
            }
        }
        else    if(k==2){
            x=0;
            y=0;
            cnt=0;
            scanf("%d%d%d",&l,&r,&t);
            if(t>=r-l+1){
                for(i=l-1;i<=r-1;i++){

                }
                int d=t/(r-l+1),e=t%(r-l+1);
                x*=d;
                y*=d;
                for(i=l-1;i<=e-1;i++){
                    switch(a[i]){
                        case    'E':
                            x+=b[i]+1;
                            break;
                        case    'S':
                            y-=b[i]+1;
                            break;
                        case    'N':
                            y+=b[i]+1;
                            break;
                        case    'W':
                            x-=b[i]+1;
                            break;
                    }
                }
                printf("%d %d\n",x,y);
            }
            else{
                for(i=l-1;i<=t-1;i++){
                    switch(a[i]){
                        case    'E':
                            x+=b[i]+1;
                            break;
                        case    'S':
                            y-=b[i]+1;
                            break;
                        case    'N':
                            y+=b[i]+1;
                            break;
                        case    'W':
                            x-=b[i]+1;
                            break;

                    }
                }
                printf("%d %d\n",x,y);
            }
        }
    }
    return 0;
}
