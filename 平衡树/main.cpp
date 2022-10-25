#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
typedef long long LL;
using namespace std;
const int maxn=1000010,INF=1e9;
int n;
int ch[maxn][2];
int val[maxn],dat[maxn];
int ssize[maxn],cnt[maxn];
int tot,root;
int New(int v){
	val[++tot]=v;
	dat[tot]=rand();
	ssize[tot]=1;
	cnt[tot]=1;
	return tot;
}
void pushup(int now){
	ssize[now]=ssize[ch[now][0]]+ssize[ch[now][1]]+cnt[now];
}
void build(){
	root=New(-INF);
	ch[root][1]=New(INF);
	pushup(root);
}
void Rotate(int &now,int d){
	int temp=ch[now][d ^ 1];
	ch[now][d ^ 1]=ch[temp][d];
	ch[temp][d]=now;
	now=temp;
	pushup(ch[now][d]);
	pushup(now);
}
void insert(int &now,int x){
	if(!now){
		now=New(x);
		return ;
	}
	if(x==val[now]){
        cnt[now]++;
	}
	else{
		int d=x<val[now]?0:1;
		insert(ch[now][d],x);
		if(dat[now]<dat[ch[now][d]]){
            Rotate(now,d ^ 1);
		}
	}
	pushup(now);
}
void Remove(int &now,int x){
	if(!now){
        return ;
	}
	if(x==val[now]){
		if(cnt[now]>1){
            cnt[now]--,
            pushup(now);
            return ;
        }
		if(ch[now][0]||ch[now][1]){
			if(!ch[now][1]||dat[ch[now][0]]>dat[ch[now][1]]){
				Rotate(now,1);
				Remove(ch[now][1],x);
			}
			else{
                Rotate(now,0);
                Remove(ch[now][0],x);
			}
			pushup(now);
		}
		else{
            now=0;
		}
		return ;
	}
	if(x<val[now]){
	    Remove(ch[now][0],x);
    }
    else{
        Remove(ch[now][1],x);
    }
	pushup(now);
}
int get_rank(int now,int x){
	if(!now){
        return 0;
	}
	if(x==val[now]){
        return ssize[ch[now][0]]+1;
	}
	else if(x<val[now]){
        return get_rank(ch[now][0],x);
	}
	else{
        return  ssize[ch[now][0]]+cnt[now]+get_rank(ch[now][1],x);
	}
}
int get_val(int now,int x){
	if(!now){
        return INF;
	}
	if(x<=ssize[ch[now][0]]){
        return get_val(ch[now][0],x);
	}
    else if(x<=ssize[ch[now][0]]+cnt[now]){
        return val[now];
    }
	else {
        return  get_val(ch[now][1],x-ssize[ch[now][0]]-cnt[now]);
	}
}
int get_pre(int x){
	int now=root,pre;
	while(now){
		if(val[now]<x){
            pre=val[now];
            now=ch[now][1];
		}
		else {
            now=ch[now][0];
		}
	}
	return pre;
}
int get_next(int x){
	int now=root,next;
	while(now){
		if(val[now]>x){
            next=val[now];
            now=ch[now][0];
		}
		else {
            now=ch[now][1];
		}
	}
	return next;
}
int main(){
	build();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int opt,x;
		scanf("%d%d",&opt,&x);
		if(opt==1){
            insert(root,x);
		}
		else if(opt==2){
            Remove(root,x);
		}
		else if(opt== 3){
            printf("%d\n",get_rank(root,x)-1);
		}
		else if(opt==4){
            printf("%d\n",get_val(root,x+1));
		}
		else if(opt==5){
            printf("%d\n",get_pre(x));
		}
		else if(opt==6){
            printf("%d\n",get_next(x));
		}
	}
	return 0;
}
