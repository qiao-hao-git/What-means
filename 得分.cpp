#include<stdio.h>
#define maxn 85

int main(){
	char s[maxn];
	scanf("%s",s);
	int sum=0; 
	for(int i=0;i<maxn;i++){
		int score=0;
		if(s[i]=='O'){
			int j=i;
			do{
				score++;
				j--;
			}while(s[j]!='X'&&j>=0);
			sum+=score; 
		}
		
	}
	printf("%d\n",sum);
	return 0;
}
