#include<stdio.h>
#define	maxn	100

struct	queue{
	int	data[maxn];
	int	head;
	int	tail;
}; 

int	main(){
	struct	queue	q;
	int	i;
	q.head=0;
	q.tail=0;
	for(int	i=0;i<9;i++){
		scanf("%d",&q.data[q.tail]);
		q.tail++;
	}
	while(q.head<q.tail){
		printf("%d ",q.data[q.head]);
		q.head++;
		q.data[q.tail]=q.data[q.head];
		q.tail++;
		q.head++;
		
	}
	return	0;
}
