#include<stdio.h>
#include<string.h>
#define maxn 1010
char a[maxn][maxn];
char b[maxn];


int main(){
	int c[4];
	memset(c,0,sizeof(c));
	int m,n;
	scanf("%d%d",&m,&n);
	if(m>=4&&m<=50&&n>=4&&n<=1000){
		for(int i=0;i<m;i++){
			getchar();
			for(int j=0;j<n;j++){
				scanf("%c",&a[i][j]);
			}
		}
		for(int j=0;j<n;j++){
			for(int i=0;i<m;i++){
				if(a[i][j]=='A'){
					c[0]++;
				}
				else if(a[i][j]=='C'){
					c[1]++;
				}
				else if(a[i][j]=='G'){
					c[2]++;
				}
				else if(a[i][j]=='T'){
					c[3]++;
				}
				if(c[0]>=c[1]&&c[0]>=c[2]&&c[0]>=c[3]){
					b[j]='A';
				}
				else if(c[1]>c[0]&&c[1]>=c[2]&&c[1]>=c[3]){
					b[j]='C';
				}
				else if(c[2]>c[0]&&c[2]>c[1]&&c[2]>=c[3]){
					b[j]='G';
				}
				else if(c[3]>c[0]&&c[3]>c[1]&&c[3]>c[2]){
					b[j]='T';
				}
			}
			memset(c,0,sizeof(c));
		}
		printf("%s",b);
	}
	return 0;
}
