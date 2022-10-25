#include<stdio.h>
#define maxn 1010

struct node{
	int w,h;
};
int b[maxn];

int main(){
	node a[6];
	int s[6];
	int count=0;
	for(int i=0;i<6;i++){
		scanf("%d%d",&a[i].w,&a[i].h);
		if(a[i].w==a[i].h){
			count++;
			s[i]=a[i].w;
		}
	}
	if(count==0){
		for(int i=1;i<=1000;i++){
			for(int j=0;j<6;j++){
				if(a[j].w==i||a[j].h==i){
					b[i]++;
				}
			}
		}
		int count1=0;
		for(int i=0;i<maxn;i++){
			if(b[i]==4){
				count1++;
			}
		}
		if(count1==3){
			printf("yes");
		}
		else{
			printf("no");
		}
	}
	else if(count==1){
		printf("no");
	}
	else if(count==2){
		for(int i=1;i<=1000;i++){
			for(int j=0;j<6;j++){
				if(a[j].w==i||a[j].h==i){
					b[i]++;
				}
				if(a[j].w==i&&a[j].h==i){
					b[i]++;
				}
			}
		}
		int count1=0,count2=0;
		for(int i=1;i<=1000;i++){
			if(b[i]==4){
				count1++;
			}
			if(b[i]==8){
				count2++;
			}
		}
		if(count1==1&&count2==1){
			printf("yes");
		}
		else{
			printf("no");
		}
	}
	else if(count==3){
		printf("no");
	}
	else if(count==4){
		printf("no");
	}
	else if(count==5){
		printf("no");
	}
	else if(count==6){
		if(a[0].w==a[0].h&&a[0].w==a[1].w&&a[0].w==a[1].h&&a[0].w==a[2].w&&a[0].w==a[2].h
		&&a[0].w==a[3].w&&a[0].w==a[3].h&&a[0].w==a[4].w&&a[0].w==a[4].h&&a[0].w==a[5].w&&a[0].w==a[5].h){
			printf("yes");
		}
		else{
			printf("no");
		}
	}
	return 0;
}
