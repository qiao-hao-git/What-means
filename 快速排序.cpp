#include<stdio.h>
int a[101],n;//定义全局变量，在子函数中使用 

void quicksort(int	left,int	right){
	int i,j,t,temp;
	if(left>right){
		return;
	}
	temp=a[left];	//temp中存的就是基准数 
	i=left;
	j=right;
	while(i!=j){
		while(a[j]>=temp&&i<j){
			j--;
		}	//顺序很重要，先要从右往左找 
		while(a[i]<=temp&&i<j){
			i++;
		}	//再从左往右找 
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}	//交换两个数在数组中的位置（i，j没有相遇） 
	}
	a[left]=a[i];
	a[i]=temp;	//最终将基准数归位 
	
	quicksort(left,i-1);	//继续处理左边的，递归 
	quicksort(i+1,right);	//继续处理右边的，递归 
	return;
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);	//快速排序调用 
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
