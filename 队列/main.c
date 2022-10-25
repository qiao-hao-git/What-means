#include <stdio.h>
#include <stdlib.h>
//数组实现队列
#define MaxSize 1000
struct  QNode{
    int Data[MaxSize];
    int rear;
    int front;
};
typedef struct QNode *Queue;
//入队列
void AddQ(Queue PtrQ,int item){
    if((PtrQ->rear+1)%MaxSize==PtrQ->front){
        printf("队列满");
        return;
    }
    PtrQ->rear=(PtrQ->rear+1)%MaxSize;
    PtrQ->Data[PtrQ->rear]=item;
}
//出队列
int DeleteQ(Queue PtrQ){
    if(PtrQ->front==PtrQ->rear){
        printf("队列空");
        return  ERROR;
    }
    else{
        PtrQ->front=(PtrQ->front+1)%MaxSize;
        return  PtrQ->Data[PtrQ->front];
    }
}
//链表实现队列
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
//入队列
//出队列
int DeleteQ(Queue PtrQ){
    struct Node *FrontCell;
    int FrontElem;
    if(PtrQ->front==NULL){
        printf("队列空");
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
