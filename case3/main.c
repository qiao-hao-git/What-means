#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1010
struct  work{
    int work_time;
    int end_time;
    int over_time;
    int delay_time;
};
struct work task[maxn];

int cmp(const void*a,const void*b){
    int d1=((struct work*)a)->end_time;
    int d2=((struct work*)b)->end_time;
    return  d1>d2;
}

int main()
{
    int n,i,j,L_max=0;
    scanf("%d",&n);
    memset(task,0,sizeof(struct    work));
    for(i=0;i<n;i++){
        scanf("%d%d",&task[i].work_time,&task[i].end_time);
    }
    qsort(task,n,sizeof(struct work),cmp);
    printf("cj   ");
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            task[i].over_time+=task[j].work_time;
        }
        printf("%5d ",task[i].over_time);
        task[i].delay_time=task[i].over_time-task[i].end_time;
    }
    printf("\n");
    printf("Lj   ");
    for(i=0;i<n;i++){
        printf("%5d ",task[i].delay_time);
    }
    printf("\n");
    for(i=0;i<n;i++){
        if(task[i].delay_time>L_max){
            L_max=task[i].delay_time;
        }
    }
    printf("L_max");
    printf("%5d",L_max);
    return 0;
}
