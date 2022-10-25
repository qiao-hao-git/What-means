#include<stdio.h>
#include<stdlib.h>
#define maxn	1001
int book[maxn];

int main(){
	int n,t;
	scanf("%d",&n);
	for(int i=0;i<maxn;i++){
		book[i]=0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		book[t]++;
	}
	for(int i=maxn-1;i>=0;i--){
		if(book[i]!=0){
			printf("%d\n",i);
		}
	}
	system("pause");
	return 0;
} 
