#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1010

struct  work{
    int work_time;
    int over_time;
}; //��ÿ������ļӹ�ʱ����깤ʱ����з�װ
struct work task[maxn];

int cmp(const void*x,const void*y){
    return (*(struct work*)x).work_time>(*(struct work*)y).work_time?1:-1;
}
//cmp����������Ϊqsort�����е�������
int main()
{
    int n,i,j,t,c_min=0;
    scanf("%d",&n);
    memset(task,0,sizeof(struct work));
    //srand((unsigned)time(0));//����������ظ�
    for(i=0;i<n;i++){
        scanf("%d",&task[i].work_time);
        //task[i].work_time=rand()%100+1;//��������ӹ�ʱ��
    }
    qsort(task,n,sizeof(task[0]),cmp);//���ӹ�ʱ���С����������������
    printf("pj   ");
    for(i=0;i<n;i++){
        printf("%5d ",task[i].work_time);
    }//�������������ļӹ�ʱ��
    printf("\n");
    printf("cj   ");
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            task[i].over_time+=task[j].work_time;
        }
        printf("%5d ",task[i].over_time);
    }//���㲢���ÿ��������깤ʱ��
    printf("\n");
    for(i=0;i<n;i++){
        c_min+=task[i].over_time;
    }
    //��cjΪ��������ӹ�ʱ��ĺ�
    printf("��cj ");
    printf("%5d",c_min);
    return 0;
}
