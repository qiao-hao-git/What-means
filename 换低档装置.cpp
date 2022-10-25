#include<stdio.h>
#define maxn 110
int a[maxn];
int b[maxn];

int main(){
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	if(n1>0&&n1<=100&&n2>0&&n2<=100){
		for(int i=0;i<n1;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n2;i++){
			scanf("%d",&b[i]);
		}
	}
	int i,j;
	int length1=0,length2=0;
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			if(a[i+j]+b[j]>3){
				break;
			}
		}
		if(j==n2){
			break;
		}
	}
	length1=((i+n2)>n1)?i+n2:n1;
	for(i=0;i<n2;i++){
		for(j=0;j<n1;j++){
			if(b[i+j]+a[j]>3){
				break;
			}
		}
		if(j==n1){
			break;
		}
	}
	length2=((i+n1)>n2)?i+n1:n2;
	printf("%d\n",(length1>length2)?length2:length1);
	
	return 0;
}
