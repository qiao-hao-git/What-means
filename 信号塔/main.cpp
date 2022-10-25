#include <iostream>
using namespace std;
int main()
{
	int n,d;
	cin>>n>>d;
	int a[300004];
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int cnt=0,ans=0,k=n;
	while(k!=1)
	{
		cnt++;
		k--;
		if(a[k]==0&&cnt<d)	continue;
		if(a[k]==1&&cnt<=d){
			cnt=0;
			continue;
		}
		if(a[k]==0&&cnt==d)
		{
			ans++;
			cnt=0;
		}
	}
	printf("%d",ans);
	return 0;
}
