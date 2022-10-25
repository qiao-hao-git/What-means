#include<stdio.h>
#define maxn	10005

int main(){
	int b[10]={0};
	int n;
	scanf("%d",&n);
	int num;
	if(n<maxn&&n>0){
		
		for(int i=1;i<=n;i++){
			num=i;
			while(num>0){
				b[num%10]++;
				num/=10;
			}
		}
	}
	for(int i=0;i<=9;i++){
		printf("%d\n",b[i]);
	}
	return 0;
}

