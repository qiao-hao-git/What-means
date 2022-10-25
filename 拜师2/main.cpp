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
const long long maxn=2097160;
const int maxm=3e6+5;
long long mod=1e9+7;
int link[maxn];
int answer[maxm];
int cnt=0;
int n,m,op,a,b;
int findlink(int x)
{
	if(x==link[x]){
        return x;
	}
	else
	{
		return link[x]=findlink(link[x]);
	}
}
void unionlink(int x,int y)
{
	int fx=findlink(x);
	int fy=findlink(y);
	if(fx!=fy){
        link[fx]=fy;
	}
}
int main()
{
	read(n);
	read(m);
	//memset(link,0,sizeof(link));
	for(int i=1;i<=n;++i){
        link[i]=i;
	}
	for(int i=1;i<=m;++i)
	{
		read(op);
		read(a);
		read(b);
		if(op==1){
            unionlink(a,b);
		}
		else if(op==2)
		{
			if(findlink(a)==findlink(b))
			{
				answer[++cnt]=1;
			}
			else
			{
				answer[++cnt]=0;
			}
		}
	}
    long long ans=0;
    int t=1;
	for(int i=cnt;i>=1;i--){
        ans+=((answer[i]*t)%mod+mod)%mod;
        t*=2;
	}
	printf("%lld",ans%mod);
	return 0;
}
