#include<stdio.h>
#include<string.h>

#define maxn 1010
char s[maxn];
char t[maxn];

int main(){
	scanf("%s",s);
		while(scanf("%s",t)==1){
		int count=0,num=0;
		int n=strlen(s);
		int m=strlen(t);
		for(int i=0;i<m-1;i++){
			for(int j=0;j<n;j++){
				if(s[j]==t[i]){
					count=1;
					for(int k=j;k<n;k++){
						if(s[k]==t[i+1]){
							count=2;
							break;
						}
					}
					//count++;
				}
				if(count==2){
					count=0;
					num++;
					break;
				}
			}
		}
		for(int j=0;j<n;j++){
			if(s[j]==t[m-2]){
				for(int k=j;k<n;k++){
					if(s[k]==t[m-1]){
						num++;
					}
				}
			}
		}
		if(num==m){
			printf("yes");
		}
		else{
			printf("no");
		}
	}
	return 0;
}
