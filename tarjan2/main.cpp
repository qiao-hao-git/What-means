#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define maxn 1010
#define maxm 50010
int n,m,num,bcc_cnt,bcc_num,cut_dian,cut_bian,cnt;
int DFN[maxn],low[maxn];
bool isC[maxn];
vector <int> G[maxn];
stack <int> S;
vector<int> D[maxn];
int mp[maxn][maxn];
void Tarjan(int x,int fa){
	num++;
	DFN[x]=low[x]=num;
	int kid=0;
	S.push(x);
	for(int i=0;i<G[x].size();++i){
		int s=G[x][i];
		if(s==fa){
            continue;
		}
		if(!DFN[s]){
			//kid++;
			Tarjan(s,x);
			if(low[s]>=DFN[x]){
				isC[x]=1 ;
				bcc_cnt++;
				//D[bcc_cnt].push_back(x);
				while(s!=S.top()){
					int cur=S.top();
					S.pop();
					D[bcc_cnt].push_back(cur);
				}
				S.pop();
				D[bcc_cnt].push_back(s);
				D[bcc_cnt].push_back(x);
			}
			if(low[s]>DFN[x]){
                cut_bian++;
			}
			if(x==fa){
                kid++;
			}
			low[x]=min(low[s],low[x]);
		}
		else if(DFN[x]>DFN[s]&&s!=fa){
			low[x]=min(DFN[s],low[x]);
		}
	}
	if(fa==x&&kid==1){
        isC[x]=0 ;
	}
	if(fa==x&&kid>=2){
        isC[x]=1;
		//bcc_cnt++;
		//D[bcc_cnt].push_back(x) ;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	memset(DFN,0,sizeof(DFN));
	memset(low,0,sizeof(low));
	memset(mp,0,sizeof(mp));
    for(int i=1;i<=m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        mp[a][b]=mp[b][a]=1;
    }
    cut_dian=0;
    cut_bian=0;
	for(int i=1;i<=n;++i){
		if(!DFN[i])
			Tarjan(i,i) ;
	}
	for(int i=1;i<=n;++i){
        if(isC[i]){
            cut_dian++;
        }
	}
	cnt=0;
	bcc_num=0;
	for(int i=1;i<=bcc_cnt;++i){
		for(int j=1;j<D[i].size();++j){
			for(int k=0;k<j;++k){
                if(mp[D[i][k]][D[i][j]]){
                    cnt++;
                }
			}
		}
		if(cnt>bcc_num){
            bcc_num=cnt;
		}
		cnt=0;
	}
	printf("%d %d %d %d",cut_dian,cut_bian,bcc_cnt,bcc_num);
	return 0;
}

