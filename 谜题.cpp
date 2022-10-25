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
	int x=2,y=1;
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]!='0'){
		
			if(s[i]=='A'){
				char t=a[x][y];
				a[x][y]=a[x-1][y];
				a[x-1][y]=t;
				x--;
			}
			if(s[i]=='B'){
				char t=a[x][y];
				a[x][y]=a[x+1][y];
				a[x+1][y]=t;
				x++;
			}
			if(s[i]=='L'){
				char t=a[x][y];
				a[x][y]=a[x][y-1];
				a[x][y-1]=t;
				y--;
			}
			if(s[i]=='R'){
				char t=a[x][y];
				a[x][y]=a[x][y+1];
				a[x][y+1]=t;
				y++;
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
