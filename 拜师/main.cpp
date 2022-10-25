#include <iostream>
#include <cstring>
using namespace std;
//#define getchar() (frS==frT&&(frT=(frS=frBB)+fread(frBB,1,1<<15,stdin),frS==frT)?EOF:*frS++)
//char frBB[1<<15],*frS=frBB,*frT=frBB;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
}
int mod=1e9+7;
int head[2097160];
int change[2097160];
int cnt=0;
int n,m;
int find(int x)
{
	if(x==head[x])
		return x;
	else
	{
		return head[x]=find(head[x]);
	}
}
void unon(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		head[fx]=fy;
}
int main()
{
	int op,a,b;
	read(n);
	read(m);
	memset(change,0,sizeof(change));
	for(int i=1;i<=n;++i)
		head[i]=i;
	for(int i=1;i<=m;++i)
	{
		read(op);
		read(a);
		read(b);
		if(op==1)
			unon(a,b);
		else if(op==2)
		{
			int fa=find(a);
			int fb=find(b);
			if(fa==fb)
			{
				change[++cnt]=1;
			}
			else
			{
				change[++cnt]=0;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=cnt;i++){
        sum+=((change[i]<<1)<<(i-1))%mod;
    }
    printf("%d\n",sum);
	return 0;
}
