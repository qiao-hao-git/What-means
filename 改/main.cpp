#include <iostream>
#include <string.h>
#include<vector>
#define maxn 200005
using namespace std;
int n,m,l,r,t,k,cnt;
char c;
char a[maxn];
int b[maxn];
int x,y;
vector<vector<int> >p;
int main()
{
    int i;
    p.resize(5);
    scanf("%d%d",&n,&m);
    getchar();
    scanf("%s",a);
    getchar();
    for(i=0;i<n;i++){
        if(a[i]=='N'){
            p[1].push_back(i);
        }
        else if(a[i]=='S'){
            p[2].push_back(i);
        }
        else if(a[i]=='W'){
            p[3].push_back(i);
        }
        else{
            p[4].push_back(i);
        }
    }
    memset(b,0,n+2);
    while(m--){
        scanf("%d",&k);
        if(k==1){
            scanf("%d%d",&l,&r);
            getchar();
            scanf("%c",&c);
            if(c=='N'){
                for(i=0;i<p[1].size();i++){
                    if(p[1][i]>=l&&p[1][i]<=r){
                        b[p[1][i]]++;
                    }
                }
            }
            else    if(c=='S'){
                for(i=0;i<p[2].size();i++){
                    if(p[2][i]>=l&&p[1][i]<=r){
                        b[p[2][i]]++;
                    }
                }
            }
            else    if(c=='W'){
                for(i=0;i<p[3].size();i++){
                    if(p[3][i]>=l&&p[1][i]<=r){
                        b[p[3][i]]++;
                    }
                }
            }
            else    if(c=='E'){
                for(i=0;i<p[4].size();i++){
                    if(p[4][i]>=l&&p[1][i]<=r){
                        b[p[4][i]]++;
                    }
                }
            }
        }
        else    if(k==2){
            x=0;
            y=0;
            cnt=0;
            scanf("%d%d%d",&l,&r,&t);
            if(t>=r-l+1){
                for(i=l-1;i<=r-1,t;i++){
                    if(a[i]=='E'){
                        x+=b[i]+1;
                    }
                    else    if(a[i]=='S'){
                        y-=b[i]+1;
                    }
                    else    if(a[i]=='W'){
                        x-=b[i]+1;
                    }
                    else    if(a[i]=='N'){
                        y+=b[i]+1;
                    }
                }
                int d=t/(r-l+1),e=t%(r-l+1);
                x*=d;
                y*=d;
                for(i=l-1;i<=e-1;i++){
                    if(a[i]=='E'){
                        x+=b[i]+1;
                    }
                    else    if(a[i]=='S'){
                        y-=b[i]+1;
                    }
                    else    if(a[i]=='W'){
                        x-=b[i]+1;
                    }
                    else    if(a[i]=='N'){
                        y+=b[i]+1;
                    }
                }
                printf("%d %d\n",x,y);
            }
            else{
                for(i=l-1;i<=t-1;i++){
                    if(a[i]=='E'){
                        x+=b[i]+1;
                    }
                    else    if(a[i]=='S'){
                        y-=b[i]+1;
                    }
                    else    if(a[i]=='W'){
                        x-=b[i]+1;
                    }
                    else    if(a[i]=='N'){
                        y+=b[i]+1;
                    }
                }
                printf("%d %d\n",x,y);
            }
        }
    }
    return 0;
}
