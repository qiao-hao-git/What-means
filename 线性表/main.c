#include <stdio.h>
#include <stdlib.h>
typedef struct  LNode *List;
struct  LNode{
    int Data[1000];
    int Last;
};
struct  LNode L;
List PtrL;
//建表
List MakeEmpty(){
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return  PtrL;
}
//查找值
int Find(int X,List PtrL){
    int i=0;
    while(i<=PtrL->Last&&PtrL->Data[i]!=X){
        i++;
    }
    if(i>PtrL->Last){
        return -1;
    }
    else{
        return  i;
    }
}
//插入值
void Insert(int X,int i,List PrrL){
    int j;
    if(PtrL->Last == MAXSIZE - 1){
        printf("表满");
        return;
    }
    if( i < 1 || i > PtrL->Last+2){
        printf("位置不合法")
        return;
    }
    for(j=PtrL->Last;j>=i-1;j--){
        PtrL->Data[j+1]=PtrL->Data[j];
    }
    PtrL->Data[i]=X;
    PtrL->Last++;
    return;
}
//删除值
void Delete(int i,List PtrL){
    int j;
    if(i<1||i>PtrL->Last+1){
        printf("不存在该位置的元素");
        return;
    }
    for(j=i;j<=PtrL->Last;j++){
        PtrL->Data[j-1]=PtrL->Data[j];
    }
    PtrL->Last--;
    return;
}




typedef struct  LNode *List;
struct  LNode{
    int Data;
    List Next;
};
struct  LNode L;
List PtrL;
//求链表长度
int Length(List PtrL){
    List p=PtrL;
    int j=0;
    while(p){
        p=p->Next;
        j++;
    }
    return j;
}
//按序号查找值
List FindKth(int K,List PtrL){
    List p=PtrL;
    int i=1;
    while(p!=NULL&&i<K){
        p=p->Next;
        i++;
    }
    if(i==K){
        return  p;
    }
    else{
        return NULL;
    }
}
//按值查找
List Find(int X,List PtrL){
    List p=PtrL;
    while(p!=NULL&&p->Data!=X){
        p=p->Next;
    }
    return p;
}
//插入
List Insert(int X,int i,List PtrL){
    list p,s;
    if(i==1){
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=PtrL;
        return  s;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("参数错误");
        return  NULL;
    }
    else{
        s=(List)malloc(sizeof(struct LNode));
        s->Next=p->Next;
        p->Next=s;
        return PtrL;
    }
}
//删除
List Delete(int i,List PtrL){
    List p,s;
    if(i==1){
        s=PtrL;
        if(PtrL!=NULL){
            PtrL->PtrL->Next;
        }
        else{
            return  NULL;
        }
        free(s);
        return  PtrL;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("错误");
        return NULL;
    }
    else if(p->Next==NULL){
        printf("错误");
        return NULL;
    }
    else{
        s=p->Next;
        p->Next=s->Next;
        free(s);
        return PtrL;
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
