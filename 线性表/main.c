#include <stdio.h>
#include <stdlib.h>
typedef struct  LNode *List;
struct  LNode{
    int Data[1000];
    int Last;
};
struct  LNode L;
List PtrL;
//����
List MakeEmpty(){
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return  PtrL;
}
//����ֵ
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
//����ֵ
void Insert(int X,int i,List PrrL){
    int j;
    if(PtrL->Last == MAXSIZE - 1){
        printf("����");
        return;
    }
    if( i < 1 || i > PtrL->Last+2){
        printf("λ�ò��Ϸ�")
        return;
    }
    for(j=PtrL->Last;j>=i-1;j--){
        PtrL->Data[j+1]=PtrL->Data[j];
    }
    PtrL->Data[i]=X;
    PtrL->Last++;
    return;
}
//ɾ��ֵ
void Delete(int i,List PtrL){
    int j;
    if(i<1||i>PtrL->Last+1){
        printf("�����ڸ�λ�õ�Ԫ��");
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
//��������
int Length(List PtrL){
    List p=PtrL;
    int j=0;
    while(p){
        p=p->Next;
        j++;
    }
    return j;
}
//����Ų���ֵ
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
//��ֵ����
List Find(int X,List PtrL){
    List p=PtrL;
    while(p!=NULL&&p->Data!=X){
        p=p->Next;
    }
    return p;
}
//����
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
        printf("��������");
        return  NULL;
    }
    else{
        s=(List)malloc(sizeof(struct LNode));
        s->Next=p->Next;
        p->Next=s;
        return PtrL;
    }
}
//ɾ��
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
        printf("����");
        return NULL;
    }
    else if(p->Next==NULL){
        printf("����");
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
