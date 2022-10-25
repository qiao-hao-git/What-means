#include<stdio.h>
#include<string.h>
#define maxn 80

int main(){
	char s[maxn];
	int	k; 
	//int count=0;
	int res;
	scanf("%s",s);
	int n=strlen(s);
	for(k=n;k>=1;k--){
		int count=0;
		if(n%k==0){
			//count=1;
			for(int i=0;i<n-k;i++){
				if(s[i]==s[i+k]){
					count++;
					//break;
				}
			}
			if(count==n-k){
			res=k;
			}
		}
		else{
			continue;
		}
	}
	printf("%d\n",res);
	return 0;
}
