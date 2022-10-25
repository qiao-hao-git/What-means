#include <stdio.h>
#include <stdlib.h>
//����ʵ�ֶ���
#define MaxSize 1000
struct  QNode{
    int Data[MaxSize];
    int rear;
    int front;
};
typedef struct QNode *Queue;
//�����
void AddQ(Queue PtrQ,int item){
    if((PtrQ->rear+1)%MaxSize==PtrQ->front){
        printf("������");
        return;
    }
    PtrQ->rear=(PtrQ->rear+1)%MaxSize;
    PtrQ->Data[PtrQ->rear]=item;
}
//������
int DeleteQ(Queue PtrQ){
    if(PtrQ->front==PtrQ->rear){
        printf("���п�");
        return  ERROR;
    }
    else{
        PtrQ->front=(PtrQ->front+1)%MaxSize;
        return  PtrQ->Data[PtrQ->front];
    }
}
//����ʵ�ֶ���
struct Node{
    int Data;
    struct Node *next;
};
struct QNode{
    struct Node *front;
    struct Node *rear;
};
typedef struct QNode *Queue;
Queue *PtrQ;
//�����
//������
int DeleteQ(Queue PtrQ){
    struct Node *FrontCell;
    int FrontElem;
    if(PtrQ->front==NULL){
        printf("���п�");
        return ERROR;
    }
    FrontCell=PtrQ->front;
    if(PtrQ->front==PtrQ->rear){
        PtrQ->front=PtrQ->rear=NULL;
    }
    else{
        PtrQ->front=PtrQ->front->next;
    }
    FrontElem=FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
