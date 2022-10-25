#include<stdio.h>
#include<string.h>
#define maxn 1010
char s[maxn];

int main(){
	scanf("%s",s);
	float m1=0,m2=0,m3=0,m4=0,m5=0;
	float	m;
	int n=strlen(s);
	for(int i=0;i<n-1;i++){
		if(s[i]=='C'){
			if(s[i+1]>='2'&&s[i+1]<='9'){
				m1=(float)(12.01*(s[i+1]-48));
			}
			else{
				m1=12.01;	
			}
		}
		if(s[i]=='H'){
			if(s[i+1]>='2'&&s[i+1]<='9'){
				m2=(float)(1.008*(s[i+1]-48));
			}
			else{
				m2=1.008;	
			}
		}
		if(s[i]=='O'){
			if(s[i+1]>='2'&&s[i+1]<='9'){
				m3=(float)(16.00*(s[i+1]-48));
			}
			else{
				m3=16.00;;	
			}
		}
		if(s[i]=='N'){
			if(s[i+1]>='2'&&s[i+1]<='9'){
				m4=(float)(14.01*(s[i+1]-48));
			}
			else{
				m4=14.01;	
			}
		}
	}
	if(s[n-1]=='C'){
		m5=12.01;
	}
	else if(s[n-1]=='O'){
		m5=16.00;
	}
	else if(s[n-1]=='H'){
		m5=1.008;
	}
	else{
		m5=14.01;
	}
	m=m1+m2+m3+m4+m5;
	printf("%fg/mol",m);
	return 0;
}
