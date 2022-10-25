#include<stdio.h>
int a[101],n;//����ȫ�ֱ��������Ӻ�����ʹ�� 

void quicksort(int	left,int	right){
	int i,j,t,temp;
	if(left>right){
		return;
	}
	temp=a[left];	//temp�д�ľ��ǻ�׼�� 
	i=left;
	j=right;
	while(i!=j){
		while(a[j]>=temp&&i<j){
			j--;
		}	//˳�����Ҫ����Ҫ���������� 
		while(a[i]<=temp&&i<j){
			i++;
		}	//�ٴ��������� 
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}	//�����������������е�λ�ã�i��jû�������� 
	}
	a[left]=a[i];
	a[i]=temp;	//���ս���׼����λ 
	
	quicksort(left,i-1);	//����������ߵģ��ݹ� 
	quicksort(i+1,right);	//���������ұߵģ��ݹ� 
	return;
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);	//����������� 
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
