#include<stdio.h>

struct student{
	char name[21];
	int score;
};

int main(){
	struct student a[100],t;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	scanf("%s%d",a[i].name,&a[i].score);
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j].score<a[j+1].score){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%s\n",a[i].name);
	} 
	return 0;
}
