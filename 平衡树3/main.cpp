#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=2e5+3;
int ch[MAXN][2],val[MAXN],cnt[MAXN],siz[MAXN],fa[MAXN];
int root,ncnt;
int chk(int x){
    return ch[fa[x]][1]==x;
}
void pushup(int x){
    siz[x] = siz[ch[x][0]]+siz[ch[x][1]]+cnt[x];
}
void rorate(int x){
    int f=fa[x],ff=fa[f],w=chk(x);
    ch[f][w]=ch[x][w^1];
    fa[ch[x][w^1]]=f;
    ch[ff][chk(f)]=x;
    fa[x] = ff;
    ch[x][w^1]=f;
    fa[f]=x;
    pushup(f);
    pushup(x);
}
void splay(int x,int goal){
    while( fa[x]!=goal ){
        int f=fa[x],ff=fa[f];
        if(ff!=goal){
            if(chk(x)==chk(f)){
                rorate(f);
            }
            else{
                rorate(x);
            }
        }
        rorate(x);
    }
    if(!goal){
        root=x;
    }
}
void find_(int x){
    if(!root){
        return ;
    }
    int cur=root;
    while(ch[cur][val[cur]<x]&&val[cur]!=x){
        cur=ch[cur][val[cur]<x];
    }
    splay(cur,0);
}
void insert_(int x){
    int cur=root,p=0;
    while(cur&&val[cur]!=x){
        p=cur;
        cur=ch[cur][val[cur]<x];
    }
    if(cur){
        cnt[cur]++;
    }
    else{
        cur=++ncnt;
        if(p) {
            ch[p][x>val[p]]=cur;
        }
        ch[cur][0]=ch[cur][1]=0;
        val[cur]=x;
        cnt[cur]=1;
        siz[cur]=1;
        fa[cur]=p;
    }
    splay(cur,0);
}
int find_x(int k){
    int cur=root;
    while(1){
        if(siz[ch[cur][0]]>=k&&ch[cur][0]){
            cur=ch[cur][0];
        }
        else if(siz[ch[cur][0]]+cnt[cur]<k){
            k-=siz[ch[cur][0]]+cnt[cur];
            cur=ch[cur][1];
        }
        else{
            return cur;
        }
    }
}
int pre(int x){
    find_(x);
    if(val[root]<x){
        return root;
    }
    int cur=ch[root][0];
    while(ch[cur][1]){
        cur=ch[cur][1];
    }
    return cur;
}
int next(int x){
    find_(x);
    if(val[root]>x){
        return root;
    }
    int cur=ch[root][1];
    while(ch[cur][0]){
        cur=ch[cur][0];
    }
    return cur;
}
void delete_(int x){
    int pree=pre(x),nnext=next(x);
    splay(pree,0);
    splay(nnext,pree);
    int cur=ch[nnext][0];
    if(cnt[cur]>1){
        cnt[cur]--;
        splay(cur,0);
    }
    else{
        ch[nnext][0] = 0;
    }
}
int n;
int main()
{
    scanf("%d",&n);
    insert_(0x3f3f3f3f);
    insert_(0xcfcfcfcf);
    while(n--){
        int opt,x;
        scanf("%d%d",&opt,&x);
        if(opt==1){
            insert_(x);
        }
        else if(opt==2){
            delete_(x);
        }
        else if(opt==3){
            find_(x);
            printf("%d\n",siz[ch[root][0]]);
        }
        else if(opt==4){
            printf("%d\n",val[find_x(x+1)]);
        }
        else if(opt==5){
            printf("%d\n",val[pre(x)]);
        }
        else if(opt==6){
            printf("d\n",val[next(x)]);
        }
    }
    return 0;
}
