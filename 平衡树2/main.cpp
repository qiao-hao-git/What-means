#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000010,INF=1e9;
int n;
struct tree{
    int same,c,son[2],f,v;
}s[maxn];
int root;
int tot;
void update(int x){
    s[x].c=s[s[x].son[0]].c+s[s[x].son[1]].c+s[x].same;
    return ;
}
int add(int v){
    tot++;
    s[tot].v=v;
    s[tot].f=rand();
    s[tot].c=s[tot].same=1;
    return tot;
}
void bulid(){
    root=add(-INF);
    s[root].son[1]=add(INF);
    update(root);
}
void rotate(int &now,int w){
    int temp=s[now].son[w^1];
    s[now].son[w^1]=s[temp].son[w];
    s[temp].son[w]=now;
    now=temp;
    update(s[now].son[w]);
    update(now);
}
void insert(int &now,int x){
    if(!now){
        now=add(x);
        return;
    }
    if(x==s[now].v){
        s[now].same++;
    }
    else{
        int d=x<s[now].v?0:1;
        insert(s[now].son[d],x);
        if(s[now].f<s[s[now].son[d]].f){
            rotate(now,d^1);
        }
    }
    update(now);
}

void del(int &now,int x){
    if(!now){
        return;
    }
    if(x==s[now].v){
        if(s[now].same>1){
            s[now].same--;
            update(now);
            return;
        }
        if(s[now].son[0]||s[now].son[1]){
            if(!s[now].son[1]||s[s[now].son[0]].f>s[s[now].son[1]].f){
                rotate(now,1);
                del(s[now].son[1],x);
            }
            else{
                rotate(now,0);
                del(s[now].son[0],x);
            }
            update(now);
        }
        else{
            now=0;
        }
        return;
    }
    if(x<s[now].v){
        del(s[now].son[0],x);
    }
    else{
        del(s[now].son[1],x);
    }
    update(now);
}

int find_rank(int now,int x){
    if(!now){
        return  0;
    }
    if(x==s[now].v){
        return  s[s[now].son[0]].c+1;
    }
    else    if(x<s[now].v){
        return  find_rank(s[now].son[0],x);
    }
    else{
        return  s[s[now].son[0]].c+s[now].same+find_rank(s[now].son[1],x);
    }
}

int find_num(int now,int x){
    if(!now){
        return  INF;
    }
    if(x<=s[s[now].son[0]].c){
        return  find_num(s[now].son[0],x);
    }
    else    if(x<=s[s[now].son[0]].c+s[now].same){
        return  s[now].v;
    }
    else{
        return  find_num(s[now].son[1],x-s[s[now].son[0]].c-s[now].same);
    }
}

int pre(int x){
	int now=root,pre;
	while(now){
		if(s[now].v<x){
            pre=s[now].v;
            now=s[now].son[1];
		}
		else{
            now=s[now].son[0];
		}
    }
    return  pre;
}

int next(int x){
	int now=root,next;
	while(now){
		if(s[now].v>x){
            next=s[now].v;
            now=s[now].son[0];
		}
		else{
            now=s[now].son[1];
		}
    }
    return next;
}
int main(){
    scanf("%d",&n);
    bulid();
    for(int i=1;i<=n;i++){
        int opt,x;
        scanf("%d%d",&opt,&x);
        if(opt==1){
            insert(root,x);
        }
        else if(opt==2){
            del(root,x);
        }
        else if(opt==3){
            printf("%d\n",find_rank(root,x)-1);
        }
        else if(opt==4){
            printf("%d\n",find_num(root,x+1));
        }
        else if(opt==5){
            if(pre(x)!=-INF){
                printf("%d\n",pre(x));
            }
            else{
                printf("NOT FOUND\n");
            }
        }
        else if(opt==6){
            if(next(x)!=INF){
                printf("%d\n",next(x));
            }
            else{
                printf("NOT FOUND\n");
            }
        }
    }
}
