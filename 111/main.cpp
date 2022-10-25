#include <iostream>
using namespace std;
struct nod{
	int num_[5];
	int lazy[5];
	//int size;
	int l,r;
	int a[5];
	nod(){
		for(int i=1;i<=4;++i)
		{
			num_[i]=0;
			lazy[i]=0;
		}

		//size=0;
	}
};
struct xy{
	int x,y;
	xy(){
		x=0;
		y=0;
	}
};
char in[200003];
int num[5][200003]={0};
int n;
nod node[1000000];
//e s w n
void pushup(int s,int l,int r)
{
	node[s].num_[1]+=num[1][r]-num[1][l-1];
	node[s].num_[2]+=num[2][r]-num[2][l-1];
	node[s].num_[3]+=num[3][r]-num[3][l-1];
	node[s].num_[4]+=num[4][r]-num[4][l-1];
	node[s].a[1]=node[s].num_[1];
	node[s].a[2]=node[s].num_[2];
	node[s].a[3]=node[s].num_[3];
	node[s].a[4]=node[s].num_[4];
	//node[s].size+=node[s].num_[1]+node[s].num_[2]+node[s].num_[3]+node[s].num_[4];
}
void build(int s,int l,int r)
{
	node[s].l=l;
	node[s].r=r;
	pushup(s,l,r);
	if(l==r)	return;
	int mid=(l+r)>>1;
	build(2*s,l,mid);
	build(2*s+1,mid+1,r);
}
void pushdown(int s,int o)
{
	node[2*s].lazy[o]+=node[s].lazy[o];
	node[2*s+1].lazy[o]+=node[s].lazy[o];
	node[2*s].num_[o]+=node[2*s].a[o]*node[2*s].lazy[o];
	node[2*s+1].num_[o]+=node[2*s+1].a[o]*node[2*s+1].lazy[o];
	node[s].lazy[o]=0;
}
void insert(int s,int l,int r,int o)
{
	if(node[s].l>r||node[s].r<l)
		return;
	if(node[s].l>=l&&node[s].r<=r)
	{
		node[s].lazy[o]++;
		node[s].num_[o]+=node[s].a[o]*node[s].lazy[o];
		return ;
	}
	pushdown(s,o);
	int mid=(node[s].l+node[s].r)>>1;
	if(mid>=r)	insert(2*s,l,r,o);
	else if(mid<l)	insert(2*s+1,l,r,o);
	else{
		insert(2*s,l,mid,o);
		insert(2*s+1,mid+1,r,o);
	}
	node[s].num_[o]=node[2*s].num_[o]+node[2*s+1].num_[o];
}
xy work(int s)
{
	xy ans;
	ans.x=node[s].num_[1]-node[s].num_[3];
	ans.y=node[s].num_[4]-node[s].num_[2];
	return ans;
}
xy query(int s,int l,int r)
{
	xy ans;
	for(int i=1;i<=4;++i)
	{
		if(node[s].lazy[i])
		{
			pushdown(s,i);
		}
	}
	if(node[s].l>r||node[s].r<l)
		return ans;
	if(node[s].l==l&&node[s].r==r)
	{
		xy temp;
		temp=work(s);
		ans.x+=temp.x;
		ans.y+=temp.y;
		return ans;
	}
	int mid=(node[s].l+node[s].r)>>1;
	if(mid>=r)
	{
		xy a=query(2*s,l,r);
		ans.x+=a.x;
		ans.y+=a.y;
	}
	else if(mid<l)
	{
		xy a=query(2*s+1,l,r);
		ans.x+=a.x;
		ans.y+=a.y;
	}
	else{
		xy a;
		a=query(2*s,l,mid);
		ans.x+=a.x;
		ans.y+=a.y;
		a=query(2*s+1,mid+1,r);
		ans.x+=a.x;
		ans.y+=a.y;
	}
	return ans;
}
int main()
{
	int m;
	cin>>n>>m;
	scanf("%s",in);
	for(int i=0;i<n;++i)
	{
		for(int j=1;j<=4;++j)
		{
			num[j][i+1]+=num[j][i];
		}
		if(in[i]=='E')
		{
			num[1][i+1]++;
		}
		else if(in[i]=='S')
		{
			num[2][i+1]++;
		}
		else if(in[i]=='W')
		{
			num[3][i+1]++;
		}
		else if(in[i]=='N')
		{
			num[4][i+1]++;
		}
	}
	build(1,1,n);
//	test();
	int opt,l,r,t;
	char o[2];
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&l,&r);
			scanf("%s",o);
			int p;
			if(o[0]=='E')	p=1;
			else if(o[0]=='S')	p=2;
			else if(o[0]=='W')	p=3;
			else p=4;
			insert(1,l,r,p);
		}
		else if(opt==2)
		{
			xy ans;
			scanf("%d%d%d",&l,&r,&t);
			int times=t/(r-l+1);
			int where=t%(r-l+1);
			if(times==0)
			{
				xy a;
				a=query(1,l,where+l-1);
				ans.x+=a.x;
				ans.y+=a.y;
			}
			else if(times!=0)
			{
				xy a;
				a=query(1,l,r);
				ans.x+=a.x;
				ans.y+=a.y;
				ans.x*=times;
				ans.y*=times;
				if(where!=0)
				{
					a=query(1,l,where+l-1);
					ans.x+=a.x;
					ans.y+=a.y;
				}
			}
			printf("%d %d\n",ans.x,ans.y);
		}
	}
	return 0;
}
