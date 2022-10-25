#include<stdio.h>
#include<string.h>

const int mx=20;
char a[mx][mx];
int b[mx][mx];
int	c[mx][mx];

int main(){
	int r,s,ac=1;
	
	while(scanf("%d",&r)&&r!=0){
		int counts=1;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%d",&s);
		for(int i=0;i<r;i++){
			getchar();
			for(int j=0;j<s;j++){
				scanf("%c",&a[i][j]);
				if(((i==0)||(j==0)||(i>0&&a[i-1][j]=='*')||(j>0&&a[i][j-1]=='*'))&&a[i][j]!='*'){
					b[i][j]=counts;
					c[i][j]=counts;
					counts++;
				}
			}
		}
		printf("puzzle #%d:\nAcross\n",ac++);
		for(int i=0;i<r;i++){
			for(int j=0;j<s;j++){
				if(b[i][j]){
					printf("%3d.",b[i][j]);
					for(int k=j;k<s&&a[i][k]!='*';k++){
						printf("%c",a[i][k]);
						//if(b[i][k]!=0){
						//	b[i][k]=0;
					//	}
					}
					printf("\n");
				}
			}
		}
		printf("Down\n");
		for(int i=0;i<r;i++){
			for(int j=0;j<s;j++){
				if(c[i][j]){
					printf("%3d.",c[i][j]);
					for(int k=i;k<r&&a[k][j]!='*';k++){
						printf("%c",a[k][j]);
					//	if(c[k][j]!=0){
					//		c[k][j]=0;
					//	}
					}
					printf("\n");
				}
			}
		}
	}
	
	return 0;
} 
