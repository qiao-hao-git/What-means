#include<stdio.h>
#define maxn 1001
int a[maxn];


int main(){
	int n,t,count=0;
	scanf("%d",&n);
	for(int	i=0;i<n;i++){
		scanf("%d",&t);
		a[t]++;
	}
	for(int	i=1;i<maxn;i++){
		if(a[i]!=0){
			count++;
		}
	}
	printf("%d\n",count);
	for(int	i=1;i<maxn;i++){
		if(a[i]!=0){
			printf("%d ",i);
		}
	}
	return 0;
	 
} 
