#include<stdio.h>
#include<string.h>
#define maxn 1010
char s[maxn]; 

int main(){
	char	a[5][5]={{'T','R','G','S','J'},{'X','D','O','K','I'},{'M',' ','V','L','N'},{'W','P','A','B','E'},{'U','Q','H','C','F'}};
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]!='0'){
			int x,y;
			for(int i=0;i<5;i++){
				for(int j=0;i<5;j++){
					if(a[i][j]==' '){
						x=i;
						y=j;
					}
				}
			}
			if(s[i]=='A'){
				char t=a[x][y];
				a[x][y]=a[x-1][y];
				a[x-1][y]=t;
			}
			if(s[i]=='B'){
				char t=a[x][y];
				a[x][y]=a[x-1][y];
				a[x+1][y]=t;
			}
			if(s[i]=='L'){
				char t=a[x][y];
				a[x][y]=a[x-1][y];
				a[x][y-1]=t;
			}
			if(s[i]=='R'){
				char t=a[x][y];
				a[x][y]=a[x-1][y];
				a[x][y+1]=t;
			}
		}
		else{
			break;
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
