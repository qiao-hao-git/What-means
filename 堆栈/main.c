#include <stdio.h>
#include <stdlib.h>
//数组实现堆栈
#define MaxSize 1000
typedef struct SNode *Stack;
struct SNode{
    int Data[MaxSize];
    int top;
};
//入栈
void push(Stack PtrS,int item){
    if(Ptrs->top==MaxSize-1){
        printf("堆栈满");
        return;
    }
    else{
        PtrS->Data[++(PtrS->top)]=item;
        return;
    }
}
//出栈
int pop(Stack PtrS){
    if(PtrS->top==-1){
        printf("堆栈空");
        return ERROR;
    }
    else{
        return  PtrS->Data[(Ptrs->top)--];
    }
}
//一个数组实现两个堆栈
struct DStack{
    int Data[MaxSize];
    int top1;
    int top2;
}S;
S.top1=-1;
S.top2=MaxSize;
//入栈
void Push(struct DStack *PtrS,int item,int Tag){
    if(PtrS->top2-PtrS->top1==1){
        printf("堆栈满");
        return;
    }
    if(Tag==1){
        PtrS->Data[++(PtrS->top1)]==item;
    }
    else{
        PtrS->Data[--(PtrS->top2)]==item;
    }
}
//出栈
int Pop(struct DStack *PtrS,int Tag){
    if(Tag==1){
        if(PtrS->top1==-1){
            printf("堆栈1空");
            return NULL;
        }
        else{
            return PtrS->Data[(PtrS->top1)--];
        }
    }
    else{
        if(PtrS->top2==MaxSize){
            printf("堆栈2空");
            return  NULL;
        }
        else{
            return  PtrS->Data[(PtrS->top2)++];
        }
    }
}
//链表实现堆栈
typedef struct SNode *Stack;
struct  SNode{
    int Data;
    struct SNode *next;
};
//构建一个堆栈的头结点
Stack CreateStack(){
    Stack S;
    S=(Stack)malloc(sizeof(struct SNode));
    S->next==NULL;
    return S;
}
//判断堆栈是否为空
int IsEmpty(Stack S){
    return  (S->next==NULL);
}
//入栈
void push(int item,Stack S){
    struct SNode *TemCell;
    TemCell=(Stack)malloc(sizeof(struct SNode));
    TemCell->data=item;
    TemCell->next=S->next;
    S->next=TemCell;
}
//出栈
int pop(Stack S){
    struct SNode *FirstCell;
    int TopElem;
    if(IsEmpty(S)){
        printf("栈空");
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
