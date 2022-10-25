#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct Gnode*   PtrGraph;
typedef struct  Gnode{
    int Nv;
    int Ne;
    int Date[100][100];
}gnode;
int cnt;
vector<int>v;
vector<int>v1;

void    createGraph(PtrGraph G){
    int n,m;
    scanf("%d%d",&n,&m);
    G->Nv=n;
    G->Ne=m;
    for(int i=0;i<G->Nv;i++){
        for(int j=0;j<G->Nv;j++){
            G->Date[i][j]=0;
        }
    }
    for(int i=0;i<G->Ne;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G->Date[a][b]=1;
    }
}
void degree(PteGraph    G){
    for(int j=0;j<G->Nv;j++){
        cnt=0;
        for(int i=0;i<G->Nv;i++){
            if(G->Date[i][j]==1){
                cnt++;
            }
        }
        v.push_back(cnt);
    }
}
void topology(PtrGraph G){
    queue<int>q;
    int count=0;
    for(int i=0;i<G->Nv;i++){
        if(v[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        v1.push_back(temp);
        count++;
        for(int j=0;j<G->Nv;j++){
            if(G->Date[temp][j]==1){
                v[j]--;
                if(v[j]==0){
                    q.push(j);
                }
            }
        }
    }
    if(G->Nv==count){
        for(int i=0;i<v1.size();i++){
            printf("%d\n",v[i]);
        }
    }
    else{
        printf("´ËÍ¼ÓÐ»·");
    }
}
int main()
{
    PtrGraph G=(PtrGraph)malloc(sizeof(struct GNode));
    createGraph(G);
    degree(G);
    topology(G);
    return 0;
}
