#include <iostream>
#include <string.h>
#include <stack>
#include <vector>
#include <cctype>
#include <algorithm>
#define maxn 1010
#define maxm 50010
int dfn[maxn],tim,low[maxn],st[maxn],top;
int bcc_num,cut_bian,cut_dian,bcc_cnt;
using namespace std;
struct edge{
    int u;
    int v;
    int next;
}e[maxm];
int head[maxn],tot;
int n,m,u,v;
bool iscut[maxn];
vector<int>bcc_point[maxn];
stack<int>s;
void add(int u,int v){
    e[++tot].v=v;
    e[tot].u=u;
    e[tot].next=head[u];
    head[u]=tot;
}
int mp[maxn][maxn];
int cnt;
void tarjan(int u,int fa){
    low[u]=dfn[u]=++tim;
    int child=0;
    s.push(u);
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(!dfn[v]){
            child++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(u!=fa&&low[v]>=dfn[u]){
                iscut[u]=true;
                bcc_num++;
                bcc_point[bcc_num].push_back(u);
                while(u!=s.top()){
                    bcc_point[bcc_num].push_back(s.top());
                    s.pop();
                }
            }
            if(child==2&&u==fa){
                iscut[u]=true;
            }
            if(low[v]>dfn[u]){
                cut_bian++;
            }
        }
        else if(v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
        if(fa==0&&child==1){
            iscut[u]=0;
        }
        if(fa==0&&child==0){
            bcc_num++;
            bcc_point[bcc_num].push_back(u);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(head,0,sizeof(head));
    for(int i=1;i<=m;++i){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
        mp[u][v]=mp[v][u]=1;
    }
    tim=0;
    top=0;
    cut_dian=0;
    cut_bian=0;
    bcc_cnt=0;
    cnt=0;
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            tarjan(i,0);
        }
    }
    for(int i=1;i<=bcc_num;++i){
        for(int j=1;j<bcc_point[i].size();++j){
            for(int k=0;k<j;++k){
                if(mp[bcc_point[i][k]][bcc_point[i][j]]){
                    cnt++;
                }
            }
        }
        if(cnt>bcc_num){
            bcc_num=cnt;
        }
        cnt=0;
    }
    for(int i=1;i<=n;++i){
        if(iscut[i]){
            cut_dian++;
        }
    }
    printf("%d %d %d %d\n",cut_dian,cut_bian,bcc_num,bcc_cnt);
    return 0;
}
