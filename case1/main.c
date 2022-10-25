#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1010

struct  work{
    int work_time;
    int over_time;
}; //把每个任务的加工时间和完工时间进行封装
struct work task[maxn];

int cmp(const void*x,const void*y){
    return (*(struct work*)x).work_time>(*(struct work*)y).work_time?1:-1;
}
//cmp函数用来作为qsort函数中的升序函数
int main()
{
    int n,i,j,t,c_min=0;
    scanf("%d",&n);
    memset(task,0,sizeof(struct work));
    //srand((unsigned)time(0));//避免随机数重复
    for(i=0;i<n;i++){
        scanf("%d",&task[i].work_time);
        //task[i].work_time=rand()%100+1;//生成随机加工时间
    }
    qsort(task,n,sizeof(task[0]),cmp);//按加工时间从小到大对任务进行排序
    printf("pj   ");
    for(i=0;i<n;i++){
        printf("%5d ",task[i].work_time);
    }//输出排序后的任务的加工时间
    printf("\n");
    printf("cj   ");
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            task[i].over_time+=task[j].work_time;
        }
        printf("%5d ",task[i].over_time);
    }//计算并输出每个任务的完工时间
    printf("\n");
    for(i=0;i<n;i++){
        c_min+=task[i].over_time;
    }
    //Σcj为所有任务加工时间的和
    printf("Σcj ");
    printf("%5d",c_min);
    return 0;
}
