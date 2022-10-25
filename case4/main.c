#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1010
struct  work{
    int work_time;
    int over_time;
};//��ÿ������ļӹ�ʱ�����깤ʱ����з�װ

struct  work    task[maxn];
int machine_worktime[maxn];//ÿ�������Ĺ���ʱ��

int cmp(const void*x,const void*y){
    return  (*(struct work*)x).work_time<(*(struct work*)y).work_time?1:-1;
}
//qsort�����Ľ���������
void quicksort(int arry[],int low,int high){
    if(low>high){
        return;
    }
    int i=low,j=high,temp=arry[i];//�������һ��Ԫ����Ϊ��׼��
    while(i<j){
        while(i<j&&arry[j]<temp){
            j--;
        }//���������ҵ���һ�����ڻ�׼����Ԫ��
        if(i<j){
            arry[i++]=arry[j];
        }//����Ԫ�طŵ����
        while(i<j&&arry[i]>temp){
            i++;
        }//���������ҵ���һ��С�ڻ�׼����Ԫ��
        if(i<j){
            arry[j--]=arry[i];
        }//����Ԫ�طŵ��ұ�
    }
    arry[i]=temp;//����׼�������������м�
    quicksort(arry,low,i-1);//�ݹ鴦���׼����ߵ�Ԫ��
    quicksort(arry,i+1,high);//�ݹ鴦���׼���ұߵ�Ԫ��
}//�����������������Ի����Ĺ���ʱ����н�������
int main()
{
    int m,n,i,C_max;
    memset(task,0,sizeof(struct work));//��ʼ���ṹ��
    scanf("%d%d",&m,&n);
    //srand((unsigned)time(0));//���������ظ��������
    for(i=0;i<n;i++){
        scanf("%d",&task[i].work_time);
        //task[i].work_time=rand()%100+1;//������ɼӹ�ʱ��
    }
    qsort(task,n,sizeof(task[0]),cmp);//�Լӹ�ʱ����н�������
    printf("pj   ");
    for(i=0;i<n;i++){
        printf("%5d ",task[i].work_time);
    }//��������ļӹ�ʱ��
    printf("\n");
    if(m>=n){
        for(i=0;i<n;i++){
            machine_worktime[i]=task[i].work_time;
        }
    }//�����������������������i��������ɵ�i�����񼴿�
    else{
        for(i=0;i<n;i++){
            machine_worktime[m-1]+=task[i].work_time;
            quicksort(machine_worktime,0,m-1);//��������֤ÿ��ѭ�������һ������Ϊ���ȿ��д����Ļ���
        }
    }//�������������������������Ҫʹ���ȿ��г����Ļ���ȥ���ʣ��������ʱ���������
    printf("mj   ");
    for(i=0;i<m;i++){
        printf("%5d ",machine_worktime[i]);
    }//���ÿ�������Ĺ���ʱ��
    printf("\n");
    C_max=machine_worktime[0];//C_max��Ϊ��������Ļ�������ʱ��
    printf("C_max");
    printf("%5d",C_max);
    return 0;
}
