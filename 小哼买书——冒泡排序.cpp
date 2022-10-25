#include<stdio.h>
#define maxn 1001
int a[maxn];

int main(){
	int	n,t;
	scanf("%d",&n);
	for(int	i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int	i=0;i<n-1;i++){
		for(int	j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	int	count=n; 
	for(int	i=0;i<n;i++){
		if(a[i]==a[i+1]){
			count--;
		}
	}
	printf("%d\n",count);
	printf("%d ",a[0]);
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]){
			printf("%d ",a[i]);
		} 
	}
	return 0;
}
