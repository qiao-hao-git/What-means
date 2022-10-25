#include<stdio.h>
#define maxn 1001
int	a[maxn];

void	quicksort(int	left,int	right){
	int	temp,i,j,t;
	if(left>right){
		return;
	}
	temp=a[left];
	i=left;
	j=right;
	while(i!=j){
		while(a[j]>=temp&&i<j){
			j--;
		}
		while(a[i]<=temp&&i<j){
			i++;
		}
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=temp;
	quicksort(left,i-1);
	quicksort(i+1,right);
	return;
}

int	main(){
	int	n;
	scanf("%d",&n);
	for(int	i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);
	int	count=n;
	for(int	i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			count--;
		}
	}
	printf("%d\n",count);
	printf("%d ",a[0]);
	for(int	i=1;i<n;i++){
		if(a[i]!=a[i-1]){
			printf("%d ",a[i]);
		}
	}
	return	0;
}
