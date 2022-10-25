#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1010
struct  work{
    int work_time;
    int over_time;
};//将每个任务的加工时间与完工时间进行封装

struct  work    task[maxn];
int machine_worktime[maxn];//每个机器的工作时间

int cmp(const void*x,const void*y){
    return  (*(struct work*)x).work_time<(*(struct work*)y).work_time?1:-1;
}
//qsort函数的降序排序函数
void quicksort(int arry[],int low,int high){
    if(low>high){
        return;
    }
    int i=low,j=high,temp=arry[i];//将数组第一个元素作为基准数
    while(i<j){
        while(i<j&&arry[j]<temp){
            j--;
        }//从右往左找到第一个大于基准数的元素
        if(i<j){
            arry[i++]=arry[j];
        }//将该元素放到左边
        while(i<j&&arry[i]>temp){
            i++;
        }//从左往右找到第一个小于基准数的元素
        if(i<j){
            arry[j--]=arry[i];
        }//将该元素放到右边
    }
    arry[i]=temp;//将基准数保存在数组中间
    quicksort(arry,low,i-1);//递归处理基准数左边的元素
    quicksort(arry,i+1,high);//递归处理基准数右边的元素
}//快速排序函数，用来对机器的工作时间进行降序排序
int main()
{
    int m,n,i,C_max;
    memset(task,0,sizeof(struct work));//初始化结构体
    scanf("%d%d",&m,&n);
    //srand((unsigned)time(0));//避免生成重复的随机数
    for(i=0;i<n;i++){
        scanf("%d",&task[i].work_time);
        //task[i].work_time=rand()%100+1;//随机生成加工时间
    }
    qsort(task,n,sizeof(task[0]),cmp);//对加工时间进行降序排序
    printf("pj   ");
    for(i=0;i<n;i++){
        printf("%5d ",task[i].work_time);
    }//输出排序后的加工时间
    printf("\n");
    if(m>=n){
        for(i=0;i<n;i++){
            machine_worktime[i]=task[i].work_time;
        }
    }//如果机器数多于任务数，第i个机器完成第i个任务即可
    else{
        for(i=0;i<n;i++){
            machine_worktime[m-1]+=task[i].work_time;
            quicksort(machine_worktime,0,m-1);//排序来保证每次循环后最后一个机器为最先空闲处来的机器
        }
    }//如果机器数少于任务数，则需要使最先空闲出来的机器去完成剩余任务中时间最长的任务
    printf("mj   ");
    for(i=0;i<m;i++){
        printf("%5d ",machine_worktime[i]);
    }//输出每个机器的工作时间
    printf("\n");
    C_max=machine_worktime[0];//C_max即为排序后最大的机器工作时间
    printf("C_max");
    printf("%5d",C_max);
    return 0;
}
