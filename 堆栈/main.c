#include <stdio.h>
#include <stdlib.h>
//����ʵ�ֶ�ջ
#define MaxSize 1000
typedef struct SNode *Stack;
struct SNode{
    int Data[MaxSize];
    int top;
};
//��ջ
void push(Stack PtrS,int item){
    if(Ptrs->top==MaxSize-1){
        printf("��ջ��");
        return;
    }
    else{
        PtrS->Data[++(PtrS->top)]=item;
        return;
    }
}
//��ջ
int pop(Stack PtrS){
    if(PtrS->top==-1){
        printf("��ջ��");
        return ERROR;
    }
    else{
        return  PtrS->Data[(Ptrs->top)--];
    }
}
//һ������ʵ��������ջ
struct DStack{
    int Data[MaxSize];
    int top1;
    int top2;
}S;
S.top1=-1;
S.top2=MaxSize;
//��ջ
void Push(struct DStack *PtrS,int item,int Tag){
    if(PtrS->top2-PtrS->top1==1){
        printf("��ջ��");
        return;
    }
    if(Tag==1){
        PtrS->Data[++(PtrS->top1)]==item;
    }
    else{
        PtrS->Data[--(PtrS->top2)]==item;
    }
}
//��ջ
int Pop(struct DStack *PtrS,int Tag){
    if(Tag==1){
        if(PtrS->top1==-1){
            printf("��ջ1��");
            return NULL;
        }
        else{
            return PtrS->Data[(PtrS->top1)--];
        }
    }
    else{
        if(PtrS->top2==MaxSize){
            printf("��ջ2��");
            return  NULL;
        }
        else{
            return  PtrS->Data[(PtrS->top2)++];
        }
    }
}
//����ʵ�ֶ�ջ
typedef struct SNode *Stack;
struct  SNode{
    int Data;
    struct SNode *next;
};
//����һ����ջ��ͷ���
Stack CreateStack(){
    Stack S;
    S=(Stack)malloc(sizeof(struct SNode));
    S->next==NULL;
    return S;
}
//�ж϶�ջ�Ƿ�Ϊ��
int IsEmpty(Stack S){
    return  (S->next==NULL);
}
//��ջ
void push(int item,Stack S){
    struct SNode *TemCell;
    TemCell=(Stack)malloc(sizeof(struct SNode));
    TemCell->data=item;
    TemCell->next=S->next;
    S->next=TemCell;
}
//��ջ
int pop(Stack S){
    struct SNode *FirstCell;
    int TopElem;
    if(IsEmpty(S)){
        printf("ջ��");
        return NULL;
    }
    else{
        FirstCell=S->next;
        S->next=FirstCell->next;
        TopElem=FirstCell->next->Data;
        free(FirstCell);
        return TopElem;
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
