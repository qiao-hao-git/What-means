#include <iostream>
#include <deque>
#include <string.h>
#define maxn 510
#define inf 0x3f
using namespace std;
char g[maxn][maxn];
int p[maxn][maxn];
bool vis[maxn][maxn];
typedef pair<int,int> P;
int n,m;
int bfs(){
    memset(vis,0,sizeof(vis));
    memset(p,inf,sizeof(p));
    p[0][0]=0;
    deque<P> q;
    q.push_back({0,0});
    char s[10]="\\//\\";
    int fx[4]={-1,-1,1,1},fy[4]={-1,1,-1,1};
    int dx[4]={-1,-1,0,0},dy[4]={-1,0,-1,0};
    while(!q.empty()){
        P t=q.front();
        q.pop_front();
        if(vis[t.first][t.second]){
            continue;
        }
        vis[t.first][t.second]=true;
        for(int i=0;i<4;i++){
            int x=t.first+fx[i],y=t.second+fy[i];
            if(x<0||x>n||y<0||y>m){
                continue;
            }
            int cx=t.first+dx[i],cy=t.second+dy[i];
            int d=p[t.first][t.second]+(g[cx][cy]!=s[i]);
            if(p[x][y]>d){
                p[x][y]=d;
                if(g[cx][cy]!=s[i]){
                    q.push_back({x,y});
                }
                else{
                    q.push_front({x,y});
                }
            }
        }
    }
    return  p[n][m];
}
int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=0;i<n;i++){
        scanf("%s",g[i]);
    }
    if((n+m)%2){
        puts("NO SOLUTION");
    }
    else{
        printf("%d\n",bfs());
    }
    return 0;
}
