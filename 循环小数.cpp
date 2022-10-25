#include<stdio.h>
#include<string.h>
#define max 10010
#define maxn 3000
char c[max];

int find(char*c,int n){
	if(n>1){
		for(int i=0;i<n-1;i++){
			if(c[n]==c[i]){
				return 0;
			}
			else{
				return 1;
			}
		}
	}
}

int main(){
	int a,b;
	int count=0;
	scanf("%d",&a);
	scanf("%d",&b);
	if(a>=0&&a<=maxn&&b>=0&&b<=maxn){
		int d;
		do{
			d=a*10;
		}while(d/b<0);
		c[0]=d/b;
		//count++;
		int t=1;
		do{
			int e=d%b;
			d=e*10;
			count++;
			c[count]=d/b;
			
			t=find(c,count);
		}while(t);
	}
	int n=sizeof(c);
	int m=0;
	printf("0.");
	for(int i=0;i<n;i++){
		if(c[i]!=0){
			m++;
		}
	}
	for(int i=0;i<m-1;i++){
		printf("%d",c[i]);
	}
	printf("\n");
	printf("%d",m-1);
	return 0;
}
